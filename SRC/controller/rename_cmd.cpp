//
// Created by y on 9/16/20.
//

#include "rename_cmd.h"
#include "auxiliary_functions.h"
#include "../view/file_writer.h"

void RenameCmd::createCMD(const Parser& params) {

    if (!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool RenameCmd::isValid(const Parser &params) {

    if (2 != params.getParams().size()){

        return false;
    }

    if (params.getParams()[0][0] != '@' && params.getParams()[0][0] != '#'){

        return false;
    }

    if (params.getParams()[1][0] != '@'){

        return false;
    }

    return true;
}

size_t RenameCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IOCallback<UI>& ioCallback) {
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

void RenameCmd::run(const Parser &params, StructureDna &dnaStructure, IOCallback<UI>& ioCallback) {
    size_t currDnaId = getDnaId(params.getParams()[0], dnaStructure, ioCallback);

    if (0 == currDnaId){

        return;
    }
    std::string newName = params.getParams()[1].substr(1);

    if (dnaStructure.isExistDna(newName)){
        ioCallback.runWrite("the name is already exist. please enter again\n");

        return;
    }
    std::string currName = dnaStructure.findDna(currDnaId).getName();
    dnaStructure.setDnaName(currName, newName);
}