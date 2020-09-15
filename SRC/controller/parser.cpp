//
// Created by y on 7/5/20.
//
#include "parser.h"

void Parser::parseCmd(std::string cmd) {
    size_t pos =0;

//    if ("" == cmd){
//        m_commandName = "new";
//    }

    if ((pos = cmd.find(' ')) == std::string::npos){
        m_commandName = cmd;

        return;
    }
    m_commandName = cmd.substr(0, pos);
    cmd.erase(0, pos+1);

    while ((pos = cmd.find(' ')) != std::string::npos) {
        m_params.push_back(cmd.substr(0, pos));
        cmd.erase(0, pos+1);
    }
    m_params.push_back(cmd);
}

