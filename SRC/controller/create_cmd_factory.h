//
// Created by y on 7/5/20.
//

#ifndef DNA_CREATE_CMD_FACTORY_H
#define DNA_CREATE_CMD_FACTORY_H

#include <string>
#include <map>

class Parser;
class ICMD;

class CreateCmdFactory{
public:
    static void init();
    static ICMD* create(const Parser& p);
    static void release();

private:
    static std::map<std::string, ICMD*> s_commands;
};

#endif //DNA_CREATE_CMD_FACTORY_H
