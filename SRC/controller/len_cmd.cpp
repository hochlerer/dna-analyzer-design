//
// Created by y on 9/15/20.
//

#include "len_cmd.h"
#include "auxiliary_functions.h"

void LenCmd::createCMD(const Parser& params) {

    if (!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool LenCmd::isValid(const Parser &params) {

    if (1 != params.getParams().size()){

        return false;
    }

    if (params.getParams()[0][0] != '#' && params.getParams()[0][0] != '@'){

        return false;
    }

    return true;
}

size_t LenCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI>& ioCallback) {
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

void LenCmd::run(const Parser &params, StructureDna &dnaStructure ,IOCallback<UI>& ioCallback) {
    size_t len, id = getDnaId(params.getParams()[0], dnaStructure, ioCallback);

    if (0 == id){

        return;
    };

    if (!dnaStructure.isExistDna(id)){
        ioCallback.runWrite("Id is not exist. please enter again\n");

        return;
    }
    len = dnaStructure.findDna(id).getDnaSeq()->getLength();
    printAfterCommand(len, ioCallback);
}

void LenCmd::printAfterCommand(size_t len, IOCallback<UI>& ioCallback) const {
    ioCallback.runWrite((numTostring(len) + "\n").c_str());
}
