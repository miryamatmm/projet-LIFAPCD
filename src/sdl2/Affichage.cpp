#include "Affichage.h"
#include <cassert>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstdlib> // pour rand() et srand()
#include <ctime> // pour time()

const int dimx = 1100;
const int dimy = 733;

using namespace std;

// ============= CLASS IMAGE =============== //

Image::Image () : m_surface(nullptr), m_texture(nullptr), aChange(false) {
}

Image::~Image()
{
    if(m_surface) SDL_FreeSurface(m_surface);
    if(m_texture) SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    aChange = false;
}

//pour charger une image depuis un fichier
void Image::chargerDepuisFichier (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
    SDL_FreeSurface(m_surface);
    m_surface = nullptr;
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::dessiner (SDL_Renderer * renderer, int x, int y, int w, int h) {
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;
    SDL_RenderCopy(renderer,m_texture,nullptr,&r);
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}

// ============= CLASS SDLJEU =============== //

SDLJeu::SDLJeu(){
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "Erreur lors de l'initialisation de la SDL_image : " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // Creation de la fenetre
    window = SDL_CreateWindow("Amour Salé", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // FONTS
    font = TTF_OpenFont("data/quetes/AnonymousPro-Regular.ttf",50);
    if (font == nullptr)
        font = TTF_OpenFont("../data/AnonymousPro-Regular.ttf",50);
    if (font == nullptr) {
            cout << "Failed to load AnonymousPro-Regular.ttf! SDL_TTF Error: " << TTF_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}        	
    
    font_color.r = 255;
    font_color.g = 102;
    font_color.b = 197;


    // IMAGES

    // ==== DEBUT ====

    imDebut.chargerDepuisFichier("./data/autre/cine.png", renderer);

    // ==== MENU ====
    imMenu.chargerDepuisFichier("./data/autre/menu.png",renderer);

    imProfil.chargerDepuisFichier("./data/profil/profil.png",renderer);

    // QUETES 
    imQuetes1.chargerDepuisFichier("./data/quetes/quetes1.png",renderer);
    imQuetes2.chargerDepuisFichier("./data/quetes/quetes2.png",renderer);
    imQuetes3.chargerDepuisFichier("./data/quetes/quetes3.png",renderer);
    imDialogues.chargerDepuisFichier("./data/quetes/dialogues.png",renderer);
    imNarration.chargerDepuisFichier("./data/quetes/narration.png", renderer);
    imFond.chargerDepuisFichier("./data/quetes/fond.png", renderer);
    imFond2.chargerDepuisFichier("./data/quetes/fond2.png", renderer);
    imCoeur.chargerDepuisFichier("./data/quetes/coeur.png",renderer);

    // OBJETS
    imObjet1.chargerDepuisFichier("./data/quetes/objet1.png", renderer);
    imObjet2.chargerDepuisFichier("./data/quetes/objet2.png", renderer);
    imP1.chargerDepuisFichier("./data/quetes/p1.png", renderer);
    imP2.chargerDepuisFichier("./data/quetes/p2.png", renderer);
    imP3.chargerDepuisFichier("./data/quetes/p3.png", renderer);
    imP4.chargerDepuisFichier("./data/quetes/p4.png", renderer);
    imObjet3.chargerDepuisFichier("./data/quetes/coca.png", renderer);

    imOke.chargerDepuisFichier("./data/persos/okechukwu_lumumba.png", renderer);
    imKarim.chargerDepuisFichier("./data/persos/karim.png", renderer);
    imAdam.chargerDepuisFichier("./data/persos/adam.png", renderer);

    imPeste.chargerDepuisFichier("./data/persos/laPeste.png", renderer);
    imChaima.chargerDepuisFichier("./data/persos/chaima.png", renderer);
    imMeyer.chargerDepuisFichier("./data/persos/meyer.png", renderer);
    imDesseree.chargerDepuisFichier("./data/persos/desseree.png", renderer);

    imCarte1.chargerDepuisFichier("./data/carte/carte1.png",renderer);
    imCarte2.chargerDepuisFichier("./data/carte/carte2.png",renderer);
    imCarte3.chargerDepuisFichier("./data/carte/carte3.png",renderer);
    imCarte4.chargerDepuisFichier("./data/carte/carte4.png",renderer);

    imPerso.chargerDepuisFichier("./data/description/personnages.png",renderer);

    // ==== PROFIL ====

    imGVBPBF.chargerDepuisFichier("./data/apparence/GVBPBF.png", renderer);
    imGVBPRF.chargerDepuisFichier("./data/apparence/GVBPRF.png", renderer);
    imNVBPBF.chargerDepuisFichier("./data/apparence/NVBPBF.png", renderer);
    imNVBPRF.chargerDepuisFichier("./data/apparence/NVBPRF.png", renderer);

    imGVNPBF.chargerDepuisFichier("./data/apparence/GVNPBF.png", renderer);
    imGVNPRF.chargerDepuisFichier("./data/apparence/GVNPRF.png", renderer);
    imNVNPBF.chargerDepuisFichier("./data/apparence/NVNPBF.png", renderer);
    imNVNPRF.chargerDepuisFichier("./data/apparence/NVNPRF.png", renderer);

    imJoueuse = imNVNPRF;

    imPP.chargerDepuisFichier("./data/apparence/pp.png",renderer);

    // ==== PERSONNAGES ====


    //DESCRIPTIONS
    //crushs 
    imCrushs.chargerDepuisFichier("./data/description/personnages-crush.png",renderer);
    imCrush1.chargerDepuisFichier("./data/description/personnages-crush-castiel.png",renderer);
    imCrush2.chargerDepuisFichier("./data/description/personnages-crush-adam.png",renderer);
    imCrush3.chargerDepuisFichier("./data/description/personnages-crush-karim.png",renderer);
    //filles
    imFilles.chargerDepuisFichier("./data/description/personnages-filles.png",renderer);
    imFille1.chargerDepuisFichier("./data/description/personnages-filles-chaima.png",renderer);
    imFille2.chargerDepuisFichier("./data/description/personnages-fille-lapeste.png",renderer);
    //profs
    imProfs.chargerDepuisFichier("./data/description/personnages-profs.png",renderer);
    imProf1.chargerDepuisFichier("./data/description/personnages-profs-elodie.png",renderer);
    imProf2.chargerDepuisFichier("./data/description/personnages-profs-alexandre.png",renderer);

    // BATIMENTS DE CARTE

    // ===== NAUTIBUS ====
    imNautibus.chargerDepuisFichier("./data/salles/nautibus/nautibus-entree.png",renderer); 
    imAML.chargerDepuisFichier("./data/salles/nautibus/nautibus-aml.png",renderer);
    imTD10.chargerDepuisFichier("./data/salles/nautibus/nautibus-td10.png",renderer);
    imTableRonde.chargerDepuisFichier("./data/salles/nautibus/nautibus-tableronde.png",renderer);

    // ===== ASTREE ====
    imAstree.chargerDepuisFichier("./data/salles/astree/astree-entree.png",renderer);
    imCafet.chargerDepuisFichier("./data/salles/astree/astree-cafet.png",renderer);
    imPiano.chargerDepuisFichier("./data/salles/astree/astree-piano.png",renderer);
    imToilettesA.chargerDepuisFichier("./data/salles/astree/astree-toilettes.png",renderer);

    // ===== BU ====
    imBU.chargerDepuisFichier("./data/salles/bu/bu-entree.png",renderer);
    imToilettesB.chargerDepuisFichier("./data/salles/bu/bu-toilettes.png",renderer);
    imSalleInfo.chargerDepuisFichier("./data/salles/bu/bu-salleInfo.png",renderer);
    im4eme.chargerDepuisFichier("./data/salles/bu/bu-4eme.png",renderer);

    // ===== SUAPS ====
    imSuaps.chargerDepuisFichier("./data/salles/suaps/suaps-entree.png",renderer); // couloir principal
    imBureau.chargerDepuisFichier("./data/salles/suaps/suaps-bureau.png",renderer);;
    imGymnase.chargerDepuisFichier("./data/salles/suaps/suaps-gymnase.png",renderer);;
    imDistributeur.chargerDepuisFichier("./data/salles/suaps/suaps-distributeur.png",renderer);

    // ===== PARC ====
    imParc.chargerDepuisFichier("./data/salles/parc/parc-entree.png",renderer);
    imBanc.chargerDepuisFichier("./data/salles/parc/parc-banc.png",renderer);
}

SDLJeu::~SDLJeu () {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool SDLJeu::clic(int x, int X, int y, int Y,const SDL_Event& events){
    return (events.button.x>=x)&&(events.button.x<=X)&&(events.button.y>=y)&&(events.button.y<=Y);
}

bool SDLJeu::survol(int x, int X, int y, int Y, int mouseX, int mouseY){
     return ((mouseX>=x)&&(mouseX<=X)&&(mouseY>=y)&&(mouseY<=Y));
}

void SDLJeu::gererClicSalle(int batiment, const SDL_Event& events, Menu &m, int x, int X, int y, int Y, int positionNv) {
    if((m.joueuse.getPositionB() == batiment) && (m.joueuse.getPositionS() == 0)&&(m.carte.getBatiment(batiment).getSalle(positionNv).getEstAccessible())) {
        if(clic(x, X, y, Y, events)) {
            m.joueuse.setPositionS(positionNv);
        }
    }
}

void SDLJeu::gererClicCouloir(int batiment,const SDL_Event& events, Menu &m, int position, int x, int X, int y, int Y){
    if((m.joueuse.getPositionB() == batiment)&&(m.joueuse.getPositionS() == position)){
        if(clic(x,X,y,Y,events)) m.joueuse.setPositionS(0);
    }
}

void SDLJeu::choixMenu(ChoixMenu choix,const SDL_Event& events, Menu &m,int x, int X, int y, int Y){
    if(clic(x,X,y,Y,events))
    {
        m.setChoixMenu(choix);
        if(choix == rien){
            m.categorieChoisie = rienC;
            m.persoChoisi = rienP;
        }
    }
}

void SDLJeu::gererClicVoile(Voile voile,const SDL_Event& events, Menu &m,int x, int X, int y, int Y){
    if(clic(x,X,y,Y,events)){
        m.joueuse.voile = voile;
    }
}

void SDLJeu::gererClicPeau(Peau peau,const SDL_Event& events, Menu &m,int x, int X, int y, int Y){
    if(clic(x,X,y,Y,events)){
        m.joueuse.peau = peau;
    }
}

void SDLJeu::gererClicFond(Couleur fond,const SDL_Event& events, Menu &m,int x, int X, int y, int Y){
    if(clic(x,X,y,Y,events)){
        m.joueuse.fond = fond;
    }
}

void SDLJeu::gererClicBatiment(int batiment,const SDL_Event& events, Menu &m,int x, int X, int y, int Y){
    if(clic(x,X,y,Y,events)&&m.carte.getBatiment(batiment).getEstAccessible()){
        m.setChoixMenu(quetes);
        m.joueuse.setPositionB(batiment);
        m.joueuse.setPositionS(0);
    }
}

void SDLJeu::dessinerImage(SDL_Renderer* renderer, int dimx, int dimy, const Menu& m, int bat, int salle, Image image) {
    if ((m.joueuse.getPositionB() == bat) && (m.joueuse.getPositionS() == salle)) {
        image.dessiner(renderer, 0, 0, dimx, dimy);
    }
}
 
void SDLJeu::choisirApparence(const Menu &m){
    if (m.joueuse.voile == noirV){
        if (m.joueuse.peau == noirP){
            if (m.joueuse.fond == roseF){
                imJoueuse = imNVNPRF;
            } else if (m.joueuse.fond == blancF){
                imJoueuse = imNVNPBF;
            }
        } else if (m.joueuse.peau == beigeP){
            if (m.joueuse.fond == roseF){
                imJoueuse = imNVBPRF;
            } else if (m.joueuse.fond == blancF){
                imJoueuse = imNVBPBF;
            }
        }
    } else if (m.joueuse.voile == grisV){
        if (m.joueuse.peau == noirP){
            if (m.joueuse.fond == roseF){
                imJoueuse = imGVNPRF;
            } else if (m.joueuse.fond == blancF){
                imJoueuse = imGVNPBF;
            }
        } else if (m.joueuse.peau == beigeP){
            if (m.joueuse.fond == roseF){
                imJoueuse = imGVBPRF;
            } else if (m.joueuse.fond == blancF){
                imJoueuse = imGVBPBF;
            }
        }
    }
}

void SDLJeu::choisirSalle(const Menu &m, Image &imSalle){
        if (m.joueuse.getPositionB() == nautibus) {
            if (m.joueuse.getPositionS() == 0) {
                imSalle = imNautibus;
            }
            else if (m.joueuse.getPositionS() == 1) {
                imSalle = imAML;
            }
            else if (m.joueuse.getPositionS() == 2) {
                imSalle = imTD10;
            }
            else if (m.joueuse.getPositionS() == 3) {
                imSalle = imTableRonde;
            }
        }
        else if (m.joueuse.getPositionB() == astree) {
            if (m.joueuse.getPositionS() == 0) {
                imSalle = imAstree;
            }
            else if (m.joueuse.getPositionS() == 1) {
                imSalle = imCafet;
            }
            else if (m.joueuse.getPositionS() == 2) {
                imSalle = imPiano;
            }
            else if (m.joueuse.getPositionS() == 3) {
                imSalle = imToilettesA;
            }
        }
        else if (m.joueuse.getPositionB() == bu) {
            if (m.joueuse.getPositionS() == 0) {
                imSalle = imBU;
            }
            else if (m.joueuse.getPositionS() == 1) {
                imSalle = imToilettesB;
            }
            else if (m.joueuse.getPositionS() == 2) {
                imSalle = imSalleInfo;
            }
            else if (m.joueuse.getPositionS() == 3) {
                imSalle = im4eme;
            }
        }
        else if (m.joueuse.getPositionB() == suaps) {
            if (m.joueuse.getPositionS() == 0) {
                imSalle = imSuaps;
            }
            else if (m.joueuse.getPositionS() == 1) {
                imSalle = imGymnase;
            }
            else if (m.joueuse.getPositionS() == 2) {
                imSalle = imDistributeur;
            }
        }
        else if (m.joueuse.getPositionB() == parc) {
            if (m.joueuse.getPositionS() == 0) {
                imSalle = imParc;
            }
            else if (m.joueuse.getPositionS() == 1) {
                imSalle = imBanc;
            }
        }
}

void SDLJeu::choisirCategorie(Menu& m, const SDL_Event &events, int x, int X, int y, int Y, categorie categorieCh){
    if(clic(x, X, y, Y, events) && (m.categorieChoisie == rienC)) {
        m.categorieChoisie = categorieCh;
    }
}

void SDLJeu::choisirPerso(Menu& m, const SDL_Event& events, const int x, const int X, const int y, const int Y, categorie categorieAct, persos persoCh){
    if(clic(x, X,y, Y, events) && (m.categorieChoisie == categorieAct)) {
        m.persoChoisi = persoCh;
    }
}

void SDLJeu::gererClicQuete(const SDL_Event& events, Menu &m, bool &choixEp){
    if(clic(435,665,264,314,events)){
        m.j.queteEnCours = 1;
        choixEp = true;
    }else if(clic(435,665,385,437,events) && m.j.quetesJeu[0].estFinis ){
            m.j.queteEnCours = 2;
            choixEp = true;
        }else{
        //     if(clic(435,665,385,437,events) ){
        //     m.j.queteEnCours = 2;
        //     m.carte.setEstAccessibleS(0, 1, true);
        //     m.carte.setEstAccessibleB(4, true);
        //     m.j.queteEnCours = 2;
        //     m.p.personnages[0].idDialogue = 15 ;
        //     m.p.personnages[1].idDialogue = 9 ;
        //     m.p.personnages[2].idDialogue = 12 ;
        //     m.p.personnages[3].idDialogue = 12 ;
        //     m.p.personnages[4].idDialogue = 15 ;
        //     m.p.personnages[5].idDialogue = 3 ;
        //     m.p.personnages[6].idDialogue = 0;
        //     choixEp = true;
        // }
        }
}

void SDLJeu::sePromener(Menu &m, SDL_Event& events){
    choixMenu(carte,events,m,935,1025,40,100);
    // ===================== NAUTIBUS ========================
    if((m.joueuse.getPositionB() == nautibus)&&(m.joueuse.getPositionS() == 0)){
                        gererClicSalle(nautibus,events,m,410,465,475,535,1);
                        gererClicSalle(nautibus,events,m,780,830,465,515,2);
                        gererClicSalle(nautibus,events,m,670,730,645,705,3);
                    }
                    gererClicCouloir(nautibus,events,m,1,290,345,630,680);
                    gererClicCouloir(nautibus,events,m,2,930,985,320,370);
                    gererClicCouloir(nautibus,events,m,3,80,140,585,640);

    // ===================== ASTREE ========================

    if((m.joueuse.getPositionB() == astree)&&(m.joueuse.getPositionS() == 0)){
                        gererClicSalle(astree,events,m,125,180,460,513,1);
                        gererClicSalle(astree,events,m,725,775,355,405,2);
                        gererClicSalle(astree,events,m,855,910,375,430,3);
                    }
                    gererClicCouloir(astree,events,m,1,380,440,630,680);
                    gererClicCouloir(astree,events,m,2,520,580,610,660);
                    gererClicCouloir(astree,events,m,3,525,580,610,660);

    // ===================== BU ========================

    if((m.joueuse.getPositionB() == bu)&&(m.joueuse.getPositionS() == 0)){
                        gererClicSalle(bu,events,m,375,425,630,680,1);
                        gererClicSalle(bu,events,m,130,180,395,445,2);
                        gererClicSalle(bu,events,m,520,575,280,330,3);

                    }
                    gererClicCouloir(bu,events,m,1,480,535,625,680);
                    gererClicCouloir(bu,events,m,2,290,350,625,680);
                    gererClicCouloir(bu,events,m,3,460,515,630,680);

        // ===================== SUAPS ========================

        // ==== COULOIR PRINCIPAL ====

        if((m.joueuse.getPositionB() == suaps)&&(m.joueuse.getPositionS() == 0)){
                        gererClicSalle(suaps,events,m,1000,1055,525,575,1);
                        gererClicSalle(suaps,events,m,200,270,530,580,2);
                        gererClicSalle(suaps,events,m,600,660,530,580,3);
                    }
                    gererClicCouloir(suaps,events,m,1,960,1010,470,520);
                    gererClicCouloir(suaps,events,m,2,520,580,630,680);
                    gererClicCouloir(suaps,events,m,3,855,915,625,680);

        // ===================== PARC ========================

        // ==== COULOIR PRINCIPAL ====

        if((m.joueuse.getPositionB() == parc)&&(m.joueuse.getPositionS() == 0)){
                        gererClicSalle(parc,events,m,944,997,475,536,1);
                    }
                    gererClicCouloir(parc,events,m,1,753,815,283,351);
                
}

void SDLJeu::verifierBonneSalle(const Menu &m, int idPersonne, int &bonneSalle){
    int positionBPerso = m.p.personnages[idPersonne].getPositionB();
    int positionSPerso = m.p.personnages[idPersonne].getPositionS();
    if((m.joueuse.getPositionB() == positionBPerso)&&(m.joueuse.getPositionS() == positionSPerso)){
        bonneSalle = idPersonne;
    }
}

void SDLJeu::affDialogue(const Menu& m, int idPersonne, int idDialogue) {

        //cout<<"je rentre la "<<endl;
        string dialogues = m.p.personnages[idPersonne].dialogues[idDialogue][0] + "\n" + "\n" + "\n";
        for (int i = 1; i <= 3; i++) {
            dialogues += m.p.personnages[idPersonne].dialogues[idDialogue][i] + "\n" + "\n";
        }
        
        // Dessin de la boîte de dialogue
        imDialogues.dessiner(renderer, 15, 85, dimx-30, dimy-50);
        
        // Calcul des dimensions du texte
        int text_width = 0;
        int text_height = 0;
        TTF_SizeText(font, dialogues.c_str(), &text_width, &text_height);
        
        // Positionnement du texte dans la boîte de dialogue
        SDL_Rect positionTitre;
        positionTitre.x = 224;
        positionTitre.y = 515;
        positionTitre.w = 600;
        positionTitre.h = 180;
        
        // Rendu du texte dans la boîte de dialogue
        SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font, dialogues.c_str(), font_color, 3 * positionTitre.w);
        if (!surface) {
            std::cerr << "Erreur lors du rendu du texte : " << TTF_GetError() << std::endl;
            return;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture) {
            std::cerr << "Erreur lors de la création de la texture : " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
            return;
        }

        // IMPORTANT JE CROIS
        SDL_FreeSurface(surface);
        SDL_RenderCopy(renderer, texture, nullptr, &positionTitre);
        SDL_DestroyTexture(texture);

                
}

void SDLJeu::gererClicDialogues(const Menu &m, SDL_Event& events, int &rep, bool &suivant,int &choix){
    rep = -1; //entier qui represente quelle reponse on a cliqué
    suivant = false; //bool pour savoir si on passse au dialogue suivant
    if(clic(105, 140, 570, 600, events)){
        rep = 1;
        if(m.j.queteEnCours == 2 && m.p.personnages[6].idDialogue == 4){
            choix = rep;
        }
        suivant = true;
    }else if(clic(105, 140, 615, 645, events)){
        rep = 2;
        if(m.j.queteEnCours == 2 && m.p.personnages[6].idDialogue == 4){
            choix = rep;
        }
        suivant = true;
    }
    else if(clic(105, 140, 665, 695, events)){
        rep = 3;
        if(m.j.queteEnCours == 2 && m.p.personnages[6].idDialogue == 4){
            choix = rep;
        }
        suivant = true;
    } 
}

void SDLJeu::gererClicNarration(const Menu &m, SDL_Event& events, bool &narration){
    if(clic(945,1000,635, 695, events)){
        narration = false;
    }
}

void SDLJeu::gererClicObjet(Menu &m, SDL_Event& events, bool &objet, int idObjet){
    if(idObjet != -1){
        if(m.j.queteEnCours == 1){
            if(idObjet == 0){
                if(clic(190, 257, 416, 460, events)){
                    objet = false;
                    m.j.quetesJeu[0].getObjetParId(0).setAEtePris(true);
                }
            }
            if(idObjet == 1){
                if(clic(804, 840, 566, 598, events)){
                    cout<<"clic cle usb"<<endl;
                    objet = false;
                    m.j.quetesJeu[0].getObjetParId(1).setAEtePris(true);
                }
            }
        }
        if(m.j.queteEnCours == 2){
            if(idObjet == 0){
                if(clic(795, 835, 475, 515, events)){
                    cout<<"clic de post it 1"<<endl;
                    objet = false;
                    m.j.quetesJeu[1].getObjetParId(0).setAEtePris(true);
                }
            }
            if(idObjet == 1){
                if(clic(677, 724, 650, 695, events)){
                    objet = false;
                    m.j.quetesJeu[1].getObjetParId(1).setAEtePris(true);
                }
            }
            if(idObjet == 2){
                if(clic(50, 110, 513, 573, events)){
                    objet = false;
                    m.j.quetesJeu[1].getObjetParId(2).setAEtePris(true);
                }
            }
            if(idObjet == 3){
                if(clic(257, 303, 555, 601, events)){
                    objet = false;
                    m.j.quetesJeu[1].getObjetParId(3).setAEtePris(true);
                }
            }
            if(idObjet == 4){
                if(clic(930, 958, 497, 550, events)){
                    objet = false;
                    m.j.quetesJeu[1].getObjetParId(3).setAEtePris(true);
                }
            }
        }
    }
}

void SDLJeu::gererSurvol(Menu &m,const int x, const int X, const int y, const int Y, int mouseX, int mouseY, boutonS &entierB, boutonS entierNv){
    if(survol(x,X,y,Y,mouseX,mouseY)) entierB = entierNv;
}

void SDLJeu::gereraffBouton(Menu &m, int x, int y, boutonS entierB, boutonS test,string nom, int idB, int idS){
    if(entierB == test){
        affBouton(m,nom,x,y,idB,idS);
    }
}

void SDLJeu::updateJaugeAmour(Menu& m, int idPersonne, int rep, int& A, int &B, int &C){
    m.j.lireABC("./data/jauge.txt",A,B,C);
    if(idPersonne != -1){
        switch (rep) {
            case 1:
                m.p.personnages[idPersonne].jauge_amour.setAmour(A);
                    break;
            case 2:
                m.p.personnages[idPersonne].jauge_amour.setAmour(B);
                    break;
            case 3:
                m.p.personnages[idPersonne].jauge_amour.setAmour(C);
                    break;
            default:
                    break;
                }
    }
}

void SDLJeu::updateJaugeAmour(Menu &m, int idPersonne, int rep){
    if(idPersonne != -1){
        if(idPersonne == 4){
            switch (rep) {
            case 1:
                m.p.personnages[idPersonne].jauge_amour.setAmour(-5);
                    break;
            case 2:
                m.p.personnages[idPersonne].jauge_amour.setAmour(0);
                    break;
            case 3:
                m.p.personnages[idPersonne].jauge_amour.setAmour(-10);
                    break;
            default:
                    break;
                }
        }
        else{
            if(m.p.personnages[idPersonne].idDialogue % 3 == 0){
            switch (rep) {
                case 1:
                    m.p.personnages[idPersonne].jauge_amour.setAmour(-5); // RAND DE -5 A 0
                    break;
                case 2:
                    m.p.personnages[idPersonne].jauge_amour.setAmour(0); // RAND DE 6 A 8
                    break;
                case 3:
                    m.p.personnages[idPersonne].jauge_amour.setAmour(5); // RAND DE -15 A -10
                    break;
                default:
                    break;
                }
            }else if(m.p.personnages[idPersonne].idDialogue % 3 == 1){
                switch (rep) {
                    case 1:
                        m.p.personnages[idPersonne].jauge_amour.setAmour(0); // RAND DE 5 A 10
                        break;
                    case 2:
                        m.p.personnages[idPersonne].jauge_amour.setAmour(-5); // RAND DE 0 A 5
                        break;
                    case 3:
                        m.p.personnages[idPersonne].jauge_amour.setAmour(5); // RAND DE -20 A 0
                        break;
                    default:
                        break;
                    }
            }else if(m.p.personnages[idPersonne].idDialogue % 3 == 2){
                switch (rep) {
                    case 1:
                        m.p.personnages[idPersonne].jauge_amour.setAmour(5); // RAND DE 5 A 7
                        break;
                    case 2:
                        m.p.personnages[idPersonne].jauge_amour.setAmour(0); // RAND DE -5 A 0
                        break;
                    case 3:
                        m.p.personnages[idPersonne].jauge_amour.setAmour(-5); // RAND DE -25 A -20
                        break;
                    default:
                        break;
                    }
            }

            }
        }
}

void SDLJeu::affObjet(Menu &m, int idObjet, bool objet){
    if(idObjet != -1){
        bool aEtePris = m.j.quetesJeu[m.j.queteEnCours - 1].getObjetParId(idObjet).testPris();
        if(objet && !aEtePris){
            int positionBObjet = m.j.quetesJeu[m.j.queteEnCours -1].getObjetParId(idObjet).getObjetpositionB();
            int positionSObjet = m.j.quetesJeu[m.j.queteEnCours -1].getObjetParId(idObjet).getObjetpositionS();
            if(m.joueuse.getPositionB() == positionBObjet && m.joueuse.getPositionS() == positionSObjet){
                if(m.j.queteEnCours ==1){
                    if(idObjet == 0){
                        imObjet1.dessiner(renderer, 200, 426, 50, 50);
                    }else if(idObjet == 1){
                        imObjet2.dessiner(renderer, 803, 563, 50, 50);
                    }
                }
                if(m.j.queteEnCours == 2){
                    if(idObjet == 0){
                        imP1.dessiner(renderer, 792, 470, 50, 50);
                    }
                    if(idObjet == 1){
                        imP2.dessiner(renderer, 650, 650, 100, 56);
                    }
                    if(idObjet == 2){
                        imP3.dessiner(renderer, 40, 510, 80, 66);
                    }
                    if(idObjet == 3){
                        imP4.dessiner(renderer, 240, 550, 80, 71);
                    }
                    if(idObjet == 4){
                        imObjet3.dessiner(renderer, 930, 500, 30, 56);
                    }
                }
                }
            }
        }
    }

void SDLJeu::affPerso(const Menu &m, int bonneSalle){
    switch(bonneSalle){
        case 0 : 
            imPP.dessiner(renderer,0,0,dimx,dimy);
            imJoueuse.dessiner(renderer, 79, 38, 135, 135);
            imOke.dessiner(renderer, 322, 57, 350, 500);
            break;
        case 1 : 
            imPP.dessiner(renderer,0,0,dimx,dimy);
            imJoueuse.dessiner(renderer, 77, 35, 140, 140);
            imAdam.dessiner(renderer, 322, 57, 350, 500);
            break;
        case 2 : 
            imPP.dessiner(renderer,0,0,dimx,dimy);
            imJoueuse.dessiner(renderer, 75, 35, 140, 140);
            imKarim.dessiner(renderer, 322, 57, 350, 500);
            break;
        case 3 : 
            imPP.dessiner(renderer,0,0,dimx,dimy);
            imJoueuse.dessiner(renderer, 75, 35, 140, 140);
            imDesseree.dessiner(renderer, 322, 57, 350, 500);
            break;
        case 4 : 
            imPP.dessiner(renderer,0,0,dimx,dimy);
            imJoueuse.dessiner(renderer, 75, 35, 140, 140);
            imPeste.dessiner(renderer, 322, 57, 350, 500);
            break;
        case 5 : 
            imPP.dessiner(renderer,0,0,dimx,dimy);
            imJoueuse.dessiner(renderer, 75, 35, 140, 140);
            imChaima.dessiner(renderer, 322, 57, 350, 500);
            break;
        case 6 : 
            imPP.dessiner(renderer,0,0,dimx,dimy);
            imJoueuse.dessiner(renderer, 75, 35, 140, 140);
            imMeyer.dessiner(renderer, 322, 57, 350, 500);
            break;
        default: // aucun personnage à afficher
            break;

    }
}

void SDLJeu::verifierCondition(Menu &m, int idPersonneC, int idPersonne, int idDialogue, int idNarration, int idB, int idS, int &bonneSalle){
    if(m.j.idNarrationEnCours == idNarration && m.p.personnages[idPersonneC].idDialogue == idDialogue){
            m.p.personnages[idPersonne].setPositionB(idB);      
            m.p.personnages[idPersonne].setPositionS(idS);     
            verifierBonneSalle(m, idPersonne, bonneSalle);
        }
}

void SDLJeu::verifierCondition2(Menu &m, int idPersonneC,int idPersonne,  int idDialogueC, int idDialogue, int idNarration, int idB, int idS, int &bonneSalle){
    if(m.j.idNarrationEnCours == idNarration && m.p.personnages[idPersonne].idDialogue == idDialogue && m.p.personnages[idPersonneC].idDialogue == idDialogueC){
            m.p.personnages[idPersonne].setPositionB(idB);      
            m.p.personnages[idPersonne].setPositionS(idS);     
            verifierBonneSalle(m, idPersonne, bonneSalle);
        } 
}

void SDLJeu::verifierNarration(Menu &m, int idPersonne, int idDialogue, int idNarration, int idB, int idS, bool &narration){
     if(m.p.personnages[idPersonne].idDialogue  == idDialogue && m.joueuse.getPositionB() == idB && m.joueuse.getPositionS() == idS && m.j.idNarrationEnCours == idNarration){
            m.j.idNarrationEnCours = idNarration+1;
            narration= true;
        }
}

void SDLJeu::verifierNarration2(Menu &m, bool objet, int idNarration, int idB, int idS, bool &narration){
    if(!objet && m.joueuse.getPositionB() == idB && m.joueuse.getPositionS() == idS && m.j.idNarrationEnCours == idNarration){
            m.j.idNarrationEnCours = idNarration +1;
            narration = true; 
        }
}

void SDLJeu::verifierObjet(Menu &m, bool &objet, int &idObjet, int idNarration, int idObjetNv){
     if(m.j.idNarrationEnCours == idNarration){
            objet = true;
            idObjet = idObjetNv;
        }
}

void SDLJeu::verifierCondition3(Menu &m, int idPersonneC,int idPersonneC2,  int idDialogueC, int idDialogueC2, int idPersonne, int idNarration, int idB, int idS, int &bonneSalle){
    if(m.p.personnages[idPersonneC].idDialogue  == idDialogueC && m.p.personnages[idPersonneC2].idDialogue  == idDialogueC2 && m.j.idNarrationEnCours == idNarration){
            m.p.personnages[idPersonne].setPositionB(idB);      
            m.p.personnages[idPersonne].setPositionS(idS);     
            verifierBonneSalle(m, idPersonne, bonneSalle);
        }
}

void SDLJeu::verifierObjet2(Menu &m, bool &objet, int &idObjet, int idNarration, int idObjetNv, int idPersonne, int idDialogue){
    if(m.p.personnages[idPersonne].idDialogue == idDialogue && m.j.idNarrationEnCours == idNarration){
            objet = true;
            idObjet = idObjetNv;
        }
}

void SDLJeu::lancerQuete(Menu &m, SDL_Event& events, int &bonneSalle, bool &narration, bool &objet, int &idObjet, bool &choixEp, int choix){
    if(m.j.queteEnCours == 1){
        if(bonneSalle == -1 && !narration){
            sePromener(m, events);
        }

        // ===== NARRATION !!! =======
        if(m.joueuse.getPositionB() == 0 && m.joueuse.getPositionS() == 0 
            && m.p.personnages[0].idDialogue  == 0 && m.p.personnages[1].idDialogue  == 0){
                m.j.idNarrationEnCours = 0;
                narration = true;
        }

        if(m.joueuse.getPositionB() == 0 && m.joueuse.getPositionS() == 0 
            && m.p.personnages[0].idDialogue  == 3 && m.p.personnages[1].idDialogue  == 3
            && m.j.idNarrationEnCours == 0){
                m.j.idNarrationEnCours = 1;
                narration = true;
        }

        verifierNarration2(m,objet,1,2,0,narration);

        if(m.joueuse.getPositionB() == 0 && m.joueuse.getPositionS() == 0 && m.p.personnages[2].idDialogue  == 3 && m.j.idNarrationEnCours == 2){
            m.j.idNarrationEnCours = 3;
            narration = true;
            m.carte.setEstAccessibleS(0, 1, true);
        }

        if(m.joueuse.getPositionB() == 0 && m.joueuse.getPositionS() == 0 &&
            m.p.personnages[2].idDialogue  == 6 && m.j.idNarrationEnCours == 3){
            m.j.idNarrationEnCours = 4;
            narration = true;
            m.carte.setEstAccessibleB(4, true);
        }

        verifierNarration(m,3,3,4,4,0,narration);
        verifierNarration(m,4,3,5,0,0,narration);
        verifierNarration(m,0,6,6,0,0,narration);
        verifierNarration(m,4,9,7,0,0,narration);

        if(!objet && m.joueuse.getPositionB() == 2 && m.joueuse.getPositionS() == 0 && m.j.idNarrationEnCours == 8 
            && m.p.personnages[2].idDialogue == 9){
            m.j.idNarrationEnCours = 9;
            narration = true; 
        }

        verifierNarration(m,3,9,9,0,0,narration);

        if(m.joueuse.getPositionB() == 2 && m.joueuse.getPositionS() == 0 && m.j.idNarrationEnCours == 10
            && m.p.personnages[0].idDialogue == 12 && m.p.personnages[1].idDialogue == 9 && m.p.personnages[4].idDialogue == 12){
            m.j.idNarrationEnCours = 11;
            narration = true;
        }

        verifierNarration(m,2,12,11,0,0,narration);
        verifierNarration(m,3,12,12,0,0,narration);

        // ===== DIALOGUES !!! =====
        
        verifierCondition(m,0,0,0,0,0,2,bonneSalle);
        verifierCondition(m,1,1,0,0,0,3,bonneSalle);

        if(m.p.personnages[2].idDialogue == 0){
            verifierCondition3(m,0,1,3,3,2,2,0,2,bonneSalle);
        }

        if(m.carte.getBatiment(0).salles[1].estAccessibleS && m.j.idNarrationEnCours == 3 && m.p.personnages[2].idDialogue == 3){
            m.p.personnages[2].setPositionB(0);      
            m.p.personnages[2].setPositionS(1);     
            verifierBonneSalle(m, 2, bonneSalle);
        }

        if(m.carte.getBatiment(4).estAccessible && m.p.personnages[2].idDialogue == 6 && m.p.personnages[3].idDialogue == 0){
            m.p.personnages[3].setPositionB(4);      
            m.p.personnages[3].setPositionS(1);     
            verifierBonneSalle(m, 3, bonneSalle);
        }

        verifierCondition(m,4,4,0,5,0,1,bonneSalle);
        // verifierCondition(m,4,0,3,6,0,2,bonneSalle); normalement réglé
        verifierCondition2(m,4,0,3,3,6,0,2,bonneSalle);
        verifierCondition2(m,0,4,6,3,7,0,1,bonneSalle);
        verifierCondition2(m,4,3,6,3,7,1,1,bonneSalle);
        verifierCondition2(m,3,4,6,6,7,0,1,bonneSalle);
        verifierCondition(m,0,0,6,8,1,1,bonneSalle);
        verifierCondition(m,1,1,3,8,2,3,bonneSalle);
        verifierCondition2(m,1,2,6,6,8,0,1,bonneSalle);

        verifierCondition(m,5,5,0,9,0,3,bonneSalle);
        verifierCondition2(m,5,3,3,6,9,0,2,bonneSalle);
        verifierCondition(m,4,4,9,10,2,1,bonneSalle);
        verifierCondition(m,1,1,6,10,2,2,bonneSalle);
        verifierCondition(m,0,0,9,10,2,3,bonneSalle);
        verifierCondition(m,0,0,12,11,2,2,bonneSalle);
        verifierCondition2(m,0,2,15,9,11,0,1,bonneSalle);
        verifierCondition(m,4,4,12,12,0,2,bonneSalle);
        verifierCondition2(m,4,3,15,9,12,0,3,bonneSalle);

        // === OBJET !!! =====

        verifierObjet(m,objet,idObjet,1,0);
        verifierObjet2(m,objet,idObjet,8,1,2,9);

        //REMISE A ZERO A CHAQUE FIN DE DIALOGUE (ou incrementation)
        if((m.p.personnages[bonneSalle].idDialogue % 3) == 2) {
           m.p.personnages[bonneSalle].incrementeOrdre();
           m.p.personnages[bonneSalle].idDialogue ++;
           bonneSalle = -1;
        }
        
        // FIN DE LA QUETE 1 
        if(m.j.idNarrationEnCours == 13 && !narration){
            m.j.quetesJeu[0].estFinis = true;
            // REMISE A ZERO DES IDDIALOGUES POUR REJOUER LA QUETE PLUS TARD
            // for(int i = 0; i<= 6; i++){
            //     m.p.personnages[i].idDialogue = 0;
            // }
            m.j.idNarrationEnCours = -1;
            choixEp = false;
            cout<<m.j.idNarrationEnCours<<endl;
        }
    
    }
    if(m.j.queteEnCours == 2){
        if(bonneSalle == -1 && !narration){
            sePromener(m, events);
        }
        
        // ===== NARRATION !!! =======
        verifierNarration(m,6,0,-1,0,0,narration);
        verifierNarration(m,5,6,0,0,0,narration);
        verifierNarration(m,0,21,1,0,0,narration);

        if(choix == 1){
            verifierNarration(m,1,15,2,2,0,narration);
        }else if(choix == 2){
            verifierNarration(m,0,24,2,0,0,narration);
        }else if(choix == 3){
            verifierNarration(m,2,18,2,0,0,narration);
        }

        verifierNarration(m,6,9,3,4,0,narration);
        verifierNarration2(m,objet,4,2,0,narration);
        verifierNarration2(m,objet,4,2,0,narration);
        verifierNarration2(m,objet,5,0,0,narration);
        verifierNarration2(m,objet,6,1,0,narration);

        //on rend la carte accessible
        if(!objet && m.joueuse.getPositionB() == 4 && m.joueuse.getPositionS() == 0 && m.j.idNarrationEnCours == 7){
            m.j.idNarrationEnCours = 8;
            m.carte.setEstAccessibleB(3, true);
            narration = true; 
        }

        verifierNarration2(m,objet,8,3,0,narration);
        verifierNarration(m,6,12,9,4,0,narration);
        verifierNarration(m,4,21,10,0,0,narration);

        // ===== DIALOGUES !!! =====

        verifierCondition(m,6,6,0,0,0,1,bonneSalle);
        verifierCondition2(m,6,5,3,3,0,0,3,bonneSalle);
        verifierCondition2(m,5,4,6,15,1,0,1,bonneSalle);
        verifierCondition2(m,4,0,18,15,1,2,2,bonneSalle);
        verifierCondition2(m,0,1,18,9,1,1,1,bonneSalle);
        verifierCondition2(m,1,2,12,12,1,0,1,bonneSalle);
        verifierCondition2(m,2,0,15,18,1,0,2,bonneSalle);
        verifierCondition(m,6,6,3,2,4,1,bonneSalle);
        
        //fini avec ok c le moment du choix

        if(choix == 1){ //adam
            m.p.personnages[0].idDialogue = 27;
            m.p.personnages[2].idDialogue = 21;
            verifierCondition2(m,6,1,6,12,2,2,3,bonneSalle);
            verifierCondition(m,3,3,12,3,4,0,bonneSalle);
            verifierCondition2(m,3,6,15,6,3,4,1,bonneSalle);
            verifierCondition2(m,6,1,9,15,9,0,1,bonneSalle);

        }else if(choix == 2){ //oke
            m.p.personnages[1].idDialogue = 18;
            m.p.personnages[2].idDialogue = 21;
            verifierCondition2(m,6,0,6,21,2,0,2,bonneSalle);
            verifierCondition(m,3,3,12,3,4,0,bonneSalle);
            verifierCondition2(m,3,6,15,6,3,4,1,bonneSalle);
            verifierCondition2(m,6,0,9,24,9,0,1,bonneSalle);


        }else if(choix == 3){ //karim
            m.p.personnages[1].idDialogue = 18;
            m.p.personnages[0].idDialogue = 27;

            verifierCondition2(m,6,2,6,15,2,0,1,bonneSalle);
            verifierCondition(m,3,3,12,3,4,0,bonneSalle);   
            verifierCondition2(m,3,6,15,6,3,4,1,bonneSalle);
            verifierCondition2(m,6,2,9,18,9,0,1,bonneSalle);
        }

        if(m.p.personnages[0].idDialogue ==  27 && m.p.personnages[1].idDialogue ==  18 && m.p.personnages[2].idDialogue ==  21 && m.p.personnages[6].idDialogue ==  9 && m.j.idNarrationEnCours == 9){
                m.p.personnages[6].setPositionB(4);      
                m.p.personnages[6].setPositionS(1);
                verifierBonneSalle(m, 6, bonneSalle);
        }

        verifierCondition(m,4,4,18,10,0,1,bonneSalle);


        // === OBJET !!! =====

        verifierObjet(m,objet,idObjet,4,0);
        verifierObjet(m,objet,idObjet,5,1);
        verifierObjet(m,objet,idObjet,6,2);
        verifierObjet(m,objet,idObjet,7,3);
        verifierObjet(m,objet,idObjet,8,4);

        //REMISE A ZERO A CHAQUE FIN DE DIALOGUE (ou incrementation)
        if((m.p.personnages[bonneSalle].idDialogue % 3) == 2) {
           m.p.personnages[bonneSalle].incrementeOrdre();
           m.p.personnages[bonneSalle].idDialogue ++;
           bonneSalle = -1;
        }
        
        // FIN DE LA QUETE 2
        if(m.j.idNarrationEnCours == 11 && !narration){
            m.j.quetesJeu[1].estFinis = true;
            choixEp = false;
        }
    }
    if(m.j.queteEnCours==3){
    if(bonneSalle == -1){
            sePromener(m, events);
        }
    // ===== NARRATION =======
    verifierNarration(m,2,21,-1,0,0,narration);
    verifierNarration(m,2,24,0,0,0,narration);
    verifierNarration(m,3,18,1,0,0,narration);
    verifierNarration2(m,objet,2,0,0,narration);

    //on rend la carte accessible
        if(!objet && m.joueuse.getPositionB() == 4 && m.joueuse.getPositionS() == 0 && m.j.idNarrationEnCours == 7){
            m.j.idNarrationEnCours = 8;
            m.carte.setEstAccessibleB(3, true);
            narration = true; 
        }

    // ===== DIALOGUES =====
    verifierCondition(m,2,2,21,0,0,1,bonneSalle);
    verifierCondition2(m,2,3,24,15,1,0,2,bonneSalle);
    verifierCondition2(m,3,6,18,12,2,0,3,bonneSalle);

    //===== OBJETS ======
    verifierObjet(m,objet,idObjet,3,1);


        // mise a j des dialogues
        if((m.p.personnages[bonneSalle].idDialogue % 3) == 2) {
           m.p.personnages[bonneSalle].incrementeOrdre();
           m.p.personnages[bonneSalle].idDialogue ++;
           bonneSalle = -1;
        }

    }
}

void SDLJeu::affDialogues(Menu& m, bool &suivant, int &bonneSalle){
    int i = m.p.personnages[bonneSalle].getOrdre();
    if(bonneSalle != -1){
        if((m.p.personnages[bonneSalle].idDialogue >= 3*i || m.p.personnages[bonneSalle].idDialogue < 3 + 3*i)){
            affDialogue(m, bonneSalle, m.p.personnages[bonneSalle].idDialogue);
        }
        if(suivant){
            m.p.personnages[bonneSalle].idDialogue++;
            suivant = false;
            cout<<"apres suivant id dialogue = "<<m.p.personnages[bonneSalle].idDialogue<<endl;
        }
    }
}

void SDLJeu::affNarration(Menu& m, bool &narration) {
    if(narration){
        // Récupération de la narration correspondante
        font_color.r = 255;
        font_color.g = 102;
        font_color.b = 197;
        string afficher = m.j.quetesJeu[m.j.queteEnCours -1 ].getNarrationParId(m.j.idNarrationEnCours);
        // Dessin de la boîte de dialogue
        imNarration.dessiner(renderer, 15, 85, dimx-30, dimy-50);
        // Calcul des dimensions du texte
        int text_width = 0;
        int text_height = 0;
        TTF_SizeText(font, afficher.c_str(), &text_width, &text_height);
        
        // Positionnement du texte dans la boîte de dialogue
        SDL_Rect positionTitre;
        positionTitre.x = 130;
        positionTitre.y = 630;
        positionTitre.w = 600;
        positionTitre.h = 60;
        
        // Rendu du texte dans la boîte de dialogue
        SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font , afficher.c_str(), font_color, dimx-30);
        if (!surface) {
              std::cerr << "Erreur lors du rendu du texte : " << TTF_GetError() << std::endl;
            return;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture) {
            std::cerr << "Erreur lors de la création de la texture : " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
            return;
        }

        // IMPORTANT JE CROIS
        SDL_FreeSurface(surface);
        SDL_RenderCopy(renderer, texture, nullptr, &positionTitre);
        SDL_DestroyTexture(texture);
    }
}

void SDLJeu::affBouton(Menu &m, string afficher, int x, int y,int idB, int idS){

        if(m.carte.getBatiment(idB).getSalle(idS).estAccessibleS){
                font_color.r = 255;
                font_color.g = 102;
                font_color.b = 197;
            imFond.dessiner(renderer, x-50, y-50, 160, 40);
        }else{
                font_color.r = 150;
                font_color.g = 150;
                font_color.b = 150;
            imFond2.dessiner(renderer, x-50, y-50, 160, 40);
        }
        

        // Calcul des dimensions du texte
        int text_width = 0;
        int text_height = 0;
        TTF_SizeText(font, afficher.c_str(), &text_width, &text_height);


        
        // Positionnement du texte dans la boîte de dialogue
        SDL_Rect positionTitre;
        positionTitre.x = x-44;
        positionTitre.y = y-44;
        positionTitre.w = 150;
        positionTitre.h = 35;
        
        // Rendu du texte dans la boîte de dialogue
        SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font , afficher.c_str(), font_color, dimx-30);
        if (!surface) {
              std::cerr << "Erreur lors du rendu du texte : " << TTF_GetError() << std::endl;
            return;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture) {
            std::cerr << "Erreur lors de la création de la texture : " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
            return;
        }

        // IMPORTANT JE CROIS
        SDL_FreeSurface(surface);
        SDL_RenderCopy(renderer, texture, nullptr, &positionTitre);
        SDL_DestroyTexture(texture);
}

