//
// Created by y on 7/8/20.
//

#ifndef DNA_MANAGEMENT_COMMAND_H
#define DNA_MANAGEMENT_COMMAND_H
#include "ICMD.h"

class ManagementCmd: public ICMD{
public:
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IWriter& output) =0;

private:
};

#endif //DNA_MANAGEMENT_COMMAND_H
