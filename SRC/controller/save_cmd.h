//
// Created by y on 7/8/20.
//

#ifndef DNA_SAVE_CMD_H
#define DNA_SAVE_CMD_H
#include "management_command.h"

class SaveCmd: public ManagementCmd{
public:
    /*virtual*/ ~SaveCmd(){};
    /*virtual*/ void createCMD(const Parser& params) ;
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IWriter& output);

private:
    bool isValid(const Parser& params);
};

#endif //DNA_SAVE_CMD_H