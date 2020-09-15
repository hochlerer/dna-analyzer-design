//
// Created by y on 6/30/20.
//

#ifndef DNA_SCREEN_WRITER_H
#define DNA_SCREEN_WRITER_H

#include "IWriter.h"

class ScreenWriter: public IWriter{
public:
    /*virtual*/ void write(const char* str) const;

};

#endif //DNA_SCREEN_WRITER_H
