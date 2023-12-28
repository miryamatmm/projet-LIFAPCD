#include <iostream>
#include <cassert>
#include "Salle.h"

using namespace std;

Salle::Salle(){
    nbBoutons = 0;
    nbPerso=0;
    estAccessibleS=false;
}

Salle:: Salle(const string& nomSNv, int nbBoutonsNv,int nbPersoNv,bool estAccessibleSNv,int idSNv){
    nomS = nomSNv;
    nbBoutons = nbBoutonsNv;
    nbPerso = nbPersoNv;
    estAccessibleS = estAccessibleSNv;
    idS = idSNv;
}

Salle::~Salle(){

}

const string& Salle::getNom() const{
    return nomS;
}


int Salle::getNbPerso() const{
    return nbPerso;
}

bool Salle::getEstAccessible() const{
    return estAccessibleS;
}

int Salle::getIdS() const{
    return idS;
}


void Salle::testRegression() const{
    Salle salle1;

    //test du constructeur par défaut

    //assert(salle1); test bouton ??
    assert(salle1.nbBoutons == 0);
    assert(salle1.nbPerso == 0);
    assert(salle1.estAccessibleS == false);

    //test du constructeur par copie
    Salle salle2("mimilasouris",2,3,true,0);;
    assert(salle2.nomS == "mimilasouris");
    //assert(salle2.nbBoutons == 2);
    assert(salle2.nbPerso == 3);
    assert(salle2.estAccessibleS == true);
    assert(salle2.idS == 0);

    //test de la fonction getNom
    assert(salle2.getNom() == "mimilasouris");

    //test de la fonction getNbBoutons
    //assert(salle2.getNbBoutons() == 2);

    //test de la fonction getNbPerso
    assert(salle2.getNbPerso() == 3);

    //test de la fonction getEstAccessible
    assert(salle2.getEstAccessible() == true);

    //test de la procédure ajouterBouton

}