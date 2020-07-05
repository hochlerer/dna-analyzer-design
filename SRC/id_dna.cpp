//
// Created by y on 7/5/20.
//

#include "id_dna.h"

const IdDna IdDna::operator++(){
    m_id += 1;
    return *this;
}

bool operator<(const IdDna& id1,const IdDna& id2){
    return (id1.getId() < id2.getId());
}