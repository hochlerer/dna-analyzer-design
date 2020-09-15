//
// Created by y on 7/5/20.
//

#ifndef DNA_LOAD_CMD_H
#define DNA_LOAD_CMD_H

#include "creation_command.h"

class LoadCmd: public CreationCmd{
public:
    /*virtual*/ ~LoadCmd() {}
    /*virtual*/ void createCMD(const Parser& params) ;
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure , IReader& input ,IWriter& output);

private:
    void printAfterCommand(StructureDna& dnaStructure ,IWriter& output)const ;
    bool isValid(const Parser& params);
};

#endif //DNA_LOAD_CMD_H
