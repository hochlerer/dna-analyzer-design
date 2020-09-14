//
// Created by y on 6/1/20.
//

#ifndef DNA_DNA_SEQUENCE_H
#define DNA_DNA_SEQUENCE_H

#include <cstring>
#include <iostream>
#include "list"
#include "../view/IReader.h"

class DnaSequence{
private:
    class Nucleotide{
    public:
        Nucleotide():m_nuc('\0'){}
        Nucleotide(const char nuc);
        Nucleotide& operator=(const Nucleotide& nuc);
        char getNuc()const;
        operator char(){return m_nuc;}
        Nucleotide matchNucleotide()const ;
        friend std::ostream& operator <<(std::ostream &out,const Nucleotide& nuc){
            std::cout<< nuc.getNuc()<< std::endl;
            return out;
        }
    private:
        bool isValidNuc(const char nuc)const ;
        char m_nuc;
    };

public:
    DnaSequence(const char* seq);
    DnaSequence(const std::string& seq);
    DnaSequence(const IReader& seq);
    DnaSequence(const DnaSequence&);
    ~DnaSequence();
    const DnaSequence& operator=(const DnaSequence&);
    Nucleotide& operator[](size_t index);

    const char* getSeq()const ;
    size_t getLength()const;
    DnaSequence sliceDna(size_t start, size_t end)const;
    DnaSequence pairingDna()const ;
    size_t findSubDna(const DnaSequence& seq)const;
    size_t countSubDna(const DnaSequence &seq)const;
    std::list<size_t> findAllSubDna(const DnaSequence &seq)const;
    std::list<DnaSequence> findConsensusSequences() const;
    friend std::ostream& operator<<(std::ostream &out,const DnaSequence &str);

private:
    DnaSequence(size_t);
    void initDna(const char* seq);
    bool isValid(const char* seq);
    size_t minCodon(size_t TAGindex,size_t TAAindex,size_t TGAindex)const;
    Nucleotide* m_dnaSequence;
    size_t m_length;
};

bool operator==(const DnaSequence &seq1,const DnaSequence &seq2);

bool operator!=(const DnaSequence &seq1,const DnaSequence &seq2);

std::ostream& operator <<(std::ostream &out,const DnaSequence &str);

#endif //DNA_DNA_SEQUENCE_H
