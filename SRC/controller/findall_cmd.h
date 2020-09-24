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
    /*virtual*/ void run(const Parser& params, StructureDna& dnaStructure ,IOCallback<UI>& ioCallback);

private:
    void printAfterCommand(std::list<size_t> indexes ,IOCallback<UI>& ioCallback)const ;
    bool isValid(const Parser& params);
    size_t getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI>& ioCallback);
};

#endif //DNA_FINDALL_CMD_H
