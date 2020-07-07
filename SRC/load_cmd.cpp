//
// Created by y on 7/5/20.
//

#include <sstream>
#include "load_cmd.h"
#include "structure_dna.h"
#include "file_reader.h"

LoadCmd::LoadCmd(const Parser &params) {
    if(params.getParams().size() < 1 || params.getParams().size() > 2){
        throw std::invalid_argument("INVALID NUMS OF ARGUMENT");
    }
}

void LoadCmd::run(const Parser &params, StructureDna& dnaStructure ,IWriter& output) {
    std::string dnaName, dnaSeq;
    FileReader file(params.getParams()[0].c_str());
    file.read();
    dnaSeq = file.getStr();

    if(params.getParams().size() == 1 ){
        dnaName = params.getParams()[0];
    }
    else {
        dnaName = params.getParams()[1];
    }

    DnaMetaData* newDna = new DnaMetaData(dnaSeq, dnaName, (std::string)"new");
    dnaStructure.addDna(newDna);
    printAfterCommand(dnaStructure, output);
}

void LoadCmd::printAfterCommand(StructureDna& dnaStructure ,IWriter& output) const {
    std::string dnaSeq = dnaStructure.getIdStructure()[DnaMetaData::getId()]->getDnaSeq()->getSeq();
    size_t lngDna  = dnaSeq.size();
    if(40 < lngDna){
        dnaSeq = dnaSeq.substr(0, 31) + "..." + dnaSeq.substr(lngDna-4, lngDna-1);
    }
    std::stringstream idStr;
    std::string strToPrint;
    idStr << dnaStructure.getIdStructure()[DnaMetaData::getId()]->getId().getId();
    strToPrint = "[" + idStr.str() + "]" + " " + dnaStructure.getIdStructure()[DnaMetaData::getId()]->getName().getNameDna() +": " + dnaSeq + "\n";
    output.write(strToPrint.c_str());
}

