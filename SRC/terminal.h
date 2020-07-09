//
// Created by y on 7/7/20.
//

#ifndef DNA_TERMINAL_H
#define DNA_TERMINAL_H
#include "IReader.h"
#include "IWriter.h"
#include "structure_dna.h"

class Terminal{
public:
    void start(IReader& input, IWriter& output, StructureDna& dnaStructure);
};

#endif //DNA_TERMINAL_H
