#ifndef _AFFICHAGE
#define _AFFICHAGE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
//#include <SDL2_mixer.h>

#include "../core/Jeu.h"
#include "../core/Menu.h"

enum boutonS {couloir, aml, td10, tableRonde, cafet, piano, toilettesA, toilettesB, salleInfo, etage4, gymnaseC, distributeur, bureau, banc };


class Image {

private:

    SDL_Surface * m_surface;
    SDL_Texture * m_texture;
    bool aChange;

public:
    Image () ;
    ~Image();
    void chargerDepuisFichier (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void dessiner (SDL_Renderer * renderer, int x, int y, int w, int h);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf) ;
    void afficheImagePleinEcran(SDL_Renderer *renderer, const char* );
};



/**
    La classe gerant le jeu avec un affichage SDL
*/
class SDLJeu {

private :

	Jeu jeu;

    SDL_Window * window;
    SDL_Renderer * renderer;


    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    //Mix_Chunk * sound;
    //bool withSound;

    // Image im_boutons;
    // Image im_salle;
    Image imDebut;

    Image imMenu;
    //MENU
    Image imProfil;

    //PROFIL

    Image imPP;

    Image imJoueuse;

    Image imGVBPBF;
    Image imGVBPRF;
    Image imNVBPBF;
    Image imNVBPRF;

    Image imGVNPBF;
    Image imGVNPRF;
    Image imNVNPBF;
    Image imNVNPRF;


    // QUETES
    Image imQuetes1;
    Image imQuetes2;
    Image imQuetes3;

    Image imDialogues;
    Image imNarration;
    Image imFond;
    Image imFond2;
    Image imCoeur;

    // OBJETS 
    Image imObjet1;
    Image imObjet2;
    Image imP1;
    Image imP2;
    Image imP3;
    Image imP4;
    Image imObjet3;

    Image imCarte1;
    Image imCarte2;
    Image imCarte3;
    Image imCarte4;

    Image imSalle;

    // PERSONNAGES

    Image imPerso;

    Image imOke;
    Image imKarim;
    Image imAdam;
    
    Image imPeste;
    Image imChaima;
    Image imMeyer;
    Image imDesseree; 

    //crushs
    Image imCrushs;
    Image imCrush1;
    Image imCrush2;
    Image imCrush3;
    //filles
    Image imFilles;
    Image imFille1;
    Image imFille2;
    //profs
    Image imProfs;
    Image imProf1;
    Image imProf2;

    // BATIMENT NAUTIBUS
    Image imNautibus; // couloir principal
    Image imAML;
    Image imTD10;
    Image imTableRonde;
    //BATIMENT ASTREE
    Image imAstree;
    Image imCafet;
    Image imPiano;
    Image imToilettesA;
    //BATIMENT BU
    Image imBU;
    Image imToilettesB;
    Image imSalleInfo;
    Image im4eme;
    // BATIMENT SUAPS
    Image imSuaps; // couloir principal
    Image imBureau;
    Image imGymnase;
    Image imDistributeur;
    //BATIMENT PARC
    Image imParc;
    Image imBanc;

public :
    SDLJeu();
    ~SDLJeu();
    void dessinerImage(SDL_Renderer* renderer, int dimx, int dimy, const Menu& m, int bat, int salle, Image image);
    string getImageJoueuse(Voile voile, Peau peau, Couleur fond);
    void sdlAff (Menu &m, int bonneSalle, bool &suivant,int &idDialogue, bool &narration, bool objet, bool choixEp, boutonS entierB, int idObjet);
    void sdlDebut();
    bool clic(int x, int X, int y, int Y,const SDL_Event& events);
    bool  survol(int x, int X, int y, int Y, int mouseX, int mouseY);
    void gererClicSalle(int batiment, const SDL_Event& events, Menu &m, int x, int X, int y, int Y, int positionNv);
    void gererClicCouloir(int batiment,const SDL_Event& events, Menu &m, int position, int x, int X, int y, int Y);
    void choixMenu(ChoixMenu choix,const SDL_Event& events, Menu &m,int x, int X, int y, int Y);
    void gererClicVoile(Voile voile,const SDL_Event& events, Menu &m,int x, int X, int y, int Y);
    void gererClicPeau(Peau peau,const SDL_Event& events, Menu &m,int x, int X, int y, int Y);
    void gererClicFond(Couleur fond,const SDL_Event& events, Menu &m,int x, int X, int y, int Y);
    void gererClicBatiment(int batiment,const SDL_Event& events, Menu &m,int x, int X, int y, int Y);
    void choisirApparence(const Menu &m);
    void choisirSalle(const Menu &m, Image &imSalle);
    void choisirCategorie(Menu& m, const SDL_Event &events, int x, int X, int y, int Y, categorie categorieCh);
    void choisirPerso(Menu& m, const SDL_Event& events, const int x, const int X, const int y, const int Y,categorie categorieAct, persos persoCh);
    void sePromener(Menu &m, SDL_Event& events);
    void gererClicQuete(const SDL_Event& events, Menu &m,bool &choixEp);
    void affObjet(Menu &m, int idObjet, bool objet);
    void affPerso(const Menu &m, int bonneSalle);
    void lancerQuete(Menu &m, SDL_Event& events, int &bonneSalle, bool &narration, bool &objet, int &idObjet, bool &choixEp, int choix);
    void verifierBonneSalle(const Menu &m, int idPersonne, int &bonneSalle);
    void affDialogue(const Menu &m, int idPersonne, int idDialogue);
    void gererClicDialogues(const Menu &m, SDL_Event& events, int &rep, bool &suivant, int &choix);
    void gererClicNarration(const Menu &m, SDL_Event& events, bool &narration);
    void gererClicObjet(Menu &m, SDL_Event& events, bool &objet, int idObjet);
    void gererSurvol(Menu &m,const int x, const int X, const int y, const int Y, int mouseX, int mouseY, boutonS &entierB, boutonS entierNv);
    void verifierCondition(Menu &m, int idPersonneC,int idPersonne,  int idDialogue, int idNarration, int idB, int idS, int &bonneSalle);
    void verifierCondition2(Menu &m, int idPersonneC,int idPersonne,  int idDialogueC, int idDialogue, int idNarration, int idB, int idS, int &bonneSalle);
    void verifierCondition3(Menu &m, int idPersonneC,int idPersonneC2,  int idDialogueC, int idDialogueC2, int idPersonne, int idNarration, int idB, int idS, int &bonneSalle);
    void verifierNarration(Menu &m, int idPersonne, int idDialogue, int idNarration, int idB, int idS, bool &narration);
    void verifierNarration2(Menu &m, bool objet, int idNarration, int idB, int idS, bool &narration);
    void verifierObjet(Menu &m, bool &objet, int &idObjet, int idNarration, int idObjetNv);
    void verifierObjet2(Menu &m, bool &objet, int &idObjet, int idNarration, int idObjetNv, int idPersonne, int idDialogue);
    void gereraffBouton(Menu &m, int x, int y, boutonS entierB, boutonS test,string nom,int idB, int idS);
    void updateJaugeAmour(Menu& m, int idPersonne, int rep);
    void updateJaugeAmour(Menu& m, int idPersonne, int rep, int& A, int &B, int &C);
    void affDialogues(Menu& m, bool &suivant, int &bonneSalle);
    void affNarration(Menu& m, bool &narration);
    void affJaugePerso(const Menu &m, int idPerso);
    void affBouton(Menu &m, string afficher, int x, int y, int idB, int idS);
    void affJauge(const Menu &m, int bonneSalle);
    void sdlBoucle ();
    // void sdlAff ();


};

#endif
