//
// Created by y on 6/30/20.
//

#ifndef DNA_IWRITER_H
#define DNA_IWRITER_H

class IWriter{
public:
    virtual void write(const char* str) const= 0;
};

#endif //DNA_IWRITER_H
