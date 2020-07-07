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
    std::map<IdDna,DnaMetaData*>& getIdStructure(){return m_idStructure;}
    const std::map<NameDna, DnaMetaData*>& getNameStructure(){return m_nameStructure;}

private:
    std::map<IdDna,DnaMetaData*> m_idStructure;
    std::map<NameDna, DnaMetaData*> m_nameStructure;
};

#endif //DNA_STRUCTURE_DNA_H
