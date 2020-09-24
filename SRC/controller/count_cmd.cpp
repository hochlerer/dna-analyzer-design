//
// Created by y on 9/16/20.
//

#include "count_cmd.h"
#include "auxiliary_functions.h"

void CountCmd::createCMD(const Parser& params) {

    if (!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool CountCmd::isValid(const Parser &params) {

    if (2 != params.getParams().size()){

        return false;
    }

    if (params.getParams()[0][0] != '#' && params.getParams()[0][0] != '@'){

        return false;
    }

    return true;
}

size_t CountCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI>& ioCallback) {
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


void CountCmd::run(const Parser &params, StructureDna &dnaStructure ,IOCallback<UI>& ioCallback) {
    size_t count, id = getDnaId(params.getParams()[0], dnaStructure, ioCallback), subId;

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

    count = originalDna->countSubDna(subDna);

    if (0 == originalDna->getLength()){
        ioCallback.runWrite((subDna + " is not a substring of " + originalDna->getSeq() + "\n").c_str());
    }

    else {
        printAfterCommand(count, ioCallback);
    }
}

void CountCmd::printAfterCommand(size_t count, IOCallback<UI>& ioCallback) const {
    ioCallback.runWrite((numTostring(count) + "\n").c_str());
}
