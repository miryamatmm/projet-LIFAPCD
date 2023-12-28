#ifndef _MENU
#define _MENU


//#include "Bouton.h"
#include "Carte.h"
#include "Personnages.h"
#include "Joueuse.h"
#include "Jeu.h"

enum ChoixMenu {carte, salle, profile, quitter, quetes, personnages, sauvegarder, rien, debut}; // les differents choix que le menu offre
enum categorie{rienC, crushs, filles, profs}; // les differentes categories de personnages
enum persos{rienP,castiel, adam, karim, chaima, peste, elodie, alexandre}; // les differents nom des personnages

class Menu{
    private :
        ChoixMenu choixMenu; // les choix du menu

    public : 
    categorie categorieChoisie; // la categorie de personnages choisie 
    persos persoChoisi; // le personnage choisi
    Joueuse joueuse; // la joueuse 
    Carte carte; // la carte
    Personnages p; // les personnages
    Jeu j; // le jeu

    /**
    * @brief Constructeur par défaut du Menu : initialise toutes les données, remplis les quetes (dialogues) et le jeu (narration et objet).
    * @see Menu::Menu()
    */
    Menu();

    /**
    * @brief Accesseur : récupère les choix du menu
    * @see ChoixMenu Menu::getChoixMenu() const
    * @retval ChoixMenu (enum)
    */
    ChoixMenu getChoixMenu() const;

     /**
    * @brief Mutateur : modifie les choix du menu
    * @see void Menu::setChoixMenu(ChoixMenu choixMenuNv)
    * @param [in] choixMenuNv nouveau choix 
    */
    void setChoixMenu(ChoixMenu choixMenuNv);

     /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @see void Menu::testRegression() const
    */
    void testRegression() const;
};

#endif

