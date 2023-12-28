#include "Jeu.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void Jeu::lireABC(const std::string& nomFichier, int &A, int &B, int &C) {
    static std::ifstream fichier(nomFichier);
    static int prochainEntier = 0;
    if (!fichier.is_open()) {
        fichier.open(nomFichier);
    }
    if (fichier >> A >> B >> C) {
        prochainEntier += 3;
        fichier.seekg(prochainEntier);
        std::cout << "Les valeurs lues sont : A = " << A << ", B = " << B << ", C = " << C << std::endl;
    } else {
        std::cerr << "Erreur : impossible de lire les entiers dans le fichier " << nomFichier << std::endl;
    }
}



void Jeu::RemplirQuete(){
    quetesJeu[0].setTitreQuete("Nouveau campus");
    //quetesJeu[0].setIdPerso(0, 1);
    quetesJeu[0].setNarration("Vous voulez integrer l'AML mais il faut khalass. Vous devez donc regler vos frais d'inscription de l'AML", 0);
    quetesJeu[0].setNarration("Oh non ! Vous avez perdu votre dossier d'inscription de l'AML!!", 1);
    quetesJeu[0].setNarration("Vous avez retrouve votre dossier, vous devez maintenant vous rendre a Nautibus TD10 pour finaliser votre inscription", 2);
    quetesJeu[0].setNarration("Vous avez maintentant debloquer l'AML, vous pouvez enfin y aller", 3);
    quetesJeu[0].setNarration("Vous etes fatigue ! Allez vous reposer au parc", 4);
    quetesJeu[0].setNarration("Allez faire genre de travailler a Nautibus, (pour les cameras)", 5);
    quetesJeu[0].setNarration("La peste vous a soulez allez chercher Oke pour la rendre encore plus jalouse" , 6);
    quetesJeu[0].setNarration("Allez regler vos compte avec la peste pour lui montrer qui est la boss" , 7);
    quetesJeu[0].setNarration("Vous vous sentez mal allez chercher du soutien emotionel" , 8);
    quetesJeu[0].setNarration("Vous avez trouve la cle usb mais elle a un mot de passe. Comment faire ?" , 9);
    quetesJeu[0].setNarration("La verite est retablie al hamdoulilah ! Ton honneur et ton argent sont sauves youpi." , 10);
    quetesJeu[0].setNarration("En fouillant dans la cle usb vous decouvrez une video de la peste avec un autre pelo" , 11);
    quetesJeu[0].setNarration("MOUAHAHAHAH j'ai bien poste la video pour que tout le monde la vois. Bien fait pour elle." , 12);
    quetesJeu[0].setNarration("Vous n'auriez pas du faire ca. Tout cet incident va etre note sur votre dossier et vous le regreterez plus tard..." , 13);
    quetesJeu[0].setObjetParId(2, 1, false, false, 0);
    quetesJeu[0].setObjetParId(2, 2, false, false, 1);
    //quetesJeu[0].setIdPerso(1, 4);

    quetesJeu[1].setTitreQuete("Le jeu");
    quetesJeu[1].setNarration("Aujourd'hui a lieu le jeu de piste organise par l'AML, rends toi a l'AML pour choisir ton binome",0);
    quetesJeu[1].setNarration("Bon, la oukhty n'est pas dispo, je crois qu'il va falloir aller voir d'autres personnes...",1);
    quetesJeu[1].setNarration("Tic tac, il va bien falloir faire un choix madame, va voir Meyer au parc",2);
    quetesJeu[1].setNarration("Allez retourne vite au parc, le jeu va commencer",3);
    quetesJeu[1].setObjetParId(2, 3, false, false, 0);
    quetesJeu[1].setObjetParId(0, 1, false, false, 1);
    quetesJeu[1].setObjetParId(1, 1, false, false, 2);
    quetesJeu[1].setObjetParId(4, 1, false, false, 3);
    quetesJeu[1].setObjetParId(3, 2, false, false, 4);
    quetesJeu[1].setNarration("Le premier est a un endroit calme pour travailler ou trouver son futur hlel",4);
    quetesJeu[1].setNarration("Le deuxieme est a un endroit rempli de puant #humour",5);
    quetesJeu[1].setNarration("Le troisieme est a un endroit ou le pain est en carton",6);
    quetesJeu[1].setNarration("Le quatrieme et dernier est a un endroit pour se reposer",7);
    quetesJeu[1].setNarration("L'ensemble affiche : Je suis souvent en metal, Je peux contenir une boisson gazeuse,Je suis souvent jetable.",8);
    quetesJeu[1].setNarration("Bravo, vous pouvez maintenant ramener la canette a l'AML pour gagner",9);
    quetesJeu[1].setNarration("Bien joue championne, j'espere que t'as bien profite avec ton crush",10);
    quetesJeu[1].setNarration("Merci d'avoir participe a ce petit jeu (nul) de l'AML bisous",11);
}

void Jeu::testRegression() const{

    Jeu j;
    // ==== TEST DE REMPLIRQUETE 

    j.RemplirQuete();

    assert(j.quetesJeu[0].getTitreQuete() == "Nouveau campus");
    assert(j.quetesJeu[0].getNarrationParId(0) == "Vous voulez integrer l'AML mais il faut khalass. Vous devez donc regler vos frais d'inscription de l'AML");
    assert(j.quetesJeu[0].getNarrationParId(1) == "Oh non ! Vous avez perdu votre dossier d'inscription de l'AML!!");
    assert(j.quetesJeu[0].getNarrationParId(2) == "Vous avez retrouve votre dossier, vous devez maintenant vous rendre a Nautibus TD10 pour finaliser votre inscription");
    assert(j.quetesJeu[0].getNarrationParId(3) == "Vous avez maintentant debloquer l'AML, vous pouvez enfin y aller");
    assert(j.quetesJeu[0].getObjetParId(0).getObjetpositionB() == 2);
    assert(j.quetesJeu[0].getObjetParId(0).getObjetpositionS() == 1);
    assert(j.quetesJeu[0].getObjetParId(0).testPris() == false);
    assert(j.quetesJeu[0].getObjetParId(0).testVisible() == false);
    

}

