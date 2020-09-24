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
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IOCallback<UI>& ioCallback);

private:
    void printAfterCommand(size_t len ,IOCallback<UI>& ioCallback)const ;
    bool isValid(const Parser& params);
    size_t getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI>& ioCallback);

};

#endif //DNA_LEN_CMD_H
