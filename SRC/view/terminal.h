//
// Created by y on 7/7/20.
//

#ifndef DNA_TERMINAL_H
#define DNA_TERMINAL_H
#include "UI.h"
class System;


class Terminal: public UI{
public:
    /*virtual*/ void start(Callback<System> &callback, IReader &input, IWriter &output, StructureDna &dnaStructure);
};

#endif //DNA_TERMINAL_H
