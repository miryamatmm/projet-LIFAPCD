#include <iostream>
#include <string.h>
#include <cassert>
#include "Personne.h"

using namespace std;

Personne::Personne(){
    positionB = -1;
    positionS = -1;
    idDialogue = 0;
    ordre = 0;
}

string Personne::getPrenom() const{
    return prenom;
}

Personne::Personne( string prenomC, string descriptionC)
{
    prenom=prenomC;
    description=descriptionC;
}

int Personne::getPositionB() const{
    return positionB;
}

int Personne::getPositionS() const{
    return positionS;
}

int Personne::getOrdre()const {
    return ordre;
}

void Personne::setPositionB(int idBNv){
    positionB = idBNv;
}

void Personne::setPositionS(int idSNv){
    positionS = idSNv;
}

void Personne::incrementeOrdre(){
    ordre++;
}

void Personne::testRegression() const{
    Personne p;

    //Constructeur par copie
    p=Personne("aleyno","lpb");
    assert(p.prenom=="aleyno");
    assert(p.description=="lpb");

    Personne p2;
    p2.prenom="mimi";
    //test de la fonction getPrenom()
    assert(p2.getPrenom()=="mimi");
    //test de la fonction getPlatonique()
}