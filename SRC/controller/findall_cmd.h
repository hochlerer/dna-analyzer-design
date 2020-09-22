//
// Created by y on 9/22/20.
//

#ifndef DNA_FINDALL_CMD_H
#define DNA_FINDALL_CMD_H

#include "analysis_command.h"

class FindallCmd: public AnalysisCmd{
public:
    /*virtual*/ ~FindallCmd(){};
    /*virtual*/ void createCMD(const Parser& params);
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IReader& input ,IWriter& output);

private:
    void printAfterCommand(std::list<size_t> indexes ,IWriter& output)const ;
    bool isValid(const Parser& params);
    size_t getDnaId(const std::string &dna, StructureDna &dnaStructure, IWriter &output);
};

#endif //DNA_FINDALL_CMD_H
