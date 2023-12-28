#ifndef _PERSONNAGES
#define _PERSONNAGES

#include "Personne.h"


class Personnages{
 
    public : 
    Personne personnages[7]; // tableau de tout les personnages du jeu

    /**
    * @brief Constructeur par défaut de Personnages : initialise tout les personnages.
    * @see Personnages::Personnages()
    */
    Personnages();

    /**
    * @brief Procédure permettant de remplir les dialogues des personnages
    * @see void Personnages::RemplirDialogue()
    */
    void RemplirDialogue();

    /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @see void Personnages::testRegression() const
    */
    void testRegression() const;
    
};

#endif