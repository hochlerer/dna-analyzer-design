//
// Created by y on 7/5/20.
//

#ifndef DNA_CREATION_COMMAND_H
#define DNA_CREATION_COMMAND_H

#include "ICMD.h"

class CreationCmd: public ICMD{
public:
    /*virtual*/ void run(const Parser& params) =0;
    /*virtual*/ std::string printAfterCommand()const =0;

protected:
    static size_t s_countDna;
};

#endif //DNA_CREATION_COMMAND_H
