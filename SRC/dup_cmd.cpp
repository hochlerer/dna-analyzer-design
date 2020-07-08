//
// Created by y on 7/6/20.
//

#include "dup_cmd.h"
#include <sstream>
#include "structure_dna.h"
#include "auxiliary_functions.h"


DupCmd::DupCmd(const Parser &params) {
    if(!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool DupCmd::isValid(const Parser &params) {
    if(params.getParams().size() < 1 || params.getParams().size() > 2){
        return false;
    }
    if(params.getParams()[0][0] != '#' && params.getParams()[0][0] != '@'){
        return false;
    }
    if(params.getParams().size() == 2){
        if(params.getParams()[1][0] != '@' ){
            return false;
        }
    }
    return true;
}


void DupCmd::run(const Parser &params, StructureDna& dnaStructure ,IWriter& output) {
    std::string dnaName, dnaSeq;

    if(params.getParams().size() == 2){
        if(dnaStructure.isExistDna(params.getParams()[1].substr(1))){
            output.write("the name is already exist. please enter again\n");
        }
    }

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

    printAfterCommand(dnaStructure, output);
}

void DupCmd::printAfterCommand(StructureDna& dnaStructure ,IWriter& output)const {
    DnaMetaData temp(dnaStructure.findDna(DnaMetaData::getId()));
    std::string strToPrint, idStr;
    idStr = numTostring(temp.getId().getId());
    strToPrint = "[" + idStr + "]" + " " + temp.getName().getNameDna() + ": " + temp.getDnaSeq()->getSeq() + "\n";
    output.write(strToPrint.c_str());
}


void DupCmd::getNameById(const Parser &params, StructureDna& dnaStructure ){
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
    DnaMetaData* newDna = new DnaMetaData(dnaSeq, dnaName, (std::string)"new");
    dnaStructure.addDna(newDna);
}

void DupCmd::getNameByName(const Parser &params, StructureDna &dnaStructure) {
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
    DnaMetaData* newDna = new DnaMetaData(dnaSeq, dnaName, (std::string)"new");
    dnaStructure.addDna(newDna);
}
