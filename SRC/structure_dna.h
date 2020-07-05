//
// Created by y on 7/5/20.
//

#ifndef DNA_STRUCTURE_DNA_H
#define DNA_STRUCTURE_DNA_H

#include "meta_data_dna.h"
#include <map>

class StructureDna{
public:
    static std::map<IdDna,DnaMetaData*>& getIdStructure();
    static std::map<NameDna, IdDna>& getNameStructure();
};

#endif //DNA_STRUCTURE_DNA_H
