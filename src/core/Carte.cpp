#include "Carte.h"
#include <cassert>
#include <iostream>
#include <string.h>
#include <cassert>

using namespace std;

Carte::Carte(){

    // DECLARATION DES BATIMENTS
    
    // NAUTIBUS === 0
    batiments.push_back( Batiment("Nautibus",0,true,nautibus) );

    // SALLES DE NAUTIBUS
    batiments[nautibus].ajouterSalle("Couloir principal",3,0,true,0);
    //bouton de couloir principal a faire
    batiments[nautibus].ajouterSalle("AML",1,0,false,1); //il faudra aller faire son adhésion à l'AML
    batiments[nautibus].ajouterSalle("TD10",1,0,true,2);
    batiments[nautibus].ajouterSalle("Table ronde",1,0,true,3);

    //ASTREE === 1
    batiments.push_back( Batiment("Astree",0,true,astree) );

    //SALLES DE ASTREE
    batiments[astree].ajouterSalle("Couloir principal",2,0,true,0);
    batiments[astree].ajouterSalle("Cafet",1,0,true,1); //il faudra faire sa carte étudiante
    batiments[astree].ajouterSalle("Piano",1,0,false,2);
    batiments[astree].ajouterSalle("Toilettes",1,0,true,3); //chercher des serviettes

    //BU === 2
    batiments.push_back(Batiment("BU",0,true,bu));
     
    //SALLES DE LA BU
    batiments[bu].ajouterSalle("Couloir principal",3,0,true,0);
    batiments[bu].ajouterSalle("Toilettes",1,0,true,1); 
    batiments[bu].ajouterSalle("Salle informatique",1,0,true,2);
    batiments[bu].ajouterSalle("4eme etage",1,0,true,3);

    //SUAPS === 3
    batiments.push_back(Batiment("SUAPS",0,false,suaps));

    //SALLES DE SUAPS
    batiments[suaps].ajouterSalle("Entrée principale",2,0,true,0);
    batiments[suaps].ajouterSalle("Gymnase C",1,0,true,1); 
    batiments[suaps].ajouterSalle("Distributeur",1,0,true,2);
    batiments[suaps].ajouterSalle("Bureau",1,0,false,3); //tu veux changer de sport

    //PARC === 4
    batiments.push_back(Batiment("Parc",0,false,parc));

    //SALLES DE PARC
    batiments[parc].ajouterSalle("Entrée du parc",2,0,true,0);
    batiments[parc].ajouterSalle("Banc",1,0,true,1); 

}

const Batiment& Carte::getBatiment(int idB) const{
    assert(idB >= 0 || idB <= int (batiments.size())); //garde

    return batiments[idB];
}

int Carte::getNbBats() const{
    return batiments.size();
}

void Carte::setEstAccessibleS(int idB, int idS, bool estAccessibleNv){
  batiments[idB].salles[idS].estAccessibleS = estAccessibleNv;
}

void Carte::setEstAccessibleB(int idB, bool estAccessibleNv){
  batiments[idB].estAccessible = estAccessibleNv;
}


