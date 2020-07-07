//
// Created by y on 7/5/20.
//


#include <sstream>
#include "new_cmd.h"
#include "structure_dna.h"

NewCmd::NewCmd(const Parser& params) {
    if(params.getParams().size() < 1 || params.getParams().size() > 2){
        throw std::invalid_argument("INVALID NUMS OF ARGUMENT");
    }
}

void NewCmd::run(const Parser &params, StructureDna& dnaStructure ,IWriter& output) {
    std::stringstream ss;
    std::string dnaName;
    if(params.getParams().size() == 1 ){
        ss << "seq" << ++CreationCmd::s_countDna;
        dnaName = ss.str();
    }
    else {
        dnaName = params.getParams()[1];
    }
    DnaMetaData* newDna = new DnaMetaData(params.getParams()[0], dnaName, (std::string)"new");
    dnaStructure.addDna(newDna);
    printAfterCommand(dnaStructure, output);
}

void NewCmd::printAfterCommand(StructureDna& dnaStructure ,IWriter& output)const {
    std::stringstream idStr;
    std::string  strToPrint;
    idStr << dnaStructure.getIdStructure()[DnaMetaData::getId()]->getId().getId();
    strToPrint = "[" + idStr.str() + "]" + " " + dnaStructure.getIdStructure()[DnaMetaData::getId()]->getName().getNameDna() +": " + dnaStructure.getIdStructure()[DnaMetaData::getId()]->getDnaSeq()->getSeq() + "\n";
    output.write(strToPrint.c_str());
}
