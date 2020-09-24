//
// Created by y on 9/16/20.
//

#ifndef DNA_RENAME_CMD_H
#define DNA_RENAME_CMD_H

#include "management_command.h"

class RenameCmd: public ManagementCmd{
public:
    /*virtual*/ ~RenameCmd(){};
    /*virtual*/ void createCMD(const Parser& params) ;
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IOCallback<UI>& ioCallback);

private:
    bool isValid(const Parser& params);
    size_t getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI>& ioCallback);
};

#endif //DNA_RENAME_CMD_H
