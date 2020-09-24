//
// Created by y on 7/5/20.
//


#include <sstream>

#include "new_cmd.h"
#include "auxiliary_functions.h"


void NewCmd::createCMD(const Parser& params) {

    if (!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool NewCmd::isValid(const Parser &params) {

    if (params.getParams().size() < 1 || params.getParams().size() > 2){

        return false;
    }

    if (params.getParams().size() == 2){

        if (params.getParams()[1][0] != '@'){

            return false;
        }
    }

    return true;
}

void NewCmd::run(const Parser &params, StructureDna &dnaStructure , IOCallback<UI> &ioCallback) {
    static size_t countDna = 0;
    std::string dnaName;

    if (params.getParams().size() == 1 ){
        dnaName = "seq" + numTostring(++countDna);

        while (dnaStructure.isExistDna(dnaName)) {
            dnaName = "seq" + numTostring(++countDna);
        }
    }

    else {
        dnaName = params.getParams()[1].substr(1);
    }

    if (dnaStructure.isExistDna(dnaName)){
        ioCallback.runWrite("This name is already exist. please enter again\n");

        return;
    }

    DnaMetaData* newDna = new DnaMetaData(params.getParams()[0], dnaName, (std::string)"new");
    dnaStructure.addDna(newDna);
    printAfterCommand(dnaStructure, ioCallback);
}

void NewCmd::printAfterCommand(StructureDna& dnaStructure ,IOCallback<UI> &ioCallback)const {
    DnaMetaData temp(dnaStructure.findDna(DnaMetaData::getLastId()));
    std::string strToPrint, idStr;
    idStr = numTostring(temp.getId());
    strToPrint = "[" + idStr + "]" + " " + temp.getName() +": " + temp.getDnaSeq()->getSeq() + "\n";
    ioCallback.runWrite(strToPrint.c_str());
}


