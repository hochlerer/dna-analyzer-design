//
// Created by y on 7/5/20.
//

#ifndef DNA_NEW_CMD_H
#define DNA_NEW_CMD_H

#include "creation_command.h"


class NewCmd: public CreationCmd{
public:
    /*virtual*/ ~NewCmd() {}
    /*virtual*/ void createCMD(const Parser& params) ;
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure , IOCallback<UI> &ioCallback);

private:
    void printAfterCommand(StructureDna& dnaStructure ,IOCallback<UI> &ioCallback)const ;
    bool isValid(const Parser& params);
};

#endif //DNA_NEW_CMD_H
