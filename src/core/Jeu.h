#ifndef _JEU
#define _JEU

#include "Quete.h"

#include <string>
#include <iostream>
#include <fstream>

class Jeu {

public :
    Quete quetesJeu[5]; //tableau 1D des quetes du jeu

    int queteEnCours;  //entier representant l'id de la quetes en cours 
    int idNarrationEnCours; //entier representant l'id narration qu'il faut afficher 

    Jeu(): idNarrationEnCours(-1){}
    
    /**
    * @brief Remplis le tableau de quetes
    * @see void Quete::RemplirQuete()
    */
    void RemplirQuete();

    void lireABC(const std::string &nomFichier, int &A, int &B, int &C);

    /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @param none
    * @see void Jeu::testRegression() const
    */
   void testRegression() const;
    
};

#endif