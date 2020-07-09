//
// Created by y on 6/30/20.
//

#include "file_writer.h"
#include <fstream>

FileWriter::FileWriter(std::string fileName):m_fileName(fileName) {}

void FileWriter::write(const char *str)const {
    std::ofstream file;
    file.open(m_fileName.c_str());
    if(!file.is_open()){
        throw std::ios_base::failure("FILE IS NOT VALID");
    }
    file << str;
    file.close();
}

