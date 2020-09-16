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

size_t LenCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IWriter &output) {
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

void LenCmd::run(const Parser &params, StructureDna &dnaStructure ,IReader& input ,IWriter &output) {
    size_t len, id = getDnaId(params.getParams()[0], dnaStructure, output);

    if (0 == id){

        return;
    };

    if (!dnaStructure.isExistDna(id)){
        output.write("Id is not exist. please enter again\n");

        return;
    }
    len = dnaStructure.findDna(id).getDnaSeq()->getLength();
    printAfterCommand(len, output);
}

void LenCmd::printAfterCommand(size_t len, IWriter &output) const {
    output.write((numTostring(len) + "\n").c_str());
}
