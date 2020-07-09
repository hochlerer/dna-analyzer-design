//
// Created by y on 7/5/20.
//

#ifndef DNA_CREATION_COMMAND_H
#define DNA_CREATION_COMMAND_H

#include "ICMD.h"

class CreationCmd: public ICMD{
public:
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IWriter& output) =0;

};

#endif //DNA_CREATION_COMMAND_H
