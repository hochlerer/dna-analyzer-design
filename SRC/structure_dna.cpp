//
// Created by y on 7/5/20.
//

#include "structure_dna.h"

void StructureDna::addDna(DnaMetaData* dna) {
    m_idStructure.insert(std::pair<IdDna, DnaMetaData*> (dna->getId(), dna));
    m_nameStructure.insert(std::pair<NameDna,DnaMetaData*> (dna->getName(), dna));
}
