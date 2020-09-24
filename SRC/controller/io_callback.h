//
// Created by y on 9/24/20.
//

#ifndef SRC_IO_CALLBACK_H
#define SRC_IO_CALLBACK_H

#include <string>

template<class T>
class IOCallback {
public:
    typedef const std::string& (T::*tReadFunc)()const;
    typedef void (T::*tWriteFunc)(const std::string&)const;
    IOCallback(T& cInst, tReadFunc pReadFunc, tWriteFunc pWriteFunc) :m_cInst(cInst), m_pReadFunc(pReadFunc), m_pWriteFunc(pWriteFunc){}
    const std::string& runRead() const;
    void runWrite(const std::string& output) const;

private:
    T& m_cInst;
    tReadFunc m_pReadFunc;
    tWriteFunc m_pWriteFunc;
};

template<class T>
const std::string& IOCallback<T>::runRead() const {
    return (m_cInst.*m_pReadFunc)();
}

template<class T>
void IOCallback<T>::runWrite(const std::string &output) const {
    (m_cInst.*m_pWriteFunc)(output);
}

#endif //SRC_IO_CALLBACK_H
