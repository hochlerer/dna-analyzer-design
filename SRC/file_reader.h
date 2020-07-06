//
// Created by y on 6/30/20.
//

#ifndef DNA_FILE_READER_H
#define DNA_FILE_READER_H

#include "IReader.h"

class FileReader: public IReader{
public:
    void read(const char* fileName);
    /*virtual*/ const std::string& getStr()const{return m_strFile;};

private:
    std::string m_strFile;
};

#endif //DNA_FILE_READER_H
