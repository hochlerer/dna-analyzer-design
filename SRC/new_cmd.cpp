//
// Created by y on 7/5/20.
//


#include <sstream>
#include "new_cmd.h"
#include "structure_dna.h"
#include "auxiliary_functions.h"

void NewCmd::createCMD(const Parser& params) {
    if(!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool NewCmd::isValid(const Parser &params) {
    if(params.getParams().size() < 1 || params.getParams().size() > 2){
        return false;
    }
    if(params.getParams().size() == 2){
        if(params.getParams()[1][0] != '@'){
            return false;
        }
    }
    return true;
}

void NewCmd::run(const Parser &params, StructureDna &dnaStructure ,IWriter &output) {
    static size_t countDna = 0;
    std::string dnaName;
    if(params.getParams().size() == 1 ){
        dnaName = "seq" + numTostring(++countDna);
        while (dnaStructure.isExistDna(dnaName)) {
            dnaName = "seq" + numTostring(++countDna);
        }
    }
    else {
        dnaName = params.getParams()[1].substr(1);
    }
    if(dnaStructure.isExistDna(dnaName)){
        output.write("this name is already exist. please enter again\n");
        return;
    }

    DnaMetaData* newDna = new DnaMetaData(params.getParams()[0], dnaName, (std::string)"new");
    dnaStructure.addDna(newDna);
    printAfterCommand(dnaStructure, output);
}

void NewCmd::printAfterCommand(StructureDna& dnaStructure ,IWriter& output)const {
    DnaMetaData temp(dnaStructure.findDna(DnaMetaData::getId()));
    std::string strToPrint, idStr;
    idStr = numTostring(temp.getId().getId());
    strToPrint = "[" + idStr + "]" + " " + temp.getName().getNameDna() +": " + temp.getDnaSeq()->getSeq() + "\n";
    output.write(strToPrint.c_str());
}


