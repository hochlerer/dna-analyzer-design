//
// Created by y on 7/5/20.
//

#include "id_dna.h"

const IdDna IdDna::operator++(){
    m_id += 1;
    return *this;
}