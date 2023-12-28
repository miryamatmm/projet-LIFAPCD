#ifndef _BATIMENT
#define _BATIMENT

#include "Salle.h"
#include <string>
#include <vector>

/**
 @mainpage ♥️♥️ Bienvenue sur la page de documentation de Amour Salé ♥️♥️
 @section Présentation
 Amour Salé est un jeu de romance où vous pouvez incarner un personnage dans un univers lycéen rempli d'émotions fortes, de flirt et de romance. Inspiré par le célèbre jeu "Amour Sucré", Amour Salé vous permet de créer votre propre personnage et de le guider à travers une aventure passionnante.

Dans le jeu, vous pourrez choisir votre propre histoire et les actions de votre personnage qui influenceront les relations que vous développez avec les différents personnages. Vous devrez faire face à de nombreux dilemmes et prendre des décisions importantes qui affecteront le déroulement de l'histoire.

De plus, vous pouvez personnaliser votre personnage, tout en interagissant avec d'autres personnages charmants. Que vous cherchiez l'amour, l'amitié ou simplement à vous amuser. Amour Salé vous permet de vivre une expérience immersive et romantique dans un monde virtuel.

Préparez-vous à des intrigues amoureuses palpitantes, des événements spéciaux et des surprises dans ce jeu passionnant et addictif. Rejoignez dès maintenant le monde merveilleux d'Amour Salé et laissez-vous emporter par cette aventure romantique pleine d'amour, de passion et de mystère.

 @section Auteures
 Les power rangers se sont réunis pour créer ce magnifique projet, en espérant qu'il vous plaira.
*/

class Batiment{
    private :
        std::string nom; // le nom du batiment
        int idSDefaut; // l'identifiant de la salle par défaut du bâtiment
        int idB; // l'identifiant du bâtiment
    public : 
    std::vector<Salle> salles; // le tableau des salles contenues dans le batiment
    bool estAccessible; // pour savoir si le batiment est accessible

    /**
    * @brief Constructeur par copie de la classe Batiment 
    * @param [in] nomC nom du batiment 
    * @param [in] nbSalleC nombre de salles dans le batiment
    * @param [in] idSDefautC ah jsp fraté demande a mimi
    * @param [in] estAccessibleC ah jsp my bro demande a mimi
    * @see Batiment::Batiment(string nomC, int nbSalle, int idSDefault, bool estAccessibleC, int idBC)
    */
    Batiment(std::string nomC, int idSDefautC, bool estAccessibleC, int idBC);


    /**
    * @brief Accesseur : récupère le nom du batiment
    * @see string Batiment::getNom()
    * @retval string le nom du batiment
    */
    const std::string& getNom() const;

    /**
    * @brief Accesseur : récupère la salle de l'identifiant de salle passé en paramètre
    * @param [in] idS
    * @see Salle Batiment::getSalle(int idS)
    * @retval Salle (classe Salle)
    */
    const Salle& getSalle(int idS) const;

    /**
    * @brief Accesseur : récupère le nombre de salle du batiment
    * @param none
    * @see int Batiment::getNbSalles()
    * @retval int le nombre de salle
    */
    int getNbSalles() const;

    /**
    * @brief Accesseur : récupère l'accessibilité de la salle
    * @param none
    * @see bool Batiment::getEstAccessible()
    * @retval bool l'accessibilité de la salle
    */
    bool getEstAccessible() const;

    /**
    * @brief ajoute une Salle au batiment
    * @param [in] nomS le nom de la salle
    * @param [in] nbBoutons le nombre de boutons de la salle
    * @param [in] nbPerso le nombre de personnages présents dans la salle
    * @param [in] estAccesible pour savoir si la salle est accessible ou non
    * @param [in] idS l'identifiant de la salle
    * @see void Batiment::ajouterSalle(const std::string& nomSalle, int nbBoutons,int nbPerso,bool estAccessibleS, int idS)
    */
    void ajouterSalle(const std::string& nomS, int nbBoutons,int nbPerso,bool estAccessibleS,int idS);

    /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @see void Batiment::testRegression() const
    */
   void testRegression() const;

};

#endif