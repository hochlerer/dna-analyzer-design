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
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IOCallback<UI>& ioCallback);

private:
    void printAfterCommand(IOCallback<UI>& ioCallback, bool isDeleted, size_t id, std::string name, std::string seq)const ;
    bool isValid(const Parser& params);
    size_t getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI>& ioCallback);
    bool isConfirm(StructureDna &dnaStructure, IOCallback<UI>& ioCallback, size_t id);
    bool isValidConfirm(std::string conf);
};

#endif //DNA_DEL_CMD_H
