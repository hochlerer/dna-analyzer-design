//
// Created by y on 7/5/20.
//

#ifndef DNA_ID_DNA_H
#define DNA_ID_DNA_H

#include <cstdio>

class IdDna{
public:
    IdDna(size_t id = 0):m_id(id){}
    size_t getId()const {return m_id;}
    const IdDna operator++();
private:
    size_t m_id;
};

#endif //DNA_ID_DNA_H
