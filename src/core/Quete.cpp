#include "Quete.h"

#include <string>
#include <iostream>
#include <cassert>
using namespace std;

Quete::Quete(){
    estFinis = false;
}
    
void Quete::setTitreQuete(string titreQ){
    titreQuete = titreQ;
}

void Quete::setIdPerso(int indice, int idP){
    idPersonnages[indice] = idP;
}

string Quete::getTitreQuete(){
    return titreQuete;
}

string Quete::getNarrationParId(int idNarration){
    return narration[idNarration];
}

void Quete::setNarration(string NarrationNv, int idNarration){
    narration[idNarration] = NarrationNv;
}

Objet Quete::getObjetParId(int idObjet){
    return objetsQuete[idObjet];
}

void Quete::setObjetParId(int ObjetpositionBNv, int ObjetpositionSNv, bool aEtePrisNv, bool estVisibleNv, int idObjet){
    objetsQuete[idObjet].setObjetpositionS(ObjetpositionSNv);
    objetsQuete[idObjet].setObjetpositionB(ObjetpositionBNv);
    objetsQuete[idObjet].setAEtePris(aEtePrisNv);
    objetsQuete[idObjet].setEstVisible(estVisibleNv);
}

void Quete::testRegression() const{
    Quete q;

    //test get et set titre
    q.setTitreQuete("prouthihi");
    assert(q.getTitreQuete()=="prouthihi");

    //astaghfirullah le reste du test j'y reviens apres -aleyno

}