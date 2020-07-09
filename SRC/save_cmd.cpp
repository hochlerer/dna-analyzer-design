//
// Created by y on 7/8/20.
//

#include "save_cmd.h"
#include "auxiliary_functions.h"
#include "file_writer.h"

SaveCmd::SaveCmd(const Parser& params) {
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

    if(params.getParams()[0][0] == '#'){
        if(!dnaStructure.isExistDna(stringToNum(params.getParams()[0].substr(1)))){
            output.write("Id not exist. please enter again\n");
            return;
        }
        getNameById(params, dnaStructure);
    }
    else{
        if(!dnaStructure.isExistDna(params.getParams()[0].substr(1))){
            output.write("Name not exist. please enter again\n");
            return;
        }
        getNameByName(params, dnaStructure);
    }

}

void SaveCmd::getNameById(const Parser &params, StructureDna &dnaStructure) {
    size_t id = stringToNum(params.getParams()[0].substr(1));
    std::string dnaName, dnaSeq, name;

    name = dnaStructure.findDna(id).getName().getNameDna();
    dnaSeq = dnaStructure.findDna(id).getDnaSeq()->getSeq();
    if(params.getParams().size() == 1 ){
        (dnaStructure.findDna(id)).increaseCounter();
        dnaName = name + "_" + numTostring(dnaStructure.findDna(id).getCounter());
        while (dnaStructure.isExistDna(dnaName)) {
            dnaStructure.findDna(id).increaseCounter();
            dnaName = name + "_" + numTostring(dnaStructure.findDna(id).getCounter());
        }
    }
    else {
        dnaName = params.getParams()[1];

    }
    FileWriter file(dnaName + ".rowdna");
    file.write(dnaSeq.c_str());
}

void SaveCmd::getNameByName(const Parser &params, StructureDna &dnaStructure) {
    std::string dnaName, dnaSeq, name= params.getParams()[0].substr(1) ;

    dnaSeq = dnaStructure.findDna(name).getDnaSeq()->getSeq();
    if(params.getParams().size() == 1 ){
        (dnaStructure.findDna(name)).increaseCounter();
        dnaName = name + "_" + numTostring(dnaStructure.findDna(name).getCounter());
        while (dnaStructure.isExistDna(dnaName)) {
            dnaStructure.findDna(name).increaseCounter();
            dnaName = name + "_" + numTostring(dnaStructure.findDna(name).getCounter());
        }
    }
    else {
        dnaName = params.getParams()[1];
    }
    FileWriter file(dnaName + ".rowdna");
    file.write(dnaSeq.c_str());
}

