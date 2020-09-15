//
// Created by y on 7/5/20.
//

#include "structure_dna.h"

void StructureDna::addDna(DnaMetaData* dna) {
    m_idStructure.insert(std::pair<size_t, DnaMetaData*> (dna->getId(), dna));
    m_nameStructure.insert(std::pair<std::string,DnaMetaData*> (dna->getName(), dna));
}

void StructureDna::erase(size_t id, std::string name) {
    m_idStructure.erase(id);
    m_nameStructure.erase(name);
}

DnaMetaData& StructureDna::findDna(std::string name) {

    return *(m_nameStructure.find(name)->second);
}

DnaMetaData &StructureDna::findDna(size_t id) {

    return *(m_idStructure.find(id)->second);
}

bool StructureDna::isExistDna(std::string name) const {

    return m_nameStructure.find(name) != m_nameStructure.end();
}

bool StructureDna::isExistDna(size_t id) const {

    return m_idStructure.find(id) != m_idStructure.end();
}

