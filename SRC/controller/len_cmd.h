//
// Created by y on 9/15/20.
//

#ifndef DNA_LEN_CMD_H
#define DNA_LEN_CMD_H

#include "analysis_command.h"

class LenCmd: public AnalysisCmd{
public:
    /*virtual*/ ~LenCmd(){};
    /*virtual*/ void createCMD(const Parser& params);
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IReader& input ,IWriter& output);

private:
    void printAfterCommand(size_t len ,IWriter& output)const ;
    bool isValid(const Parser& params);
};

#endif //DNA_LEN_CMD_H
