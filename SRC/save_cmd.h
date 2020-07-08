//
// Created by y on 7/8/20.
//

#ifndef DNA_SAVE_CMD_H
#define DNA_SAVE_CMD_H
#include "management_command.h"

class SaveCmd: public ManagementCmd{
public:
    SaveCmd(const Parser& params);
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IWriter& output);

private:
    bool isValid(const Parser& params);
    void getNameById(const Parser &params, StructureDna& dnaStructure);
    void getNameByName(const Parser &params, StructureDna& dnaStructure);
};

#endif //DNA_SAVE_CMD_H
