#include <iostream>
#include <cassert>

using namespace std;

#include "Joueuse.h"


Joueuse::Joueuse(){
    pseudo= "Soeurette";
    peau= noirP;
    fond=roseF;
    voile=noirV;
    positionB = 0;
    positionS = 0;
}

int Joueuse::getPositionB() const{
    return positionB;
}

int Joueuse::getPositionS() const{
    return positionS;
}

void Joueuse::setPositionB(int idBNv){
    positionB = idBNv;
}

void Joueuse::setPositionS(int idSNv){
    positionS = idSNv;
}

void Joueuse::testRegression() const{

    Joueuse j;

    assert(j.pseudo == "Soeurette");
    assert(j.peau == noirP);
    assert(j.fond == roseF);
    assert(j.voile == noirV);
    assert(j.positionB == 0);
    assert(j.positionS == 0);

    //test du getPositionB()
    assert(j.getPositionB() == j.positionB);

    //test du getPositionS()
    assert(j.getPositionS() == j.positionS);
}