//
// Created by y on 7/8/20.
//

#ifndef DNA_MANAGEMENT_COMMAND_H
#define DNA_MANAGEMENT_COMMAND_H

#include "ICMD.h"

class ManagementCmd: public ICMD{
public:
    /*virtual*/ ~ManagementCmd() {};
    /*virtual*/ void createCMD(const Parser& params) = 0;
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure , IReader& input, IWriter& output) =0;

private:
};

#endif //DNA_MANAGEMENT_COMMAND_H
