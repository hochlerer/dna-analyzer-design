//
// Created by y on 7/6/20.
//

#ifndef DNA_DUP_CMD_H
#define DNA_DUP_CMD_H
#include "creation_command.h"

class DupCmd: public CreationCmd{
public:
    DupCmd(const Parser& params);
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IWriter& output);

private:
    void printAfterCommand(StructureDna& dnaStructure ,IWriter& output)const ;
};

#endif //DNA_DUP_CMD_H
