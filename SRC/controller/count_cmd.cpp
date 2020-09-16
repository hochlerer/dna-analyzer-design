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

size_t CountCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IWriter &output) {
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


void CountCmd::run(const Parser &params, StructureDna &dnaStructure ,IReader& input ,IWriter &output) {
    size_t count, id = getDnaId(params.getParams()[0], dnaStructure, output), subId;

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

    count = originalDna->countSubDna(subDna);

    if (0 == originalDna->getLength()){
        output.write((subDna + " is not a substring of " + originalDna->getSeq() + "\n").c_str());
    }

    else {
        printAfterCommand(count, output);
    }
}

void CountCmd::printAfterCommand(size_t count, IWriter &output) const {
    output.write((numTostring(count) + "\n").c_str());
}
