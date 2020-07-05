//
// Created by y on 6/30/20.
//

#ifndef DNA_IREADER_H
#define DNA_IREADER_H
#include <string>

class IReader{
public:
    virtual ~IReader(){}
    virtual const std::string& getStr()const = 0;
};

#endif //DNA_IREADER_H
