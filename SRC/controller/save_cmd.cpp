//
// Created by y on 7/8/20.
//

#include "save_cmd.h"
#include "auxiliary_functions.h"
#include "../view/file_writer.h"

void SaveCmd::createCMD(const Parser& params) {
    if(!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool SaveCmd::isValid(const Parser &params) {
    if(params.getParams().size() < 1 || params.getParams().size() > 2){
        return false;
    }
    if(params.getParams()[0][0] != '#'&& params.getParams()[0][0] != '@'){
        return false;
    }
    if(params.getParams().size() == 2){
        if(params.getParams()[1][0] != '@' ){
            return false;
        }
    }
    return true;
}

void SaveCmd::run(const Parser &params, StructureDna &dnaStructure, IWriter &output) {
    size_t id;
    std::string dnaName, fileName, rawdnaPath = "model/rawdna_files/";
//"../SRC/model/rawdna_files"
    if (params.getParams()[0][0] == '@'){
        dnaName = params.getParams()[0].substr(1);
        if (!dnaStructure.isExistDna(dnaName)){
            output.write("Name not exist. please enter again\n");

            return;
        }
        id = dnaStructure.findDna(dnaName).getId();
    }

    else{
        id = stringToNum(params.getParams()[0].substr(1));
        if (!dnaStructure.isExistDna(id)){
            output.write("Id not exist. please enter again\n");

            return;
        }
        dnaName = dnaStructure.findDna(id).getName();
    }

    if (2 == params.getParams().size()){
        fileName = params.getParams()[1].substr(1);
    }

    else {
        fileName = dnaName;
    }
    FileWriter file(rawdnaPath + fileName + ".rawdna");
    file.write(dnaStructure.findDna(id).getDnaSeq()->getSeq());
}