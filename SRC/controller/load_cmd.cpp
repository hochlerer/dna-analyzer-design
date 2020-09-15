//
// Created by y on 7/5/20.
//

#include <sstream>
#include "load_cmd.h"
#include "../view/file_reader.h"
#include "auxiliary_functions.h"

void LoadCmd::createCMD(const Parser &params) {
    if(!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool LoadCmd::isValid(const Parser &params) {
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


void LoadCmd::run(const Parser &params, StructureDna& dnaStructure ,IWriter& output) {
    std::string dnaName, dnaSeq, fileName = params.getParams()[0];
    FileReader file(fileName);
    file.read();
    fileName = file.getFileName();
    dnaSeq = file.getStr();
    if(params.getParams().size() == 1 ){
        dnaName = fileName;
        while (dnaStructure.isExistDna(dnaName)) {
            dnaStructure.findDna(dnaName).increaseCounter();
            dnaName = fileName + "_" + numTostring(dnaStructure.findDna(dnaName).getCounter());
        }
    }
    else {
        dnaName = params.getParams()[1].substr(1);
        if(dnaStructure.isExistDna(dnaName)){
            output.write("this name is already exist. please enter again\n");
            return;
        }
    }

    DnaMetaData* newDna = new DnaMetaData(dnaSeq, dnaName, (std::string)"new");
    dnaStructure.addDna(newDna);
    printAfterCommand(dnaStructure, output);
}

void LoadCmd::printAfterCommand(StructureDna& dnaStructure ,IWriter& output) const {
    DnaMetaData temp(dnaStructure.findDna(DnaMetaData::getId()));
    std::string dnaSeq = temp.getDnaSeq()->getSeq();
    size_t lngDna  = dnaSeq.size();
    if(40 < lngDna){
        dnaSeq = dnaSeq.substr(0, 31) + "..." + dnaSeq.substr(lngDna-4, lngDna-1);
    }
    std::string strToPrint, idStr;
    idStr = numTostring(temp.getId());
    strToPrint = "[" + idStr + "]" + " " + temp.getName() +": " + dnaSeq + "\n";
    output.write(strToPrint.c_str());
}

