//
// Created by y on 7/5/20.
//

#ifndef DNA_CREATE_CMD_FACTORY_H
#define DNA_CREATE_CMD_FACTORY_H

#include <string>
class Parser;
class ICMD;

class CreateCmdFactory{
public:
    static ICMD* create(const Parser& p);
};

#endif //DNA_CREATE_CMD_FACTORY_H
