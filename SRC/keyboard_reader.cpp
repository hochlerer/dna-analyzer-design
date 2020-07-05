//
// Created by y on 6/30/20.
//

#include "keyboard_reader.h"
#include <iostream>

void KeyboardReader::read() {
    std::string str;
    std::cout<<"> cmd >>> ";
    std::getline(std::cin, m_str, '\n');
    std::cout<<std::endl;
}

