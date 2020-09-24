//
// Created by y on 9/22/20.
//

#ifndef DNA_ENTER_CMD_H
#define DNA_ENTER_CMD_H

#include "ICMD.h"


class EnterCmd: public ICMD{
public:
    /*virtual*/ ~EnterCmd() {}
    /*virtual*/ void createCMD(const Parser& params) ;
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure , IReader& input, IWriter& output);

private:
};
#endif //DNA_ENTER_CMD_H
