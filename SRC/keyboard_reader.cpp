//
// Created by y on 6/30/20.
//

#include "keyboard_reader.h"
#include <iostream>

void KeyboardReader::read() {
    std::cout<<"Enter your string: ";
    std::cin>>m_str;
    std::cout<<std::endl;
}