void SDLJeu::affJauge(const Menu &m, int bonneSalle){
    if(bonneSalle != -1){

        //imCoeur.dessiner(renderer,960,650,80,84);

        // Récupération de la jauge correspondante
        string afficher = to_string(m.p.personnages[bonneSalle].jauge_amour.getAmour()) + "%";

        // Calcul des dimensions du texte
        int text_width = 0;
        int text_height = 0;
        TTF_SizeText(font, afficher.c_str(), &text_width, &text_height);
        
        // Positionnement du texte dans la boîte de dialogue
        SDL_Rect positionTitre;
        positionTitre.x = 990;
        positionTitre.y = 680;
        positionTitre.w = 35;
        positionTitre.h = 35;
        
        // Rendu du texte dans la boîte de dialogue
        SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font , afficher.c_str(), font_color, dimx-30);
        if (!surface) {
              std::cerr << "Erreur lors du rendu du texte : " << TTF_GetError() << std::endl;
            return;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture) {
            std::cerr << "Erreur lors de la création de la texture : " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
            return;
        }

        //afficher la jauge qui monte et descend 

        SDL_Rect j_bar;
        j_bar.x = 985;
        j_bar.y = 500;
        j_bar.w = 40;
        j_bar.h = 180;
        SDL_SetRenderDrawColor(renderer,255, 246, 253,255);
        SDL_RenderFillRect(renderer,&j_bar);

        
        SDL_Rect jauge; 
        // if(m.p.personnages[bonneSalle].jauge_amour.getAmour() >0){
        //     jauge.x = j_bar.x; jauge.w =  j_bar.w; jauge.h = (j_bar.h*m.p.personnages[bonneSalle].jauge_amour.getAmour())/100 ; jauge.y = j_bar.y+j_bar.h-jauge.h;
        // }
        // else {
        //     jauge.x = j_bar.x; jauge.w = 0 ; jauge.h = 0 ; jauge.y = j_bar.y;
        // }

        int jaugeValue = m.p.personnages[bonneSalle].jauge_amour.getAmour(); // Valeur de la jauge

        jaugeValue = max(-100, min(100, jaugeValue)); // Limiter la valeur de la jauge entre -100 et 100

        jaugeValue += 100; // Décaler la valeur de la jauge pour qu'elle soit positive (entre 0 et 200)

        int jaugeHeight = (jaugeValue * j_bar.h) / 200; // Hauteur de la jauge relative à sa valeur

        jauge.x = j_bar.x;
        jauge.w = j_bar.w;
        jauge.h = jaugeHeight;

        jauge.y = j_bar.y + j_bar.h - jauge.y - jauge.h;

        SDL_SetRenderDrawColor(renderer,255,102,197,255);
        SDL_RenderFillRect(renderer,&jauge);

        // IMPORTANT JE CROIS
        SDL_FreeSurface(surface);
        SDL_RenderCopy(renderer, texture, nullptr, &positionTitre);
        SDL_DestroyTexture(texture);
    }
}

