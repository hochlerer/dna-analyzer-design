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
    DnaMetaData& findDna(NameDna name) ;
    DnaMetaData& findDna(IdDna id) ;
    bool isExistDna(NameDna name)const ;
    bool isExistDna(IdDna id)const ;

private:
    std::map<IdDna,DnaMetaData*> m_idStructure;
    std::map<NameDna, DnaMetaData*> m_nameStructure;
};

#endif //DNA_STRUCTURE_DNA_H
