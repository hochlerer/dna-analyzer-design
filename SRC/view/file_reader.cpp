//
// Created by y on 6/30/20.
//
#include <fstream>
#include "file_reader.h"

void FileReader::read() {
    std::ifstream file(m_fileName);
    if(!file.is_open()){
        throw std::ios_base::failure("FILE IS NOT VALID");
    }
    std::getline(file, m_strFile);
    file.close();
}

