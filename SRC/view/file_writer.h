//
// Created by y on 6/30/20.
//

#ifndef DNA_FILE_WRITER_H
#define DNA_FILE_WRITER_H

#include <string>

#include "IWriter.h"


class FileWriter: public IWriter{
public:
    FileWriter(std::string fileName);
    /*virtual*/ void write(const char* str)const ;

private:
    std::string m_fileName;
};

#endif //DNA_FILE_WRITER_H
