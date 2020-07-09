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
    bool isValid(const Parser& params);
    void getNameById(const Parser &params, StructureDna& dnaStructure);
    void getNameByName(const Parser &params, StructureDna& dnaStructure );
    };

#endif //DNA_DUP_CMD_H
