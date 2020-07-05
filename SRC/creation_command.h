//
// Created by y on 7/5/20.
//

#ifndef DNA_CREATION_COMMAND_H
#define DNA_CREATION_COMMAND_H

#include "ICMD.h"

class CreationCMD: public ICMD{
    /*virtual*/ void run() =0;
};

#endif //DNA_CREATION_COMMAND_H
