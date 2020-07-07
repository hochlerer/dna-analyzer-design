//
// Created by y on 7/5/20.
//

#ifndef DNA_ICMD_H
#define DNA_ICMD_H
#include "parser.h"
#include <string>
#include "structure_dna.h"
#include "IWriter.h"

class ICMD{
public:
    virtual void run(const Parser& params, StructureDna& dnaStructure ,IWriter& output) = 0;

private:
};

#endif //DNA_ICMD_H
