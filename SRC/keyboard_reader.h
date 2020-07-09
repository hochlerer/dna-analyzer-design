//
// Created by y on 6/30/20.
//

#ifndef DNA_KEYBOARD_READER_H
#define DNA_KEYBOARD_READER_H
#include "IReader.h"
#include <string>

class KeyboardReader: public IReader{
public:
    void read();
    /*virtual*/ const std::string& getStr()const{return m_str;};

private:
    std::string m_str;
};

#endif //DNA_KEYBOARD_READER_H
