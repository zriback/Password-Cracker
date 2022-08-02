#include "PassCracker.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

void PassCracker::setType(const char *type){
    strncpy(this->type, type, sizeof(this->type));
}


