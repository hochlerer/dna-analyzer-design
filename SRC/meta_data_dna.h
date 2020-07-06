//
// Created by y on 7/5/20.
//

#ifndef DNA_META_DATA_DNA_H
#define DNA_META_DATA_DNA_H
#include "dna_sequence.h"
#include "name_dna.h"
#include "id_dna.h"
#include "status_dna.h"

class DnaMetaData{
public:
    DnaMetaData(const DnaSequence& dnaSeq, const NameDna& name, const StatusDna& status): m_dna(new DnaSequence(dnaSeq)), m_nameDna(name), m_statusDna(status) {++m_idDna;}
    static IdDna getId() {return m_idDna;}
    NameDna getName()const {return m_nameDna;}
    StatusDna getStatus()const {return m_statusDna;}
    const DnaSequence* getDnaSeq()const {return m_dna;}

private:
    DnaSequence* m_dna;
    NameDna m_nameDna;
    StatusDna m_statusDna;
    static IdDna m_idDna;
};

#endif //DNA_META_DATA_DNA_H
