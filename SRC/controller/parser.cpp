//
// Created by y on 7/5/20.
//
#include "parser.h"

void Parser::parseCmd(std::string cmd) {
    setName(cmd);
    setParams(cmd);
}

void Parser::setName(std::string &cmd){
    size_t pos = cmd.find(' ') != std::string::npos ? cmd.find(' ') : cmd.size();
    m_commandName = cmd.substr(0, pos);
    cmd.erase(0, pos+1);
}

void Parser::setParams(std::string &cmd) {
    size_t pos =0;

    while ((pos = cmd.find(' ')) != std::string::npos) {
        m_params.push_back(cmd.substr(0, pos));
        cmd.erase(0, pos+1);
    }

    if (!cmd.empty()){
        m_params.push_back(cmd);
    }
}

