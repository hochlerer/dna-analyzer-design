//
// Created by y on 7/5/20.
//

#include "name_dna.h"
#include <cstring>

bool operator<(const NameDna& name1, const NameDna& name2){
    return strcmp(name1.getNameDna().c_str(), name2.getNameDna().c_str());
}