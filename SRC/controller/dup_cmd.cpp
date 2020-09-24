//
// Created by y on 7/6/20.
//

#include <sstream>

#include "dup_cmd.h"
#include "auxiliary_functions.h"


void DupCmd::createCMD(const Parser &params) {

    if (!isValid(params)){

        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool DupCmd::isValid(const Parser &params) {

    if (params.getParams().size() < 1 || params.getParams().size() > 2){

        return false;
    }

    if (params.getParams()[0][0] != '#' && params.getParams()[0][0] != '@'){

        return false;
    }

    if (params.getParams().size() == 2){
        if (params.getParams()[1][0] != '@' ){

            return false;
        }
    }

    return true;
}


size_t DupCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI> &ioCallback) {
    std::string dnaName;
    size_t dnaId;

    if (dna[0] == '@'){
        dnaName = dna.substr(1);

        if (!dnaStructure.isExistDna(dnaName)){
            ioCallback.runWrite("Name not exist. please enter again\n");

            return 0;
        }
        dnaId = dnaStructure.findDna(dnaName).getId();
    }

    else{
        dnaId = stringToNum(dna.substr(1));

        if (!dnaStructure.isExistDna(dnaId)){
            ioCallback.runWrite("Id not exist. please enter again\n");

            return 0;
        }
    }

    return dnaId;
}

void DupCmd::run(const Parser &params, StructureDna& dnaStructure ,IOCallback<UI> &ioCallback) {
    size_t dnaId = getDnaId(params.getParams()[0], dnaStructure, ioCallback);

    if (0 == dnaId){

        return;
    }
    std::string dnaName, dnaSeq = dnaStructure.findDna(dnaId).getDnaSeq()->getSeq();

    if (params.getParams().size() == 2){
        dnaName = params.getParams()[1].substr(1);

        if (dnaStructure.isExistDna(dnaName)){
            ioCallback.runWrite("the name is already exist. please enter again\n");

            return;
        }
    }

    else {
        dnaName = getNameById(dnaId, dnaStructure);
    }
    DnaMetaData* newDna = new DnaMetaData(dnaSeq, dnaName, (std::string)"new");
    dnaStructure.addDna(newDna);
    printAfterCommand(dnaStructure, ioCallback);
}

void DupCmd::printAfterCommand(StructureDna& dnaStructure ,IOCallback<UI> &ioCallback)const {
    DnaMetaData temp(dnaStructure.findDna(DnaMetaData::getLastId()));
    std::string strToPrint, idStr;
    idStr = numTostring(temp.getId());
    strToPrint = "[" + idStr + "]" + " " + temp.getName() + ": " + temp.getDnaSeq()->getSeq() + "\n";
    ioCallback.runWrite(strToPrint.c_str());
}


std::string DupCmd::getNameById(size_t id, StructureDna& dnaStructure ){
    std::string dnaName;
    std::string name = dnaStructure.findDna(id).getName();

    (dnaStructure.findDna(id)).increaseCounter();
    dnaName = name + "_" + numTostring(dnaStructure.findDna(id).getCounter());

    while (dnaStructure.isExistDna(dnaName)) {
        dnaStructure.findDna(id).increaseCounter();
        dnaName = name + "_" + numTostring(dnaStructure.findDna(id).getCounter());
    }

    return dnaName;
}


