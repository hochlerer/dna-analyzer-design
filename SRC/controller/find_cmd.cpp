//
// Created by y on 9/16/20.
//

#include "find_cmd.h"
#include "auxiliary_functions.h"

void FindCmd::createCMD(const Parser& params) {

    if (!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool FindCmd::isValid(const Parser &params) {

    if (2 != params.getParams().size()){

        return false;
    }

    if (params.getParams()[0][0] != '#' && params.getParams()[0][0] != '@'){

        return false;
    }

    return true;
}

size_t FindCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI>& ioCallback) {
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


void FindCmd::run(const Parser &params, StructureDna &dnaStructure ,IOCallback<UI>& ioCallback) {
    size_t index, id = getDnaId(params.getParams()[0], dnaStructure, ioCallback), subId;

    if (0 == id){

        return;
    };
    std::string subDna = params.getParams()[1];

    if ('@' == subDna[0] || '#' == subDna[0]){
        subId = getDnaId(subDna, dnaStructure, ioCallback);

        if (0 == subId){

            return;
        };
        subDna = dnaStructure.findDna(subId).getDnaSeq()->getSeq();
    }

    const DnaSequence* originalDna(dnaStructure.findDna(id).getDnaSeq());
    index = originalDna->findSubDna(subDna);

    if (index > originalDna->getLength()){
        ioCallback.runWrite((subDna + " is not a substring of " + originalDna->getSeq() + "\n").c_str());
    }

    else {
        printAfterCommand(index, ioCallback);
    }
}

void FindCmd::printAfterCommand(size_t index, IOCallback<UI>& ioCallback) const {
    ioCallback.runWrite((numTostring(index) + "\n").c_str());
}
