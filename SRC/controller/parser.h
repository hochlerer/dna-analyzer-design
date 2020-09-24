//
// Created by y on 7/5/20.
//

#ifndef DNA_PARSER_H
#define DNA_PARSER_H

#include <string>
#include <vector>

class Parser{
public:
    void parseCmd(std::string cmd);
    const std::string& getCmdName()const {return m_commandName;}
    const std::vector<std::string>& getParams()const {return m_params;}

private:
    void setName(std::string &cmd);
    void setParams(std::string &cmd);
    std::string m_commandName;
    std::vector<std::string> m_params;
};

#endif //DNA_PARSER_H
