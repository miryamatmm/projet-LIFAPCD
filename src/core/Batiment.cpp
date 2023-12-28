#include "Batiment.h"
#include <iostream>
#include <cassert>
#include <string.h>
 
using namespace std;

Batiment::Batiment(string nomC, int idSDefautC, bool estAccessibleC, int idBC){
    nom = nomC;
    idSDefaut = idSDefautC;
    estAccessible = estAccessibleC;
    idB = idBC;

}

const string& Batiment::getNom() const {
    return nom;
}

const Salle& Batiment::getSalle(int idS) const{
    return salles[idS]; 
}

int Batiment::getNbSalles() const{
    return salles.size();
}

bool Batiment::getEstAccessible() const{
    return estAccessible;
}

void Batiment::ajouterSalle(const std::string& nomS, int nbBoutons,int nbPerso,bool estAccessibleS, int idS){
    salles.push_back( Salle(nomS,nbBoutons,nbPerso,estAccessibleS,idS) );
}

void Batiment::testRegression() const{   
    //=== TEST CONSTRUCTEUR PAR COPIE ==== 
    Batiment b("prout",3,true,0);
    assert(b.nom=="prout");
    assert(b.idSDefaut==3);
    assert(b.estAccessible==true);
    assert(b.idB == 0);

    //==== TEST DE LA FONCTION GETNOM =====
    assert(b.getNom() == "prout");

    //==== TEST DE LA FONCTION GETESTACCESSIBLE =====
    assert(b.getEstAccessible());

    //==== TEST DE LA FONCTION GETSALLE =====
    //==== TEST DE LA FONCTION AJOUTERSALLE =====
    b.ajouterSalle("Salle 1", 10, 20, true, 0);
    b.ajouterSalle("Salle 2", 5, 10, false, 1);

    const Salle& s1 = b.getSalle(0);
    assert(s1.getNom() == "Salle 1");
    assert(s1.getEstAccessible() == true);
    assert(s1.getIdS() == 0);

    //==== TEST DE LA FONCTION GETNBSALLLE =====
    assert(b.getNbSalles() == 2);

}