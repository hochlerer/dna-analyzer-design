//
// Created by y on 7/8/20.
//

#include "save_cmd.h"
#include "auxiliary_functions.h"
#include "../view/file_writer.h"

void SaveCmd::createCMD(const Parser& params) {

    if (!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool SaveCmd::isValid(const Parser &params) {

    if (params.getParams().size() < 1 || params.getParams().size() > 2){

        return false;
    }

    if (params.getParams()[0][0] != '#'&& params.getParams()[0][0] != '@'){

        return false;
    }

    if (params.getParams().size() == 2){

        if (params.getParams()[1][0] != '@' ){

            return false;
        }
    }

    return true;
}

size_t SaveCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IWriter &output){
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

void SaveCmd::run(const Parser &params, StructureDna &dnaStructure, IReader& input, IWriter &output) {
    size_t id = getDnaId(params.getParams()[0], dnaStructure, output);

    if (0 == id){

        return;
    }
    std::string dnaName = dnaStructure.findDna(id).getName(), fileName, rawdnaPath = "model/rawdna_files/";

    if (2 == params.getParams().size()){
        fileName = params.getParams()[1].substr(1);
    }

    else {
        fileName = dnaName;
    }
    FileWriter file(rawdnaPath + fileName + ".rawdna");
    file.write(dnaStructure.findDna(id).getDnaSeq()->getSeq());
}