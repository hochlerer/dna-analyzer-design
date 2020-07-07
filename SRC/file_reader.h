//
// Created by y on 6/30/20.
//

#ifndef DNA_FILE_READER_H
#define DNA_FILE_READER_H

#include "IReader.h"

class FileReader: public IReader{
public:
    FileReader(const char* fileName):m_fileName(fileName){}
    void read()=0;
    /*virtual*/ const std::string& getStr()const{return m_strFile;};

private:
    const char* m_fileName;
    std::string m_strFile;
};

#endif //DNA_FILE_READER_H
