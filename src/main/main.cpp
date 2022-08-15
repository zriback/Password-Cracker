#include <stdio.h>
#include <iostream>
#include <cstring>
#include "PassCracker.h"
#include "hashes.h"

#include <iomanip>
#include <sstream>


int main(int argc, char **argv){

    char type[16];
    char goal[1024];
    char wordlist[64];

    if (argc == 4){
        strncpy(type, argv[1], sizeof(type));
        strncpy(goal, argv[2], sizeof(goal));
        strncpy(wordlist, argv[3], sizeof(wordlist));
    }
    else{
        std::cout << "Incorrect command line usage. Correct ussage is\n";
        std::cout << ".\\cracker.exe [hash method] [hash] [wordlist]\n";
        exit(1);
    }

    PassCracker *pc = new PassCracker();
    pc->setType(type);
    pc->setGoal(goal);

    std::string password;
    try {
        password = pc->crackHash(wordlist); 
        std::cout << "Found it!\n" << password << "\n";
    }
    catch (std::logic_error const&){
        std::cout << "Password not found\n";
    }
    return 0;
}


