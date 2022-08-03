#ifndef PASS_CRACKER_HEADER
#define PASS_CRACKER_HEADER

#include <stdio.h>
#include <iostream>
#include <cstring>

class PassCracker{
    // Stores the type of hash this is to compute (for example, SHA1, SHA256, or MD5, etc.)
    char type[16];
    char goal[1024];

  public:
    void setType(const char *type);

    void setGoal(const char *goal);

    std::string calculateHash(char * type, char *msg);
};




#endif