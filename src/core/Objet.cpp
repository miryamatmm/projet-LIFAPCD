#include <iostream>
using namespace std;

#include "Objet.h"

Objet::Objet(){
    aEtePris=false;
    estVisible=false;
}


bool Objet::testPris(){
    return aEtePris;
}

bool Objet::testVisible(){
    return estVisible;
}

int Objet::getObjetpositionB(){
    return objetpositionB;
}

int Objet::getObjetpositionS(){
    return objetpositionS;
}

void Objet::setAEtePris(bool aEtePrisNv){
    aEtePris = aEtePrisNv;
}

void Objet::setEstVisible(bool estVisibleNv){
    estVisible = estVisibleNv;
}

void Objet::setObjetpositionB(int objetpositionBNv){
    objetpositionB = objetpositionBNv;
}

void Objet::setObjetpositionS(int objetpositionSNv){
    objetpositionS = objetpositionSNv;
}