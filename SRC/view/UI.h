//
// Created by y on 9/15/20.
//

#ifndef DNA_UI_H
#define DNA_UI_H
#include "../controller/callback.h"

class IReader;
class IWriter;
class System;
class StructureDna;



class UI{
public:
    virtual void start(Callback<System> &callback, IReader& input, IWriter& output, StructureDna& dnaStructure) = 0;
};

#endif //DNA_UI_H
