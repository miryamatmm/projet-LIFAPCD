#ifndef _CARTE
#define _CARTE

#include <string>
#include <vector>

#include "Batiment.h"

enum batiments {nautibus, astree, bu, suaps, parc}; // nom des batiments pour faire stylé en vrai

class Carte{
    private :
    std::vector <Batiment> batiments; // tableau des batiments contenues dans la carte

    public :

    /**
    * @brief Constructeur par défaut de la Carte : initialise tous les bâtiments ainsi que leurs salles.
    * @see Carte::Carte():nbBatiments(5)
    */
    Carte();

    /**
    * @brief Accesseur : récupère le batiment d'identifiant passé en paramètre
    * @param [in] idB identifiant du batiment
    * @see Batiment Carte::getBatiment(int idB)
    * @retval Batiment (classe Batiment)
    */
    const Batiment& getBatiment(int idB) const;

    /**
    * @brief Accesseur : récupère le nombre de batiments de la carte
    * @see int Carte::getNbBats()
    * @retval int le nombre de batiments
    */
    int getNbBats() const;

    /**
    * @brief Mutateur : modifie l'accessibilité d'une salle
    * @see void Carte::setEstAccessibleS(int idB, int idS, bool estAccessibleNv)
    * @param [in] idB id du batiment dans lequel se trouve la salle
    * @param [in] idS id de la salle en question
    * @param [in] estAccessibleNv nouvelle valeur pour l'accessibilité de la salle
    */
    void setEstAccessibleS(int idB, int idS, bool estAccessibleNv);

    /**
    * @brief Mutateur : modifie l'accessibilité d'un batiment
    * @see void Carte::setEstAccessibleB(int idB, bool estAccessibleNv)
    * @param [in] idB id du batiment en question
    * @param [in] estAccessibleNv nouvelle valeur pour l'accessibilité du batiment
    */
    void setEstAccessibleB(int idB, bool estAccessibleNv);

    /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @see void Carte::testRegression() const
    */
   void testRegression() const;

};

#endif