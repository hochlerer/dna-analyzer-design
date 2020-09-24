//
// Created by y on 7/6/20.
//

#ifndef DNA_DUP_CMD_H
#define DNA_DUP_CMD_H

#include "creation_command.h"

class DupCmd: public CreationCmd{
public:
    /*virtual*/ ~DupCmd() {}
    /*virtual*/ void createCMD(const Parser& params) ;
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IOCallback<UI> &ioCallback);

private:
    void printAfterCommand(StructureDna& dnaStructure ,IOCallback<UI> &ioCallback)const ;
    bool isValid(const Parser& params);
    size_t getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI> &ioCallback);
    std::string getNameById(size_t id, StructureDna& dnaStructure);
};

#endif //DNA_DUP_CMD_H
