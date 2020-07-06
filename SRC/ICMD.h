//
// Created by y on 7/5/20.
//

#ifndef DNA_ICMD_H
#define DNA_ICMD_H
#include "parser.h"
#include <string>

class ICMD{
public:
    virtual void run(const Parser& params) = 0;
    virtual std::string printAfterCommand()const =0;

private:
};

#endif //DNA_ICMD_H