void Carte::testRegression() const{
    Carte c; 

    // ==== TEST DU CONSTRUCTEUR PAR DEFAUT =====

    assert(c.batiments[nautibus].getNom() == "Nautibus");
    assert(c.batiments[nautibus].getEstAccessible());

    assert(c.batiments[nautibus].getSalle(0).getNom() == "Couloir principal");
    assert(c.batiments[nautibus].getSalle(0).getNbPerso() == 0);
    assert(c.batiments[nautibus].getSalle(0).getEstAccessible());
    assert(c.batiments[nautibus].getSalle(0).getIdS() == 0);

    assert(c.batiments[nautibus].getSalle(1).getNom() == "AML");
    assert(c.batiments[nautibus].getSalle(1).getNbPerso() == 0);
    assert(c.batiments[nautibus].getSalle(1).getEstAccessible() == false);
    assert(c.batiments[nautibus].getSalle(1).getIdS() == 1);

    assert(c.batiments[nautibus].getSalle(2).getNom() == "TD10");
    assert(c.batiments[nautibus].getSalle(2).getNbPerso() == 0);
    assert(c.batiments[nautibus].getSalle(2).getEstAccessible());
    assert(c.batiments[nautibus].getSalle(2).getIdS() == 2);

    assert(c.batiments[nautibus].getSalle(3).getNom() == "Table ronde");
    assert(c.batiments[nautibus].getSalle(3).getNbPerso() == 0);
    assert(c.batiments[nautibus].getSalle(3).getEstAccessible());
    assert(c.batiments[nautibus].getSalle(3).getIdS() == 3);


    assert(c.batiments[astree].getNom() == "Astree");
    assert(c.batiments[astree].getEstAccessible());

    assert(c.batiments[astree].getSalle(0).getNom() == "Couloir principal");
    assert(c.batiments[astree].getSalle(0).getNbPerso() == 0);
    assert(c.batiments[astree].getSalle(0).getEstAccessible());
    assert(c.batiments[astree].getSalle(0).getIdS() == 0);

    assert(c.batiments[astree].getSalle(1).getNom() == "Cafet");
    assert(c.batiments[astree].getSalle(1).getNbPerso() == 0);
    assert(c.batiments[astree].getSalle(1).getEstAccessible());
    assert(c.batiments[astree].getSalle(1).getIdS() == 1);

    assert(c.batiments[astree].getSalle(2).getNom() == "Piano");
    assert(c.batiments[astree].getSalle(2).getNbPerso() == 0);
    assert(c.batiments[astree].getSalle(2).getEstAccessible() == false);
    assert(c.batiments[astree].getSalle(2).getIdS() == 2);

    assert(c.batiments[astree].getSalle(3).getNom() == "Toilettes");
    assert(c.batiments[astree].getSalle(3).getNbPerso() == 0);
    assert(c.batiments[astree].getSalle(3).getEstAccessible());
    assert(c.batiments[astree].getSalle(3).getIdS() == 3);


    assert(c.batiments[bu].getNom() == "BU");
    assert(c.batiments[astree].getEstAccessible());

    assert(c.batiments[bu].getSalle(0).getNom() == "Couloir principal");
    assert(c.batiments[bu].getSalle(0).getNbPerso() == 0);
    assert(c.batiments[bu].getSalle(0).getEstAccessible());
    assert(c.batiments[bu].getSalle(0).getIdS() == 0);

    assert(c.batiments[bu].getSalle(1).getNom() == "Toilettes");
    assert(c.batiments[bu].getSalle(1).getNbPerso() == 0);
    assert(c.batiments[bu].getSalle(1).getEstAccessible());
    assert(c.batiments[bu].getSalle(1).getIdS() == 1);

    assert(c.batiments[bu].getSalle(2).getNom() == "Salle informatique");
    assert(c.batiments[bu].getSalle(2).getNbPerso() == 0);
    assert(c.batiments[bu].getSalle(2).getEstAccessible());
    assert(c.batiments[bu].getSalle(2).getIdS() == 2);

    assert(c.batiments[bu].getSalle(3).getNom() == "4eme etage");
    assert(c.batiments[bu].getSalle(3).getNbPerso() == 0);
    assert(c.batiments[bu].getSalle(3).getEstAccessible());
    assert(c.batiments[bu].getSalle(3).getIdS() == 3);


    assert(c.batiments[suaps].getNom() == "SUAPS");
    assert(c.batiments[suaps].getEstAccessible() == false);

    assert(c.batiments[suaps].getSalle(0).getNom() == "Entrée principale");
    assert(c.batiments[suaps].getSalle(0).getNbPerso() == 0);
    assert(c.batiments[suaps].getSalle(0).getEstAccessible());
    assert(c.batiments[suaps].getSalle(0).getIdS() == 0);

    assert(c.batiments[suaps].getSalle(1).getNom() == "Gymnase C");
    assert(c.batiments[suaps].getSalle(1).getNbPerso() == 0);
    assert(c.batiments[suaps].getSalle(1).getEstAccessible());
    assert(c.batiments[suaps].getSalle(1).getIdS() == 1);

    assert(c.batiments[suaps].getSalle(2).getNom() == "Distributeur");
    assert(c.batiments[suaps].getSalle(2).getNbPerso() == 0);
    assert(c.batiments[suaps].getSalle(2).getEstAccessible());
    assert(c.batiments[suaps].getSalle(2).getIdS() == 2);

    assert(c.batiments[suaps].getSalle(3).getNom() == "Bureau");
    assert(c.batiments[suaps].getSalle(3).getNbPerso() == 0);
    assert(c.batiments[suaps].getSalle(3).getEstAccessible() == false);
    assert(c.batiments[suaps].getSalle(3).getIdS() == 3);

    assert(c.batiments[parc].getNom() == "Parc");
    assert(c.batiments[parc].getEstAccessible() == false);

    assert(c.batiments[parc].getSalle(0).getNom() == "Entrée du parc");
    assert(c.batiments[parc].getSalle(0).getNbPerso() == 0);
    assert(c.batiments[parc].getSalle(0).getEstAccessible());
    assert(c.batiments[parc].getSalle(0).getIdS() == 0);

    assert(c.batiments[parc].getSalle(1).getNom() == "Banc");
    assert(c.batiments[parc].getSalle(1).getNbPerso() == 0);
    assert(c.batiments[parc].getSalle(1).getEstAccessible());
    assert(c.batiments[parc].getSalle(1).getIdS() == 1);


    // ===== TEST DU GETBATIMENT ======

    assert(c.getBatiment(0).getEstAccessible() == c.batiments[0].getEstAccessible());
    assert(c.getBatiment(0).getNbSalles() == c.batiments[0].getNbSalles());
    assert(c.getBatiment(0).getNom() == c.batiments[0].getNom());
        
    assert(c.getBatiment(0).getSalle(0).getNom() == c.batiments[0].getSalle(0).getNom());
    assert(c.getBatiment(0).getSalle(0).getNbPerso() == c.batiments[0].getSalle(0).getNbPerso());
    assert(c.getBatiment(0).getSalle(0).getEstAccessible() == c.batiments[0].getSalle(0).getEstAccessible());
    assert(c.getBatiment(0).getSalle(0).getIdS() == c.batiments[0].getSalle(0).getIdS());

    assert(c.getBatiment(0).getSalle(1).getNom() == c.batiments[0].getSalle(1).getNom());
    assert(c.getBatiment(0).getSalle(1).getNbPerso() == c.batiments[0].getSalle(1).getNbPerso());
    assert(c.getBatiment(0).getSalle(1).getEstAccessible() == c.batiments[0].getSalle(1).getEstAccessible());
    assert(c.getBatiment(0).getSalle(1).getIdS() == c.batiments[0].getSalle(1).getIdS());

    assert(c.getBatiment(0).getSalle(2).getNom() == c.batiments[0].getSalle(2).getNom());
    assert(c.getBatiment(0).getSalle(2).getNbPerso() == c.batiments[0].getSalle(2).getNbPerso());
    assert(c.getBatiment(0).getSalle(2).getEstAccessible() == c.batiments[0].getSalle(2).getEstAccessible());
    assert(c.getBatiment(0).getSalle(2).getIdS() == c.batiments[0].getSalle(2).getIdS());

    assert(c.getBatiment(0).getSalle(3).getNom() == c.batiments[0].getSalle(3).getNom());
    assert(c.getBatiment(0).getSalle(3).getNbPerso() == c.batiments[0].getSalle(3).getNbPerso());
    assert(c.getBatiment(0).getSalle(3).getEstAccessible() == c.batiments[0].getSalle(3).getEstAccessible());
    assert(c.getBatiment(0).getSalle(3).getIdS() == c.batiments[0].getSalle(3).getIdS());


    // ==== TEST DU GETNBBAT ====

    assert(c.getNbBats() == int (c.batiments.size()));


    // ===== TEST DU SETESTACCESSIBLES =====

    c.setEstAccessibleS(0, 1, false);

    assert(!c.batiments[0].salles[1].estAccessibleS);

    // ===== TEST DU SETESTACCESSIBLEB =====
    
    c.setEstAccessibleB(3, true);

    assert(c.batiments[0].estAccessible);
}