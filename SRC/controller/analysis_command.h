//
// Created by y on 9/15/20.
//

#ifndef DNA_ANALYSIS_COMMAND_H
#define DNA_ANALYSIS_COMMAND_H

#include "ICMD.h"

class AnalysisCmd: public ICMD{
public:
    /*virtual*/ ~AnalysisCmd(){};
    /*virtual*/ void createCMD(const Parser& params) = 0;
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure, IReader &input ,IWriter& output) =0;

};

#endif //DNA_ANALYSIS_COMMAND_H
