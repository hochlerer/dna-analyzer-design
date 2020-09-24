//
// Created by y on 9/15/20.
//

#ifndef DNA_UI_H
#define DNA_UI_H

#include <string>
#include "../controller/callback.h"

class IReader;
class IWriter;
class System;
class StructureDna;


class UI{
public:
    UI(IReader& input, IWriter& output) : m_input(input), m_output(output){}
    virtual void start(Callback<System> &callback, IReader& input, IWriter& output, StructureDna& dnaStructure) = 0;
    virtual void write(const std::string& output) const = 0;
    virtual const std::string& read() const = 0;

protected:
    IReader& m_input;
    IWriter& m_output;
};

#endif //DNA_UI_H
