//
// Created by y on 7/8/20.
//
#include "auxiliary_functions.h"
#include <sstream>

std::string numTostring(size_t num){
    std::stringstream str;
    str<< num;
    return str.str();
}

size_t stringToNum(std::string str){
    std::istringstream st(str);
    size_t num;
    st>> num;
    return num;
}