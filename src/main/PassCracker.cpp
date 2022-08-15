#include "PassCracker.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "hashes.h"



void PassCracker::setType(const char *type){
    strncpy(this->type, type, sizeof(this->type));
}

void PassCracker::setGoal(const char *goal){
    strncpy(this->goal, goal, sizeof(this->goal));
}

/*
Returns the password that matches the hash if it exists in the worldlist
Else returns NULL
*/
std::string PassCracker::crackHash(char *wordlist){
    bool cracked = false;
    std::ifstream file(wordlist);
    std::string line;
    std::string hash;

    while (!cracked){
        std::getline(file, line);
        if(!file.eof()){  // if the EOF has not been reached
            // std::cout << "Trying: " << line << "\n";
            hash = calculateHash(line.c_str());
            // std::cout << "Hash is " << hash << "\n";
            if (strcmp(hash.c_str(), this->goal) == 0){
                cracked = true;
            }
        }
        else{
            break;
        }
        
    }
    file.close();
    if (!cracked){  // then we broke from reaching the EOF
        return NULL;
    }
    else{
        return line;
    }
}

std::string PassCracker::calculateHash(const char *msg){
    int msg_len = strlen(msg);
    unsigned char* digest = nullptr;
    unsigned int len = 0;

    hash_md5(this->type, (const unsigned char *)msg, msg_len, &digest, &len);

    std::string hash;
    std::stringstream ss;

    // convert to a string
    for (unsigned int i = 0; i < len; i++){
        ss << std::hex << std::setfill('0') << std::setw(2) << (int)digest[i];
    }   
    hash = ss.str();
    OPENSSL_free(digest);

    return hash;
}


