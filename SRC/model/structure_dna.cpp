//
// Created by y on 7/5/20.
//

#include "structure_dna.h"

void StructureDna::addDna(DnaMetaData* dna) {
    m_idStructure.insert(std::pair<IdDna, DnaMetaData*> (dna->getId(), dna));
    m_nameStructure.insert(std::pair<NameDna,DnaMetaData*> (dna->getName(), dna));
}

bool StructureDna::isExistDna(NameDna name) const {
    return m_nameStructure.find(name) != m_nameStructure.end();
}

bool StructureDna::isExistDna(IdDna id) const {
    return m_idStructure.find(id) != m_idStructure.end();
}

DnaMetaData& StructureDna::findDna(NameDna name) {
    return *(m_nameStructure.find(name)->second);
}

DnaMetaData &StructureDna::findDna(IdDna id) {
    return *(m_idStructure.find(id)->second);
}

