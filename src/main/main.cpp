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

    if (argc == 3){
        strncpy(type, argv[1], sizeof(type));
        strncpy(goal, argv[2], sizeof(goal));
    }
    else{
        std::cout << "Incorrect command line usage. Correct ussage is\n";
        std::cout << ".\\cracker.exe [hash method] [goal]\n";
    }

    PassCracker *pc = new PassCracker();
    pc->setType(type);
    pc->setGoal(goal);

    std::string hash;

    char msg[256];
    strncpy(msg, "supertime", sizeof(msg));

    hash = pc->calculateHash(msg);

    std::cout << hash << "\n";

    return 0;
}


