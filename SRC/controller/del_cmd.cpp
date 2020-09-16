//
// Created by y on 9/15/20.
//

#include "del_cmd.h"
#include "auxiliary_functions.h"
#include "../view/file_writer.h"

void DelCmd::createCMD(const Parser& params) {

    if (!isValid(params)){
        throw std::invalid_argument("INVALID ARGUMENT");
    }
}

bool DelCmd::isValid(const Parser &params) {

    if (1 != params.getParams().size()){

        return false;
    }

    if (params.getParams()[0][0] != '#' && params.getParams()[0][0] != '@'){

        return false;
    }


    return true;
}

size_t DelCmd::getDnaId(const std::string &dna, StructureDna &dnaStructure, IWriter &output) {
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


void DelCmd::run(const Parser &params, StructureDna &dnaStructure, IReader &input, IWriter &output) {
    size_t id = getDnaId(params.getParams()[0], dnaStructure, output);

    if (0 == id){

        return;
    }
    std::string dnaName = dnaStructure.findDna(id).getName();
    bool isDeleted = isConfirm(dnaStructure, input, output, id);
    std::string seq = dnaStructure.findDna(id).getDnaSeq()->getSeq();

    if (isDeleted){
        dnaStructure.erase(id, dnaName);
        printAfterCommand(output, isDeleted, id, dnaName, seq);
    }

    else {
        printAfterCommand(output, isDeleted, id, dnaName, seq);
    }

}

bool DelCmd::isConfirm(StructureDna &dnaStructure, IReader &input, IWriter &output, size_t id) {
    DnaMetaData tempDna(dnaStructure.findDna(id));
    std::string name = tempDna.getName(), isConfirmed;
    std::string print = "Do you really want to delete " + name + " : " + tempDna.getDnaSeq()->getSeq() + " ?\n" +
                        "Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'.";
    output.write(print.c_str());
    output.write("> confirm >>> ");
    input.read();
    isConfirmed = input.getStr();

    while (!isValidConfirm(isConfirmed)){
        print = "You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.";
        output.write(print.c_str());
        input.read();
        isConfirmed = input.getStr();
    }

    return "Y" == isConfirmed || "y" == isConfirmed;

}


void DelCmd::printAfterCommand(IWriter &output, bool isDeleted, size_t id, std::string name, std::string seq) const {
    std::string print;

    if (isDeleted) {
        print = "Deleted: [" + numTostring(id) + "] " + name + ": " + seq + "\n";
        output.write(print.c_str());
    }

    else {
        print = "Deletion canceled\n";
        output.write(print.c_str());
    }
}

bool DelCmd::isValidConfirm(std::string conf) {
    if ("Y" == conf){
        return true;
    }

    if ("y" == conf){
        return true;
    }

    if ("N" == conf){
        return true;
    }

    if ("n" == conf){
        return true;
    }

    return false;
}

