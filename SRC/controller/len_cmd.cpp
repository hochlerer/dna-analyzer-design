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

    if (params.getParams()[0][0] != '#'){

        return false;
    }

    return true;
}

void LenCmd::run(const Parser &params, StructureDna &dnaStructure, IWriter &output) {
    size_t id = stringToNum(params.getParams()[0].substr(1)), len;

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
