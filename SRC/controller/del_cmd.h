//
// Created by y on 9/15/20.
//

#ifndef DNA_DEL_CMD_H
#define DNA_DEL_CMD_H

#include "management_command.h"

class DelCmd: public ManagementCmd{
public:
    /*virtual*/ ~DelCmd(){};
    /*virtual*/ void createCMD(const Parser& params) ;
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IReader& input ,IWriter& output);

private:
    void printAfterCommand(IWriter &output, bool isDeleted, size_t id, std::string name, std::string seq)const ;
    bool isValid(const Parser& params);
    bool isConfirm(StructureDna &dnaStructure, IReader &input, IWriter &output, size_t id);
    bool isValidConfirm(std::string conf);
};

#endif //DNA_DEL_CMD_H
