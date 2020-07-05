//
// Created by y on 7/5/20.
//


#include <sstream>
#include "new_cmd.h"
#include "structure_dna.h"

NewCMD::NewCMD(const Parser& params) {
    if(params.getParams().size() < 1 || params.getParams().size() > 2){
        throw std::invalid_argument("INVALID NUMS OF ARGUMENT");
    }
}

void NewCMD::run(const Parser &params) {
    static size_t countDna =0;
    std::stringstream ss;
    std::string dnaName;
    if(params.getParams().size() == 1 ){
        ss << "seq" << ++countDna;
        dnaName = ss.str();
    }
    else {
        dnaName = params.getParams()[1];
    }
    DnaMetaData* newDna = new DnaMetaData(params.getParams()[0], dnaName, (std::string)"new");
    StructureDna::getIdStructure().insert(std::pair<IdDna, DnaMetaData*> (DnaMetaData::getId(), newDna));
}
