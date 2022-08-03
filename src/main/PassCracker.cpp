#include "PassCracker.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include "hashes.h"



void PassCracker::setType(const char *type){
    strncpy(this->type, type, sizeof(this->type));
}

void PassCracker::setGoal(const char *goal){
    strncpy(this->goal, goal, sizeof(this->goal));
}

std::string PassCracker::calculateHash(char * type, char *msg){

    //TODO make the type actually do something
    int msg_len = strlen(msg);
    unsigned char* digest = nullptr;
    unsigned int len = 0;

    hash_md5((const unsigned char *)msg, msg_len, &digest, &len);

    std::string hash;
    std::stringstream ss;

    // convert to a string
    for (unsigned int i = 0; i < len; i++){
        ss << std::hex << (int)digest[i];
    }   
    hash = ss.str();
    OPENSSL_free(digest);

    return hash;
}


