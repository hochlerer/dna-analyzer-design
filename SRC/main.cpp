#include <iostream>
#include <fstream>
#include "dna_sequence.h"
#include "list"
#include "file_reader.h"
#include "keyboard_reader.h"
#include "file_writer.h"
#include "screen_writer.h"
#include "system.h"

/*
void tetCharCtor(){
    char d[] = {"AAAA"};
    DnaSequence dna(d);
    if(strcmp(dna.getSeq(), "AAAA") == 0)
        std::cout<<"CString c'tor is OK!"<<std::endl;
    else
        std::cout<<"CString c'tor is not OK!"<<std::endl;
}

void testStringCtor(){
    std::string d = "GCGC";
    DnaSequence dna(d);
    if(strcmp(dna.getSeq(), "GCGC") == 0)
        std::cout<<"std::string c'tor is OK!"<<std::endl;
    else
        std::cout<<"std::string c'tor is not OK!"<<std::endl;

    try {
        std::string d2 = "FGV";
        DnaSequence dna2(d2);
    }
    catch (std::invalid_argument e) {
        std::cout<< "invalid_argument catch successfully" <<std::endl;
    }
}

void testCopyCtor(){
    DnaSequence dna("GATC");
    if(strcmp(dna.getSeq(), "GATC") == 0)
        std::cout<<"copy c'tor is OK!"<<std::endl;
    else
        std::cout<<"copy c'tor is not OK!"<<std::endl;
}

void testAssignmentOperator(){
    DnaSequence dna1("GATCA");
    DnaSequence dna2("CGTTGGACGA");
    dna1 = dna2;
    if(dna1 == "CGTTGGACGA")
        std::cout<<"operator = is OK!"<<std::endl;
    else
        std::cout<<"operator = is not OK!"<<std::endl;
}

void testOperatorBracket(){
    char d[] = {"CTGCACGA"};
    DnaSequence dna(d);
    bool isValid = true;
    if (dna[1] != d[1]) {
        isValid = false;
    }
    dna[3] = 'T';
    if (dna != "CTGTACGA") {
        isValid = false;
    }

    d[0] = dna[7];
    if (strcmp(d ,"ATGCACGA")) {
        isValid = false;
    }

    if (isValid)
        std::cout<<"operator[] is OK!"<<std::endl;
    else
        std::cout<<"operator[] is not OK!"<<std::endl;

    try {
        DnaSequence dna("CGTTGGACGA");
        dna[0] = 'X';
    }
    catch (std::invalid_argument e) {
        std::cout<< "invalid_argument catch successfully" <<std::endl;
    }
}

void testSliceDna(){
    DnaSequence dna("AGGCCCCTGTGA");
    DnaSequence sliceDna(dna.sliceDna(3,8));
    if(sliceDna == "CCCCT")
        std::cout<<"slicing is OK!"<<std::endl;
    else
        std::cout<<"slicing is not OK!"<<std::endl;
}

void testPairDna(){
    DnaSequence dna("AGGCCCCTGTGA");
    DnaSequence pairDna(dna.pairingDna());
    if(pairDna == "TCACAGGGGCCT")
        std::cout<<"pairing is OK!"<<std::endl;
    else
        std::cout<<"pairing is not OK!"<<std::endl;
}

void testFindSubDna(){
    DnaSequence dna("AGGCTGTGA");
    if(dna.findSubDna("TG") == 4)
        std::cout<<"finding is OK!"<<std::endl;
    else
        std::cout<<"finding is not OK!"<<std::endl;
}

void testCountSubDna(){
    DnaSequence dna("TGGCTGTGA");
    if(dna.countSubDna("TG") == 3)
        std::cout<<"counting is OK!"<<std::endl;
    else
        std::cout<<"counting is not OK!"<<std::endl;
}

void testFindAllSubDna(){
    DnaSequence dna("TGGCTGTGA");
    std::list<size_t> allSbDna = dna.findAllSubDna("TG");
    std::cout<<"// 0 4 6 //"<<":   ";
    for(std::list<size_t>::iterator iter = allSbDna.begin(); iter!= allSbDna.end(); iter++){
        std::cout<<*iter<<" ";
    }
    std::cout<<std::endl;

}

void testFindConsensusSequences(){
    DnaSequence dna("CATGAAAATGCCCTGAGT");
    std::list<DnaSequence> consensusSequences = dna.findConsensusSequences();
    for (std::list<DnaSequence>::iterator iter = consensusSequences.begin(); iter!=consensusSequences.end(); iter++){
        std::cout<< *iter <<std::endl;
    }
}

void testIReaderctor(){
    FileReader file("dnaFile.txt");
    DnaSequence dna1(file);
    bool isValid = true;
    if(strcmp(dna1.getSeq(), "TGCA")) {
        isValid = false;
    }
    KeyboardReader kb;
    DnaSequence dna2(kb);
    if(strcmp(dna2.getSeq(), "TGCA")){
        isValid = false;
    }
    if(isValid) {
        std::cout << "IReader c'tor is OK!" << std::endl;
    }
    else {
        std::cout << "IReader c'tor is not OK!" << std::endl;
    }
}

void testIWriter(){
    FileWriter file("fileWriter");
    ScreenWriter sw;
    DnaSequence d("CATGAAAATGCCCTGAGT");
    file.write(d.getSeq());
    sw.write(d.getSeq());
}
*/



int main() {
    std::cout<<"---main---"<<std::endl;
/*
    tetCharCtor();
    testStringCtor();
    testCopyCtor();
    testAssignmentOperator();
    testOperatorBracket();
    testSliceDna();
    testPairDna();
    testFindSubDna();
    testCountSubDna();
    testFindAllSubDna();
    testFindConsensusSequences();
    testIReaderctor();
    testIWriter();
*/
    KeyboardReader read;
    ScreenWriter write;
    System s;
    s.startApp(read, write);


    std::cout<< "end of program" <<std::endl;
    return 0;
}
