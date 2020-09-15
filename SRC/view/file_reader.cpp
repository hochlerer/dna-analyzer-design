//
// Created by y on 6/30/20.
//
#include <fstream>
#include <sstream>
#include "file_reader.h"


void FileReader::read() {
    std::ifstream file(m_filePath.c_str());

    if (!file.is_open()){
        throw std::ios_base::failure("FILE IS NOT VALID");
    }
    std::getline(file, m_strFile);
    file.close();
}

std::string FileReader::getFileName() const {
    size_t index;
    std::string splitName = m_filePath;
    index = splitName.find('/');
    while (std::string::npos != index){
        splitName = splitName.substr(index+1);
        index = splitName.find('/');
    }
    splitName = splitName.substr(0,splitName.find('.'));
    return splitName;
}

