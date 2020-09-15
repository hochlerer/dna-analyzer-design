//
// Created by y on 7/5/20.
//

#ifndef DNA_STRUCTURE_DNA_H
#define DNA_STRUCTURE_DNA_H

#include "meta_data_dna.h"
#include <map>

class StructureDna{
public:
    void addDna(DnaMetaData* dna);
    void erase(size_t id, std::string name);
    DnaMetaData& findDna(std::string name) ;
    DnaMetaData& findDna(size_t id) ;
    bool isExistDna(std::string name)const ;
    bool isExistDna(size_t id)const ;

private:
    std::map<size_t, DnaMetaData*> m_idStructure;
    std::map<std::string, DnaMetaData*> m_nameStructure;
};

#endif //DNA_STRUCTURE_DNA_H
