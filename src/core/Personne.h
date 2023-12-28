#ifndef _PERSONNE
#define _PERSONNE

//#include "Salle.h"
#include "Jauge.h"
#include <string>
#include <iostream>
using namespace std;

const int TAILLE = 1000;


class Personne{
    private : 
        string prenom; // prenom du personnages
        int positionB; // id du batiment ou se trouve le personnage
        int positionS; // id de la salle ou se trouve le personnage
        int ordre; // ordre des dialogues
    public :
    string description; // description d'un personnage
    string dialogues[TAILLE][4]; // dialogues d'un personnage
    int idDialogue; // id du dialogue en cours d'un personnage


    Jauge jauge_amour; // jauge d'affinité d'un personnage


    /**
    * @brief Constructeur par défaut de Personne : initialise la position, l'idDialogue et l'ordre.
    * @see Personne::Personne()
    */
    Personne();

    /**
    * @brief Constructeur par copie de Personne : affecte un prenom et une description.
    * @see Personne::Personne( string prenomC, string descriptionC)
    * @param [in] prenomC prenom d'un personnage
    * @param [in] descriptionC description d'un personnage
    */
    Personne( string prenomC, string descriptionC);

    /**
    * @brief Accesseur : récupère le prenom d'un personnage
    * @see string Personne::getPrenom() const
    * @retval string
    */
    string getPrenom() const;

    /**
    * @brief Accesseur : récupère l'id du batiment ou se trouve un personnage
    * @see int Personne::getPositionB() const
    * @retval int
    */
    int getPositionB() const;

    /**
    * @brief Accesseur : récupère l'id de la salle ou se trouve un personnage
    * @see int Personne::getPositionS() const
    * @retval int
    */
    int getPositionS() const;

    /**
    * @brief Accesseur : récupère l'ordre de dialogue d'un personnage
    * @see int Personne::getOrdre() const
    * @retval int
    */
    int getOrdre() const;

    /**
    * @brief Mutateur : modifie l'id du batiment ou se trouve un personnage
    * @see void Personne::setPositionB(int idBNv)
    * @param [in] idBNv nouveau id de batiment 
    */
    void setPositionB(int idBNv);

    /**
    * @brief Mutateur : modifie l'id de la salle ou se trouve un personnage
    * @see void Personne::setPositionS(int idSNv)
    * @param [in] idSNv nouveau id de salle
    */
    void setPositionS(int idSNv);

    /**
    * @brief Mutateur : incremente l'ordre de 1
    * @see void Personne::incrementeOrdre()
    */
    void incrementeOrdre();

     /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @see void Personne::testRegression() const
    */
    void testRegression() const;
    
};

#endif