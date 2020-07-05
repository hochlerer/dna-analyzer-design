//
// Created by y on 7/5/20.
//

#ifndef DNA_STRUCTURE_DNA_H
#define DNA_STRUCTURE_DNA_H

#include "meta_data_dna.h"
#include <map>

class StructureDna{
public:
private:
    static std::map<IdDna,DnaMetaData> m_idStructure;
    static std::map<NameDna,DnaMetaData*> m_nameStructure;
    static std::map<StatusDna,DnaMetaData*> m_statusStructure;
};

#endif //DNA_STRUCTURE_DNA_H
