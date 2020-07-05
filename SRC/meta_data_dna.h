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

private:
    NameDna m_nameDna;
    IdDna m_idDna;
    StatusDna n_statusDna;
    DnaSequence* m_dna;
};

#endif //DNA_META_DATA_DNA_H