void SDLJeu::affJaugePerso(const Menu &m, int idPerso){
       // Récupération de la jauge correspondante
        string afficher = to_string(m.p.personnages[idPerso].jauge_amour.getAmour()) + "%";

        // Calcul des dimensions du texte
        int text_width = 0;
        int text_height = 0;
        TTF_SizeText(font, afficher.c_str(), &text_width, &text_height);
        
        // Positionnement du texte dans la boîte de dialogue
        SDL_Rect positionTitre;
        positionTitre.x = 639;
        positionTitre.y = 358;
        positionTitre.w = 35;
        positionTitre.h = 35;
        
        // Rendu du texte dans la boîte de dialogue
        SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font , afficher.c_str(), font_color, dimx-30);
        if (!surface) {
              std::cerr << "Erreur lors du rendu du texte : " << TTF_GetError() << std::endl;
            return;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture) {
            std::cerr << "Erreur lors de la création de la texture : " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
            return;
        }

        // IMPORTANT JE CROIS
        SDL_FreeSurface(surface);
        SDL_RenderCopy(renderer, texture, nullptr, &positionTitre);
        SDL_DestroyTexture(texture);
    }

void SDLJeu::sdlAff (Menu& m, int bonneSalle, bool& suivant, int &idDialogue ,bool &narration, bool objet, bool choixEp, boutonS entierB, int idObjet) {
        SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
        SDL_RenderClear(renderer);

        if(m.getChoixMenu() == debut){
            imDebut.dessiner(renderer,0,0,dimx,dimy);
        }
        if(m.getChoixMenu() == rien){
            imMenu.dessiner(renderer,0,0,dimx,dimy);
        }

        if(m.getChoixMenu() == profile){
            imProfil.dessiner(renderer,0,0,dimx,dimy);
            imJoueuse.dessiner(renderer,62,126,570,570);
            choisirApparence(m);
        }

        if(m.getChoixMenu() == quetes){
            if(!choixEp){
                if(m.j.quetesJeu[0].estFinis && !m.j.quetesJeu[1].estFinis){
                    imQuetes2.dessiner(renderer,0,0,dimx,dimy);
                }
                if(m.j.quetesJeu[0].estFinis && m.j.quetesJeu[1].estFinis){
                    imQuetes3.dessiner(renderer,0,0,dimx,dimy);
                }
                if(!m.j.quetesJeu[0].estFinis){
                    imQuetes1.dessiner(renderer,0,0,dimx,dimy);
                }
            }else{
                imSalle.dessiner(renderer,0,0,dimx,dimy);
                choisirSalle(m,imSalle);
                affPerso(m, bonneSalle);
                affNarration(m ,narration);
                affObjet(m, idObjet, objet);
                affJauge(m, bonneSalle);
                affDialogues(m, suivant, bonneSalle);
            }
            
            
            if(!narration && bonneSalle == -1){

                gereraffBouton(m,415,475,entierB,aml,"  AML  ",0,1);
                gereraffBouton(m,780,465,entierB,td10,"  TD10  ",0,2);
                gereraffBouton(m,668,653,entierB,tableRonde,"Table ronde",0,3);
                gereraffBouton(m,127,456,entierB,cafet,"  Cafet  ",1,1);
                gereraffBouton(m,726,353,entierB,piano,"  Piano  ",1,2);
                gereraffBouton(m,855,376,entierB,toilettesA," Toilettes ",1,3);
                gereraffBouton(m,373,626,entierB,toilettesB," Toilettes ",2,1);
                gereraffBouton(m,128,393,entierB,salleInfo,"Salle info",2,2);
                gereraffBouton(m,524,280,entierB,etage4,"4eme etage",2,3);
                gereraffBouton(m,1000,525,entierB,gymnaseC,"GymnaseC",3,1);
                gereraffBouton(m,210,522,entierB,distributeur,"Distributeur",3,2);
                gereraffBouton(m,606,526,entierB,bureau," Bureau ",3,3);
                gereraffBouton(m,948,484,entierB,banc,"  Banc  ",4,1);
                
            }
        }

        if(m.getChoixMenu() == carte){
            if(m.carte.getBatiment(4).estAccessible && !m.carte.getBatiment(3).estAccessible){
                imCarte4.dessiner(renderer,0,0,dimx,dimy);
            }else if(m.carte.getBatiment(3).estAccessible){
                imCarte3.dessiner(renderer,0,0,dimx,dimy);
            }else{
                imCarte1.dessiner(renderer,0,0,dimx,dimy);
            }
        }

        if(m.getChoixMenu() == personnages){
            if(m.persoChoisi == rienP) {
                if(m.categorieChoisie == rienC) {
                    imPerso.dessiner(renderer,0,0,dimx,dimy);
                } else if(m.categorieChoisie == crushs) {
                    imCrushs.dessiner(renderer,0,0,dimx,dimy);
                } else if(m.categorieChoisie == filles) {
                    imFilles.dessiner(renderer,0,0,dimx,dimy);
                } else if(m.categorieChoisie == profs) {
                    imProfs.dessiner(renderer,0,0,dimx,dimy);
                }
            } else {
                if(m.categorieChoisie == filles && m.persoChoisi == chaima) {
                    imFille1.dessiner(renderer,0,0,dimx,dimy);
                    affJaugePerso(m,5);
                } else if(m.categorieChoisie == filles && m.persoChoisi == peste) {
                    imFille2.dessiner(renderer,0,0,dimx,dimy);
                    affJaugePerso(m,4);
                } else if(m.categorieChoisie == crushs && m.persoChoisi == castiel) {
                    imCrush1.dessiner(renderer,0,0,dimx,dimy);
                    affJaugePerso(m,0);
                } else if(m.categorieChoisie == crushs && m.persoChoisi == adam) {
                    imCrush2.dessiner(renderer,0,0,dimx,dimy);
                    affJaugePerso(m,1);
                } else if(m.categorieChoisie == crushs && m.persoChoisi == karim) {
                    imCrush3.dessiner(renderer,0,0,dimx,dimy);
                    affJaugePerso(m,2);
                } else if(m.categorieChoisie == profs && m.persoChoisi == elodie) {
                    imProf1.dessiner(renderer,0,0,dimx,dimy);
                    affJaugePerso(m,3);
                } else if(m.categorieChoisie == profs && m.persoChoisi == alexandre) {
                    imProf2.dessiner(renderer,0,0,dimx,dimy);
                    affJaugePerso(m,6);
                }
        }

        }

        if(m.getChoixMenu() == salle){
            imSalle.dessiner(renderer,0,0,dimx,dimy);
            choisirSalle(m,imSalle);
        }
}

