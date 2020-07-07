//
// Created by y on 7/6/20.
//

#include "dup_cmd.h"
#include <sstream>
#include "structure_dna.h"


DupCmd::DupCmd(const Parser &params) {
    if(params.getParams().size() < 1 || params.getParams().size() > 2){
        throw std::invalid_argument("INVALID NUMS OF ARGUMENT");
    }
}

void DupCmd::run(const Parser &params, StructureDna& dnaStructure ,IWriter& output) {
    std::istringstream st(params.getParams()[0]);
    std::stringstream ss;
    size_t id;
    st>> id;
    std::string dnaName, dnaSeq;

    dnaSeq = dnaStructure.getIdStructure().find(id)->second->getDnaSeq()->getSeq();
    if(params.getParams().size() == 1 ){
        ss << ++CreationCmd::s_countDna;
        dnaName = (dnaStructure.getIdStructure().find(id))->second->getName().getNameDna() + "_" + ss.str();
    }
    else {
        dnaName = params.getParams()[1];
    }
    DnaMetaData* newDna = new DnaMetaData(dnaSeq, dnaName, (std::string)"new");
    dnaStructure.addDna(newDna);

    printAfterCommand(dnaStructure, output);
}

void DupCmd::printAfterCommand(StructureDna& dnaStructure ,IWriter& output)const {
    std::stringstream idStr;
    std::string  strToPrint;
    idStr << dnaStructure.getIdStructure()[DnaMetaData::getId()]->getId().getId();
    strToPrint = "[" + idStr.str() + "]" + " " + dnaStructure.getIdStructure()[DnaMetaData::getId()]->getName().getNameDna() +": " + dnaStructure.getIdStructure()[DnaMetaData::getId()]->getDnaSeq()->getSeq() + "\n";
    output.write(strToPrint.c_str());}