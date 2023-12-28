#ifndef _QUETE
#define _QUETE

#include "Personnages.h"
#include "Objet.h"

#include <string>
#include <iostream>

using namespace std;

class Quete{
    private :
    
    int idPersonnages[5]; //tableau 1D des id des perssonages impliqués dans la quete
    string titreQuete; //titre de la quete
    string narration[100]; //tableau 1D des repliques du narrateur de la quete
    Objet objetsQuete[5]; //tableau 1D des objets impliqués dans la quete

    public:

    /**
    * @brief Constructeur par défaut de Quete : initialise estFinis
    * @see Quete::Quete()
    */
    Quete();

    bool estFinis; // booléen pour savoir si la quete est finis

    /**
    * @brief Mutateur : modifie le titre de la quete
    * @param [in] titreQ nouvelle valeur pour le titre de la quete
    * @see void Quete::setTitreQuete(string titreQ) 
    */
    void setTitreQuete(string titreQ);

    /**
    * @brief Accesseur : récupère le titre de la quete
    * @see string Quete::getTitreQuete()
    * @retval string le titre de la quete
    */
    string getTitreQuete();

    /**
    * @brief Mutateur : modifie l'id d'un personnage
    * @param [in] indice l'indice du personnage à modifier
    * @param [in] idP nouvelle valeur pour l'id du personnage
    * @see void Quete::setIdPerso(int indice, int idP) 
    */
    void setIdPerso(int indice, int idP);

    /**
    * @brief Accesseur : récupère la replique du narrateur en fonction de son id
    * @param [in] idNarration l'id de la replique du narrateur à récupèrer
    * @see string Quete::getNarrationParId(int idNarration)
    * @retval string la replique idNarration du narrateur
    */
    string getNarrationParId(int idNarration);

    /**
    * @brief Mutateur : modifie une replique du narrateur en fonction de son id
    * @param [in] NarrationNv nouvelle valeur pour la replique du narrateur
    * @param [in] idNarration l'id de la replique du narrateur à modifier
    * @see void Quete::setNarration(string NarrationNv, int idNarration)
    */
    void setNarration(string NarrationNv, int idNarration);

    /**
    * @brief Accesseur : récupère un objet en fonction de son id
    * @param [in] idObjet l'id de l'objet à récupèrer
    * @see string Quete::getObjetParId(int idObjet)
    * @retval Objet un objet impliqué dans la quete
    */
    Objet getObjetParId(int idObjet);

    /**
    * @brief Mutateur : modifie un objet en fonction de son id
    * @param [in] nouvelle valeur pour le batiment ou se trouve l'objet
    * @param [in] nouvelle valeur pour la salle ou se trouve l'objet
    * @param [in] aEtePris nouvelle valeur pour savoir si l'objet à été pris ou non
    * @param [in] estVisibleNv nouvelle valeur pour la visibilité de l'objet
    * @param [in] idObjet l'id de l'objet à modifier
    * @see void Quete::setObjetParId(int, int, bool aEtePris, bool estVisibleNv, int idObjet)
    */
    void setObjetParId(int ObjetpositionBNv, int ObjetpositionSNv, bool aEtePrisNv, bool estVisibleNv, int idObjet);


     /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @see void Quete::testRegression() const
    */
    void testRegression() const;

};

#endif