void SDLJeu::sdlBoucle () {
    Menu m;
    SDL_Event events;
	bool quit = false;
    int bonneSalle = -1; 
    bool suivant, narration, objet; 
    int rep;
    int idObjet = -1;
    int idDialogue = 0;
    bool choixEp = false;
    int choix = -1;
    boutonS entierB = couloir;
    //int test=0;
	// tant que ce n'est pas la fin ...
	while (!quit) {

		while (SDL_PollEvent(&events)) {
			switch (events.type)
            {
            case SDL_QUIT:
                quit = true;
                break;

            case SDL_MOUSEMOTION :
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if(m.getChoixMenu() == quetes){
                     entierB = couloir;
                     if(m.joueuse.getPositionB()== 0 && m.joueuse.getPositionS() == 0){
                        gererSurvol(m,410,465,475,535,mouseX,mouseY,entierB,aml);
                        gererSurvol(m,780,830,465,515,mouseX,mouseY,entierB,td10);
                        gererSurvol(m,670,730,645,705,mouseX,mouseY,entierB,tableRonde);
                    }
                    if(m.joueuse.getPositionB()== 1 && m.joueuse.getPositionS() == 0){
                        gererSurvol(m,125,180,460,513,mouseX,mouseY,entierB,cafet);
                        gererSurvol(m,725,775,355,405,mouseX,mouseY,entierB,piano);
                        gererSurvol(m,855,910,375,430,mouseX,mouseY,entierB,toilettesA);
                    }
                    if(m.joueuse.getPositionB()== 2 && m.joueuse.getPositionS() == 0){
                        gererSurvol(m,375,425,630,680,mouseX,mouseY,entierB,toilettesB);
                        gererSurvol(m,130,180,395,445,mouseX,mouseY,entierB,salleInfo);
                        gererSurvol(m,520,575,280,330,mouseX,mouseY,entierB,etage4);
                    }
                    if(m.joueuse.getPositionB()== 3 && m.joueuse.getPositionS() == 0){
                        gererSurvol(m,1000,1055,525,575,mouseX,mouseY,entierB,gymnaseC);
                        gererSurvol(m,200,270,530,580,mouseX,mouseY,entierB,distributeur);
                        gererSurvol(m,600,660,530,580,mouseX,mouseY,entierB,bureau);
                    }
                    if(m.joueuse.getPositionB()== 4 && m.joueuse.getPositionS() == 0){
                        gererSurvol(m,944,997,475,536,mouseX,mouseY,entierB,banc);
                    }
                }
            break;
            case SDL_MOUSEBUTTONDOWN :

            if(m.getChoixMenu()==debut){
                // ==== BOUTON JOUER ====
                choixMenu(rien,events,m,380,715,580,690);
            }
        
            // ========= MENU ========

                if(m.getChoixMenu()==rien){
                    choixMenu(profile,events,m,410,690,223,276);
                    choixMenu(quetes,events,m,410,690,320,373);
                    choixMenu(personnages,events,m,410,690,418,472);
                    // == QUITTER ==
                    if(clic(410,690,516,567,events))
                    {
                        quit = true;
                    }
                }

            // ========= PROFIL ========

            if(m.getChoixMenu()==profile){
                // ==== BOUTON MENU ====
                choixMenu(rien,events,m,70,155,45,100);

                // ==== APPARENCE ====
                gererClicVoile(grisV,events,m,800,865,235,290);
                gererClicVoile(noirV,events,m,910,965,235,290);
                gererClicPeau(beigeP,events,m,800,865,415,475);
                gererClicPeau(noirP,events,m,910,965,415,475);
                gererClicFond(roseF,events,m,800,865,600,655);
                gererClicFond(blancF,events,m,910,965,600,655);
            }
            
            // ========= QUETES ========

            if(m.getChoixMenu()==quetes){
                    // ==== BOUTON MENU ====
                    choixMenu(rien,events,m,70,155,45,100);
                    if(!choixEp){
                        gererClicQuete(events, m,choixEp);
                    }
                    lancerQuete(m, events, bonneSalle, narration, objet, idObjet, choixEp,choix);
                    gererClicNarration(m, events, narration);
                    gererClicObjet(m, events, objet, idObjet);
                    gererClicDialogues(m, events, rep, suivant,choix);
                    updateJaugeAmour(m, bonneSalle, rep);
            }

            // ========= CARTE ========

            if(m.getChoixMenu() == carte){

                    // ==== BOUTON MENU ====
                   choixMenu(rien,events,m,70,155,45,100);

                    // ==== CHOIX BATIMENT ====
                    gererClicBatiment(nautibus,events,m,210,365,300,335);
                    gererClicBatiment(astree,events,m,730,885,300,335);
                    gererClicBatiment(bu,events,m,720,880,590,625);
                    gererClicBatiment(suaps,events,m,220,380,590,625);
                    gererClicBatiment(parc,events,m,480,635,430,465);
                }

                // ========= PERSONNAGES ========

                if(m.getChoixMenu()==personnages){
                    choisirCategorie(m, events, 425, 660, 255, 320, crushs);
                    choisirPerso(m, events, 120,360,380,440, crushs, castiel);
                    choisirPerso(m, events, 425, 665, 380, 440, crushs, adam);
                    choisirPerso(m, events, 740, 980, 385, 435, crushs, karim);

                    choisirCategorie(m, events, 425, 660, 385, 445, filles);
                    choisirPerso(m, events, 215, 455, 380, 435, filles, chaima);
                    choisirPerso(m, events, 645, 880, 380, 435, filles, peste);

                    choisirCategorie(m, events, 425, 665, 520,575, profs);
                    choisirPerso(m, events, 165,500,380,440, profs, elodie);
                    choisirPerso(m, events, 580,915,380,440, profs, alexandre);

                    if(clic(70, 155, 45, 100, events)) {
                        if(m.categorieChoisie == rienC){
                            choixMenu(rien,events,m,70,155,45,100);
                        }
                        if(m.persoChoisi == rienP&&(m.categorieChoisie == crushs || m.categorieChoisie == filles || m.categorieChoisie == profs)){
                                m.categorieChoisie = rienC;
                        }
                        if(m.categorieChoisie == profs) {
                            if(m.persoChoisi == elodie || m.persoChoisi == alexandre) {
                                m.persoChoisi = rienP;
                                m.categorieChoisie = profs;
                            }
                        } else if(m.categorieChoisie == crushs) {
                            if(m.persoChoisi == karim || m.persoChoisi == adam || m.persoChoisi == castiel) {
                                m.persoChoisi = rienP;
                                m.categorieChoisie = crushs;
                            }
                        } else if(m.categorieChoisie == filles) {
                            if(m.persoChoisi == chaima || m.persoChoisi == peste) {
                                m.persoChoisi = rienP;
                                m.categorieChoisie = filles;
                            }
                        }
                    }
                }
                //affichages des positions
                cout<<" x : "<<events.button.x<<" y : "<<events.button.y<<endl;
                // cout<<" bat : "<<m.joueuse.getPositionB()<<" salle : "<<m.joueuse.getPositionS()<<endl;
                // cout<<" bonne salle : "<<bonneSalle<<endl;
                // cout<<"entierB"<<entierB<<endl;
                // int positionBPerso = m.p.personnages[0].getPositionB();
                // int positionSPerso = m.p.personnages[0].getPositionS();
                // cout<<"B : "<<positionBPerso<<" S : "<<positionSPerso<<endl;
                // cout<<m.j.idNarrationEnCours<<endl;
            }
		}

        sdlAff(m, bonneSalle, suivant,idDialogue, narration, objet,choixEp,entierB, idObjet);
        SDL_RenderPresent(renderer);
	}

}

