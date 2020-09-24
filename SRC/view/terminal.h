//
// Created by y on 7/7/20.
//

#ifndef DNA_TERMINAL_H
#define DNA_TERMINAL_H

#include "UI.h"
class System;


class Terminal: public UI{
public:
    Terminal(IReader& input, IWriter& output): UI(input, output){}
    /*virtual*/ void start(Callback<System> &callback, IReader &input, IWriter &output, StructureDna &dnaStructure);
    void write(const std::string& output) const;
    const std::string& read() const;
};

#endif //DNA_TERMINAL_H
