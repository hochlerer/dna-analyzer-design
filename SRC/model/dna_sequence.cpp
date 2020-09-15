//
// Created by y on 6/1/20.
//

#include <cstring>
#include "dna_sequence.h"
#include "list"
/*DnaSequence' methods*/

bool DnaSequence::isValid(const char* seq){

    if (!seq)
        throw std::invalid_argument("NULL DNA");

    if ((strspn(seq, "ACGT") != strlen(seq)) || strcmp(seq ,"\0")==0)
        throw std::invalid_argument("DNA IS NOT VALID");

    return true;
}

/*auxiliary function*/
void DnaSequence::initDna(const char* seq){
    m_dnaSequence = new Nucleotide[m_length + 1];

    for (size_t i=0; i < m_length; i++){
        m_dnaSequence[i] = seq[i];
    }
}

DnaSequence::DnaSequence(size_t lenght) {
    m_length = lenght;
    m_dnaSequence = new Nucleotide[m_length + 1];
}

DnaSequence::DnaSequence(const char* seq){

    if (isValid(seq)) {
        m_length = strlen(seq);
        initDna(seq);
    }
}

DnaSequence::DnaSequence(const std::string& seq){

    if (isValid(seq.c_str())) {
        m_length = strlen(seq.c_str());
        initDna(seq.c_str());
    }
}

DnaSequence::DnaSequence(const IReader& seq) {

    if (isValid(seq.getStr().c_str())){
        m_length = seq.getStr().length();
        initDna(seq.getStr().c_str());
    }
}

DnaSequence::DnaSequence(const DnaSequence& seq){
    m_length = strlen(seq.getSeq());
    initDna(seq.getSeq());
}

const DnaSequence& DnaSequence::operator=(const DnaSequence& seq){

    if (this == &seq)
        return *this;
    delete[] m_dnaSequence;
    m_dnaSequence = NULL;
    m_length = strlen(seq.getSeq());
    initDna(seq.getSeq());
    return *this;
}

DnaSequence::~DnaSequence(){
    delete[] m_dnaSequence;
    m_dnaSequence = NULL;
}

DnaSequence::Nucleotide& DnaSequence::operator[](size_t index){
    return m_dnaSequence[index];
}

bool operator==(const DnaSequence &seq1,const DnaSequence &seq2)
{
    return strcmp(seq1.getSeq(), seq2.getSeq()) == 0;
}

bool operator!=(const DnaSequence &seq1,const DnaSequence &seq2)
{
    return strcmp(seq1.getSeq(), seq2.getSeq()) !=0;
}

const char* DnaSequence::getSeq() const
{
    return (char*)m_dnaSequence;
}

size_t DnaSequence::getLength() const
{
    return m_length;
}

std::ostream& operator <<(std::ostream &out,const DnaSequence &seq)
{
    return out<<"the DNA is: " << seq.getSeq()<<std::endl;
}

DnaSequence DnaSequence::sliceDna(size_t start, size_t end)const {

    if (end>m_length)
        end = m_length;

    if(start > end)
        start = end;
    DnaSequence sliceDna(end - start);

    for (size_t i=start ,j=0; i<end ;i++, j++){
        sliceDna[j] = m_dnaSequence[i];
    }

    return sliceDna;
}

DnaSequence::Nucleotide DnaSequence::Nucleotide::matchNucleotide() const{

    if (m_nuc == 'A')
        return 'T';

    if (m_nuc == 'T')
        return 'A';

    if (m_nuc == 'G')
        return 'C';

    return 'G';
}

DnaSequence DnaSequence::pairingDna()const {
    DnaSequence pairDna(getLength());

    for (size_t i=0, j=m_length-1; i<m_length; i++, j--){
        pairDna.m_dnaSequence[i] = (m_dnaSequence[j]).matchNucleotide();
    }

    return pairDna;
}

size_t DnaSequence::findSubDna(const DnaSequence &seq)const {
    size_t index = std::string(getSeq()).find(std::string(seq.getSeq()));

    if (index == std::string::npos) {

        return m_length + 1;
    }

    return index;
}

size_t DnaSequence::countSubDna(const DnaSequence &seq)const {
    size_t count = 0;
    size_t index = findSubDna(seq.sliceDna(0,seq.getLength()));

    if (index || index==0){
        count++;
    }
    size_t tmpIndex;

    for (size_t i=1; i< getLength();i++){
        tmpIndex = sliceDna(i,getLength()).findSubDna(seq)+i;

        if (tmpIndex && tmpIndex < m_length){

            if(index != tmpIndex) {
                count++;
                index = tmpIndex;
            }
        }
    }

    return count;
}

std::list<size_t> DnaSequence::findAllSubDna(const DnaSequence &seq) const{
    std::list<size_t> countOccurrences;
    size_t index = 0;
    size_t tmpIndex;

    for (size_t i = 0; i<m_length;i++) {
        tmpIndex = sliceDna(i, getLength()).findSubDna(seq) + i;

        if (tmpIndex < m_length) {

            if (index != tmpIndex || tmpIndex == 0) {
                index = tmpIndex;
                countOccurrences.push_back(index);
            }
        }
    }

    return countOccurrences;
}

size_t DnaSequence::minCodon(size_t TAGindex,size_t TAAindex,size_t TGAindex)const{
    size_t minIndex = 0;
    minIndex = TAGindex<TAAindex? TAGindex:TAAindex;
    minIndex = minIndex<TGAindex? minIndex:TGAindex;

    return minIndex;
}


std::list<DnaSequence> DnaSequence::findConsensusSequences()const{
    std::list<DnaSequence> consensusSequence;
    std::list<size_t> countCodon = findAllSubDna("ATG");

    size_t TAGindex;
    size_t TAAindex;
    size_t TGAindex;
    size_t endCodon;
    int i=0;

    for (std::list<size_t>::iterator iter = countCodon.begin(); iter!= countCodon.end(); iter++){
        TAGindex = sliceDna(i+3, m_length).findSubDna("TAG")+i+3;
        TAAindex = sliceDna(i+3, m_length).findSubDna("TAA")+i+3;
        TGAindex = sliceDna(i+3, m_length).findSubDna("TGA")+i+3;

        if ((TAGindex-(*iter)) %3)
            TAGindex = m_length+1;

        if ((TAAindex-(*iter)) %3)
            TAAindex = m_length+1;

        if ((TGAindex-(*iter)) %3)
            TGAindex = m_length+1;

        endCodon = minCodon(TAGindex, TAAindex,TGAindex);

        if (endCodon <= m_length )
            consensusSequence.push_back(sliceDna(*iter,endCodon+3));
        i++;
    }

    return consensusSequence;
}


/*Nucleotide' methods*/

bool DnaSequence::Nucleotide::isValidNuc(const char nuc)const{

    return (nuc == 'A' || nuc == 'C' || nuc== 'G' || nuc == 'T');
}

DnaSequence::Nucleotide::Nucleotide(const char nuc){
    m_nuc = nuc;
}

DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator=(const Nucleotide& nuc){

    if (!isValidNuc(nuc.getNuc()))
        throw std::invalid_argument("DNA IS NOT VALID ");
    m_nuc = nuc.getNuc();

    return *this;
}

char DnaSequence::Nucleotide::getNuc()const
{
    return m_nuc;
}
