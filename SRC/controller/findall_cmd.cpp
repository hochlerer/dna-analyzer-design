//
// Created by y on 9/22/20.
//

#include "findall_cmd.h"
#include "auxiliary_functions.h"

void FindallCmd::createCMD(const Parser& params) {

    if (!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool FindallCmd::isValid(const Parser &params) {

    if (2 != params.getParams().size()){

        return false;
    }

    if (params.getParams()[0][0] != '#' && params.getParams()[0][0] != '@'){

        return false;
    }

    return true;
}

size_t FindallCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI>& ioCallback) {
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


void FindallCmd::run(const Parser &params, StructureDna &dnaStructure , IOCallback<UI>& ioCallback) {
    size_t id = getDnaId(params.getParams()[0], dnaStructure, ioCallback), subId;

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
    std::list<size_t> indexes = originalDna->findAllSubDna(subDna);

    if (indexes.empty()){
        ioCallback.runWrite((subDna + " is not a substring of " + originalDna->getSeq() + "\n").c_str());
    }

    else {
        printAfterCommand(indexes, ioCallback);
    }
}

void FindallCmd::printAfterCommand(std::list<size_t> indexes, IOCallback<UI>& ioCallback) const {
    std::string string = "";

    while (!indexes.empty()){
        string += numTostring(indexes.front()) + " ";
        indexes.pop_front();
    }

    ioCallback.runWrite((string + "\n").c_str());
}
