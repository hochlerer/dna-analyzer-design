//
// Created by y on 7/5/20.
//

#include "meta_data_dna.h"

size_t DnaMetaData::s_lastId = 1;

DnaMetaData::~DnaMetaData() {
    delete m_dna;
    m_dna = NULL;
}

DnaMetaData::DnaMetaData(const DnaMetaData &other) {
    m_idDna = other.m_idDna;
    m_dna = new DnaSequence(*(other.m_dna));
    m_statusDna = other.m_statusDna;
    m_nameDna = other.m_nameDna;
    m_counter = 0;
}

void DnaMetaData::setName(std::string newName) {
    m_nameDna = newName;
}
