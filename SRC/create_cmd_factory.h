//
// Created by y on 7/5/20.
//

#ifndef DNA_CREATE_CMD_FACTORY_H
#define DNA_CREATE_CMD_FACTORY_H

#include <string>
class ICMD;

class CreateCmdFactory{
public:
    static ICMD* create(const std::string& command);
};

#endif //DNA_CREATE_CMD_FACTORY_H
