//
// Created by y on 7/6/20.
//

#include <sstream>

#include "dup_cmd.h"
#include "auxiliary_functions.h"


void DupCmd::createCMD(const Parser &params) {

    if (!isValid(params)){

        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool DupCmd::isValid(const Parser &params) {

    if (params.getParams().size() < 1 || params.getParams().size() > 2){

        return false;
    }

    if (params.getParams()[0][0] != '#' && params.getParams()[0][0] != '@'){

        return false;
    }

    if (params.getParams().size() == 2){
        if (params.getParams()[1][0] != '@' ){

            return false;
        }
    }

    return true;
}


size_t DupCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IWriter &output) {
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

void DupCmd::run(const Parser &params, StructureDna& dnaStructure ,IReader& input ,IWriter& output) {
    size_t dnaId = getDnaId(params.getParams()[0], dnaStructure, output);

    if (0 == dnaId){

        return;
    }
    std::string dnaName, dnaSeq = dnaStructure.findDna(dnaId).getDnaSeq()->getSeq();

    if (params.getParams().size() == 2){
        dnaName = params.getParams()[1].substr(1);

        if (dnaStructure.isExistDna(dnaName)){
            output.write("the name is already exist. please enter again\n");

            return;
        }
    }

    else {
        dnaName = getNameById(dnaId, dnaStructure);
    }
    DnaMetaData* newDna = new DnaMetaData(dnaSeq, dnaName, (std::string)"new");
    dnaStructure.addDna(newDna);
    printAfterCommand(dnaStructure, output);
}

void DupCmd::printAfterCommand(StructureDna& dnaStructure ,IWriter& output)const {
    DnaMetaData temp(dnaStructure.findDna(DnaMetaData::getLastId()));
    std::string strToPrint, idStr;
    idStr = numTostring(temp.getId());
    strToPrint = "[" + idStr + "]" + " " + temp.getName() + ": " + temp.getDnaSeq()->getSeq() + "\n";
    output.write(strToPrint.c_str());
}


std::string DupCmd::getNameById(size_t id, StructureDna& dnaStructure ){
    std::string dnaName;
    std::string name = dnaStructure.findDna(id).getName();

    (dnaStructure.findDna(id)).increaseCounter();
    dnaName = name + "_" + numTostring(dnaStructure.findDna(id).getCounter());

    while (dnaStructure.isExistDna(dnaName)) {
        dnaStructure.findDna(id).increaseCounter();
        dnaName = name + "_" + numTostring(dnaStructure.findDna(id).getCounter());
    }

    return dnaName;
}

//
//void DupCmd::getNameByName(const Parser &params, StructureDna &dnaStructure) {
//    std::string dnaName, dnaSeq, name= params.getParams()[0].substr(1) ;
//
//    dnaSeq = dnaStructure.findDna(name).getDnaSeq()->getSeq();
//
//    if (params.getParams().size() == 1 ){
//        (dnaStructure.findDna(name)).increaseCounter();
//        dnaName = name + "_" + numTostring(dnaStructure.findDna(name).getCounter());
//
//        while (dnaStructure.isExistDna(dnaName)) {
//            dnaStructure.findDna(name).increaseCounter();
//            dnaName = name + "_" + numTostring(dnaStructure.findDna(name).getCounter());
//        }
//    }
//
//    else {
//        dnaName = params.getParams()[1];
//    }
//    DnaMetaData* newDna = new DnaMetaData(dnaSeq, dnaName, (std::string)"new");
//    dnaStructure.addDna(newDna);
//}
