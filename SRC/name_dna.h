//
// Created by y on 7/5/20.
//

#ifndef DNA_NAME_DNA_H
#define DNA_NAME_DNA_H

#include <string>

class NameDna{
public:
    NameDna(const std::string& name = ""):m_name(name){}
    const std::string& getNameDna()const {return m_name;}

private:
    std::string m_name;
};

#endif //DNA_NAME_DNA_H
