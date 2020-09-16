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

size_t FindCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IWriter &output) {
    std::string dnaName;
    size_t dnaId;

    if (dna[0] == '@'){
        dnaName = dna.substr(1);

        if (!dnaStructure.isExistDna(dnaName)){
            output.write("Name not exist. please enter again\n");

            return 0;
        }
        dnaId = dnaStructure.findDna(dnaName).getId();
    }

    else{
        dnaId = stringToNum(dna.substr(1));

        if (!dnaStructure.isExistDna(dnaId)){
            output.write("Id not exist. please enter again\n");

            return 0;
        }
    }

    return dnaId;
}


void FindCmd::run(const Parser &params, StructureDna &dnaStructure ,IReader& input ,IWriter &output) {
    size_t index, id = getDnaId(params.getParams()[0], dnaStructure, output), subId;

    if (0 == id){

        return;
    };
    std::string subDna = params.getParams()[1];

    if ('@' == subDna[0] || '#' == subDna[0]){
        subId = getDnaId(subDna, dnaStructure, output);

        if (0 == subId){

            return;
        };
        subDna = dnaStructure.findDna(subId).getDnaSeq()->getSeq();
    }

    const DnaSequence* originalDna(dnaStructure.findDna(id).getDnaSeq());
    index = originalDna->findSubDna(subDna);

    if (index > originalDna->getLength()){
        output.write((subDna + " is not a substring of " + originalDna->getSeq() + "\n").c_str());
    }

    else {
        printAfterCommand(index, output);
    }
}

void FindCmd::printAfterCommand(size_t index, IWriter &output) const {
    output.write((numTostring(index) + "\n").c_str());
}
