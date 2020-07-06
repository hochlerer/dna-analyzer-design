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

void LoadCmd::run(const Parser &params) {
    std::string dnaName, dnaSeq;
    FileReader file;
    file.read(params.getParams()[0].c_str());
    dnaSeq = file.getStr();

    if(params.getParams().size() == 1 ){
        dnaName = params.getParams()[0];
    }
    else {
        dnaName = params.getParams()[1];
    }

    DnaMetaData* newDna = new DnaMetaData(dnaSeq, dnaName, (std::string)"new");
    StructureDna::getIdStructure().insert(std::pair<IdDna, DnaMetaData*> (DnaMetaData::getId(), newDna));
    StructureDna::getNameStructure().insert(std::pair<NameDna,DnaMetaData*> (dnaName, newDna));

}

std::string LoadCmd::printAfterCommand() const {
    std::string dnaSeq = StructureDna::getIdStructure()[DnaMetaData::getId()]->getDnaSeq()->getSeq();
    size_t lngDna  = dnaSeq.size();
    if(40 < lngDna){
        dnaSeq = dnaSeq.substr(0, 31) + "..." + dnaSeq.substr(lngDna-4, lngDna-1);
    }
    std::stringstream idStr;
    idStr << StructureDna::getIdStructure()[DnaMetaData::getId()]->getId().getId();
    return "[" + idStr.str() + "]" + " " + StructureDna::getIdStructure()[DnaMetaData::getId()]->getName().getNameDna() +": " + dnaSeq + "\n";

}

