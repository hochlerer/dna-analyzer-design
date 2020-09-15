//
// Created by y on 7/5/20.
//

#ifndef DNA_ICMD_H
#define DNA_ICMD_H

#include <string>

#include "parser.h"
#include "../model/structure_dna.h"
#include "../view/IWriter.h"

class ICMD{
public:
    virtual ~ICMD() = 0;
    virtual void createCMD(const Parser& params) = 0;
    virtual void run(const Parser& params, StructureDna& dnaStructure ,IReader& input ,IWriter& output) = 0;

private:
};

#endif //DNA_ICMD_H
