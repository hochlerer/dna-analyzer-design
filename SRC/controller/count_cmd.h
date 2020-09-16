//
// Created by y on 9/16/20.
//

#ifndef DNA_COUNT_CMD_H
#define DNA_COUNT_CMD_H

#include "analysis_command.h"

class CountCmd: public AnalysisCmd{
public:
    /*virtual*/ ~CountCmd(){};
    /*virtual*/ void createCMD(const Parser& params);
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IReader& input ,IWriter& output);

private:
    void printAfterCommand(size_t count ,IWriter& output)const ;
    bool isValid(const Parser& params);
    size_t getDnaId(const std::string &dna, StructureDna &dnaStructure, IWriter &output);
};


#endif //DNA_COUNT_CMD_H
