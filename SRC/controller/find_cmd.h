//
// Created by y on 9/16/20.
//

#ifndef DNA_FIND_CMD_H
#define DNA_FIND_CMD_H

#include "analysis_command.h"

class FindCmd: public AnalysisCmd{
public:
    /*virtual*/ ~FindCmd(){};
    /*virtual*/ void createCMD(const Parser& params);
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IOCallback<UI>& ioCallback);

private:
    void printAfterCommand(size_t len ,IOCallback<UI>& ioCallback)const ;
    bool isValid(const Parser& params);
    size_t getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI>& ioCallback);
};


#endif //DNA_FIND_CMD_H
