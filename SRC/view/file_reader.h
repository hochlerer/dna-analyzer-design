//
// Created by y on 6/30/20.
//

#ifndef DNA_FILE_READER_H
#define DNA_FILE_READER_H

#include "IReader.h"

class FileReader: public IReader{
public:
    FileReader(std::string fileName): m_filePath(fileName){}
    /*virtual*/ void read();
    /*virtual*/ const std::string& getStr()const{return m_strFile;};
    std::string getFileName()const ;

private:
    std::string m_filePath;
    std::string m_strFile;
};

#endif //DNA_FILE_READER_H
