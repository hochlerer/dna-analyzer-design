//
// Created by y on 9/15/20.
//

#ifndef DNA_UI_H
#define DNA_UI_H

#include "IReader.h"
#include "IWriter.h"

class StructureDna;

class UI{
public:
    virtual void start(IReader& input, IWriter& output, StructureDna& dnaStructure) = 0;
};

#endif //DNA_UI_H
