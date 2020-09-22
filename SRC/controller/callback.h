//
// Created by y on 9/17/20.
//

#ifndef DNA_CALLBACK_H
#define DNA_CALLBACK_H
class Parser;
class StructureDna;
class IReader;
class IWriter;


template<class cInstance>
class Callback{
public:
    typedef void (cInstance::*pMethod)(Parser &p, StructureDna &dnaStructure, IReader &input, IWriter &output);
    Callback(cInstance &instance, pMethod method):m_inst(instance), m_method(method){}
    void operator()(Parser &p, StructureDna &dnaStructure, IReader &input, IWriter &output) const;

private:
    cInstance& m_inst;
    pMethod m_method;
};

template<class cInstance>
void Callback<cInstance>::operator()(Parser &p, StructureDna &dnaStructure, IReader &input, IWriter &output) const {
    (m_inst.*m_method)(p, dnaStructure, input, output);
}

#endif //DNA_CALLBACK_H
