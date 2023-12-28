#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>
#include "../core/Menu.h"


void AffPerso( Personne p ){ 

    cout<<"Prenom : ";
    cout<<p.getPrenom()<<endl;
    cout<<"Description : ";
    cout<<p.description<<endl;
    cout<<"Pourcentage de la jauge d'amour: "<<p.jauge_amour.getAmour()<<endl;
}

void AffMenuPerso( Personnages p){
    bool ok = true;
    char detection;
    int choixperso;

    do{

        cout<<" Je veux obtenir plus d'informations sur ... "<<endl;
        cout<<" C : les crushs "<<endl;
        cout<<" F : les filles "<<endl;
        cout<<" P : les profs "<<endl;
        cout<<" q : quitter \n\n";
        cin>>detection;

        switch(detection){ // a enlver par mimi
            case 'C': 
                cout<<" Choisissez un crush : "<<endl;
                cout<<" 1 : Castiel "<<endl;
                cout<<" 2 : Nathaniel "<<endl;
                cout<<" 3 : Karim  \n\n"<<endl;
                cin>>choixperso;
                cout<<"\n";
                AffPerso(p.personnages[choixperso-1]);
                ok=false;
                break;
            case 'F': 
                cout<<" Choisissez une fille : "<<endl;
                cout<<" 1 : Chaïma "<<endl;
                cout<<" 2 : P-word "<<endl;
                cin>>choixperso;
                cout<<"\n";
                AffPerso(p.personnages[choixperso+2]);
                ok=false;
                break;
            case 'P':
                cout<<" Choisissez un prof : "<<endl;
                cout<<" 1 : Alexandre Meyer "<<endl;
                cout<<" 2 : Elodie Desseree "<<endl;
                cin>>choixperso;
                cout<<"\n";
                AffPerso(p.personnages[choixperso+4]);
                ok=false;
                break;
            case 'q': 
                ok=false;
                break;
        }

    }while(ok);

}

void AffCarte(const Carte& c, Joueuse &j){
    bool ok = true;
    char changerBat;
    int partirBat;
    int changerSalle;
    char retournerPrincipal;

    cout<<endl;
    cout<<"Vous etes ici : "; 
    const int idBJoueuse = j.getPositionB();
    const int idSJoueuse = j.getPositionS();
    cout<< "Batiment : "<< c.getBatiment(idBJoueuse).getNom()<<", ";
    cout<< "Salle : "<< c.getBatiment(idBJoueuse).getSalle(idSJoueuse).getNom()<<endl;

    cout<<"Vous voulez changer de batiment ? (O/N)"<<endl;
    cin>>changerBat;
    switch (changerBat)
    {
    
        case 'O' :
            cout<<endl<<"Dans quel batiment voulez vous allez ? "<<endl;
            for(int h=0; h<c.getNbBats();h++){
                bool accessibleB = c.getBatiment(h).getEstAccessible();
                if(accessibleB){
                    cout<<h<<" : "<<c.getBatiment(h).getNom()<<" , accessible : oui "<<endl;
                }else{
                    cout<<h<<" : "<<c.getBatiment(h).getNom()<<" , accessible : non "<<endl;
                }
            }
            cin>>partirBat;
            cout<<endl;
            if(c.getBatiment(partirBat).getEstAccessible()){
                j.setPositionB(partirBat);
                j.setPositionS(0);
                cout<<"Vous êtes à "<<c.getBatiment(partirBat).getNom()<<"\n\n"<<endl;
            }
            else{
                cout<<"Ce batiment n'est pas accesible pour le moment :)  \n\n "<<endl;
            }
            ok = false;
            break;

        case 'N':
            do{
            if(idSJoueuse == 0){
                cout<< "Ou voulez vous allez ?"<<endl;

                for(int i=0; i< c.getBatiment(idBJoueuse).getNbSalles();i++){
                    bool accessibleS = c.getBatiment(idBJoueuse).getSalle(i).getEstAccessible();
                    if(accessibleS){
                        cout<<i<<" : "<<c.getBatiment(idBJoueuse).getSalle(i).getNom()<<" , accessible : oui "<<endl;
                    }else{
                        cout<<i<<" : "<<c.getBatiment(idBJoueuse).getSalle(i).getNom()<<" , accessible : non "<<endl;
                    }
                }
                cin>>changerSalle;
                cout<<endl;
                if(c.getBatiment(idBJoueuse).getSalle(changerSalle).getEstAccessible()){
                    j.setPositionS(changerSalle);
                    cout<<"Vous êtes dans la salle "<<c.getBatiment(idBJoueuse).getSalle(changerSalle).getNom() <<"\n\n"<<endl;
                }
                else{
                    cout<<"Cette salle n'est pas accessible pour le moment ^^  \n\n "<<endl;
                }
                ok = false;
                break;
            }
            else{
                cout<<"Retourner au couloir principal ? (O/N)"<<endl;
                cin>>retournerPrincipal;
                switch(retournerPrincipal){
                    case 'O' :
                        cout<<"\nVous êtes au couloir principal de "<<c.getBatiment(idBJoueuse).getNom()<<"\n "<<endl;
                        j.setPositionS(0);
                        ok=false;
                        break;
                    case 'N' : 
                        ok=false;
                        break;
                }
            }
        }while(ok);   
        break;
    }

    
}

void AffDialogue(Personnages &p, int idGarcon, int idDialogue, char &detection){
    bool ok = true;

    cout<<"Pourcentage d'affinite : "<<p.personnages[idGarcon].jauge_amour.getAmour()<<endl;
    cout<<p.personnages[idGarcon].getPrenom()<<" : "<<p.personnages[idGarcon].dialogues[idDialogue][0]<<endl;
    cout<<endl;
    cout<<"A : "<<p.personnages[idGarcon].dialogues[idDialogue][1]<<endl;
    cout<<"B : "<<p.personnages[idGarcon].dialogues[idDialogue][2]<<endl;
    cout<<"C : "<<p.personnages[idGarcon].dialogues[idDialogue][3]<<endl;
    
    do{
        cin>>detection;
        switch(detection){
            case 'A' : 
                p.personnages[idGarcon].jauge_amour.setAmour(5);
                ok=false;
                break;
            case 'B' : 
                p.personnages[idGarcon].jauge_amour.setAmour(-5);
                ok=false;
                break;
            case 'C' : 
                p.personnages[idGarcon].jauge_amour.setAmour(10);
                ok=false;
                break;
            case 'q' : 
                ok = false;
                break;
        }
        }while(ok);
    cout<<"Pourcentage d'affinite : "<<p.personnages[idGarcon].jauge_amour.getAmour()<<endl;
    cout<<endl;
}

void AffObjet(Objet obj, Joueuse &j, Carte carte){
    char detection; 
    if((j.getPositionB() == obj.getObjetpositionB())&&(j.getPositionS() == obj.getObjetpositionS())){
        do{
            cout<<"x"<<endl;
            cout<<endl;
            cout<<"Pour prendre un objet appuyez sur P"<<endl;
            cin>>detection; 
            if(detection == 'P'){
                obj.setAEtePris(true);
                obj.setEstVisible(false);
            }
        }while(obj.testVisible());
    }else AffCarte(carte, j);
}

void AffQuete(Jeu &jeu , Personnages &perso, Carte carte, Joueuse &joueuse){
    char detection;
    jeu.RemplirQuete();

    //QUETE NUMERO 0 : NOUVEAU CAMPUS 
    cout<<"Titre de la quete : "<<jeu.quetesJeu[0].getTitreQuete()<<endl;
    cout<<jeu.quetesJeu[0].getNarrationParId(0)<<endl;
    perso.RemplirDialogue();
    
    while(((joueuse.getPositionS()  != 1)||(joueuse.getPositionB() != 1))&&((joueuse.getPositionS()  != 3)||(joueuse.getPositionB() != 0))){
        AffCarte(carte, joueuse);
    }

    if(((joueuse.getPositionS() == 1)&&(joueuse.getPositionB() == 1))){
        AffDialogue(perso, 0, 0, detection);
        if(detection == 'A'){
            AffDialogue(perso, 0, 1, detection);
        }else if(detection == 'C'){
            AffDialogue(perso, 0, 2, detection);
        }
    } 

    if(((joueuse.getPositionS() == 3)&&(joueuse.getPositionB() == 0))){
        AffDialogue(perso, 1, 0, detection);
        if(detection == 'A'){
            AffDialogue(perso, 1, 1, detection);
        }else {
            AffDialogue(perso, 1, 2, detection);
        }
    } 
    
    cout<<jeu.quetesJeu[0].getNarrationParId(1)<<endl;
    while((joueuse.getPositionS()  != 1)||(joueuse.getPositionB() != 2)){
        AffCarte(carte, joueuse);
    }
    AffObjet(jeu.quetesJeu[0].getObjetParId(0), joueuse, carte);
    cout<<jeu.quetesJeu[0].getNarrationParId(2)<<endl;


    while((joueuse.getPositionS()  != 2)||(joueuse.getPositionB() != 0)){
        AffCarte(carte, joueuse);
    }

    AffDialogue(perso, 6, 0, detection);
    if(detection == 'C'){
        AffDialogue(perso, 6, 2, detection);
    }else {
        AffDialogue(perso, 6, 1, detection);
    } 
    cout<<jeu.quetesJeu[0].getNarrationParId(3)<<endl;

}


void AffQuetes(Jeu &jeu , Personnages &perso, Carte carte, Joueuse &joueuse){
    bool ok = true; 
    char detection;
    cout<<"Voulez-vous commencer une quete ? (O/N)"<<endl;
    cin>>detection;
    switch(detection){
            case 'O' : 
                AffQuete(jeu, perso, carte, joueuse);
                ok=false;
                break;
            case 'N' : 
                ok = false;
                break;
        }while(ok);
}

void AffProfil(Joueuse &j){
    char modifierProfil;
    char modifierQuoi;
    string donneeModifiee;
    char choixNv;

    cout<<"\nPseudo : "<<j.pseudo.c_str()<<endl;

    cout<<"Couleur de fond : ";
    switch(j.fond){
        case roseF : 
            cout<<"Rose"<<endl;
            break;
        case blancF : 
            cout<<"Blanc"<<endl;
    }

    cout<<"Couleur de voile : ";
    switch (j.voile){
        case noirV :
            cout<<"Noir"<<endl;
            break;
        case grisV :
            cout<<"Gris"<<endl;
            break;
    }

    cout<<"Couleur de peau : ";
    switch (j.peau){
        case beigeP : 
            cout<<"Beige"<<endl;
            break;
        case noirP :
            cout<<"Noir"<<endl;
            break;
    }
    cout<<"\n \nVoulez vous modifier votre profil ? (O/N)\n";
    cin>>modifierProfil;
    switch (modifierProfil)
    {
        case 'O':
            cout<<"\nQue voulez-vous modifier ?"<<endl;
            cout<<" 1 : Pseudo "<<endl;
            cout<<" 2 : Fond "<<endl;
            cout<<" 3 : Voile "<<endl;
            cout<<" 4 : Peau  \n\n"<<endl;
            cin>>modifierQuoi;
            switch(modifierQuoi){
                case '1' :
                    cout<<"\nSaisissez votre nouveau pseudo \n";
                    cin>>donneeModifiee;
                    j.pseudo = donneeModifiee;
                    break;
                case '2' :
                    cout<<"\nCouleur de fond disponible : \n";
                    cout<<" 1 : Rose "<<endl;
                    cout<<" 2 : Blanc "<<endl;
                    cin>>donneeModifiee;
                    if(donneeModifiee == "1") j.fond = roseF;
                    else if(donneeModifiee == "2") j.fond = blancF;
                    break;
                case '3' :
                    cout<<"\nCouleur de voile disponible : \n";
                    cout<<" 1 : Gris "<<endl;
                    cout<<" 2 : Noir  \n\n"<<endl;
                    cin>>choixNv;
                    switch (choixNv){
                        case '1' :
                            j.voile = grisV;
                            cout<<"\nTon voile est maintenant gris ^^ \n"<<endl;
                            break;
                        case '2' :
                            j.voile = noirV;
                            cout<<"\nTon voile est maintenant noir ^^ \n"<<endl;
                            break;
                    }
                    break;
                case '4' :
                    cout<<"\nCouleur de peau disponible : \n";
                    cout<<" 1 : Beige "<<endl;
                    cout<<" 2 : Noir \n\n"<<endl;
                    cin>>choixNv;
                    switch (choixNv){
                        case '1' : 
                            j.peau = beigeP;
                            cout<<"\nTa couleur de peau est maintenant beige ^^ \n"<<endl;
                            break;
                        case '2' : 
                            j.peau = noirP;
                            cout<<"\nTa couleur de peau est maintenant noir ^^ \n"<<endl;
                            break;
            }
            break;
    
        default:
            break;
    }

    }
}

void AffMenu(Menu m){
    bool ok = true;
    char detection;

    do{
        cout<<"Pressez un bouton : "<<endl;
        cout<<"C : Carte"<<endl;
        cout<<"P : Profil"<<endl;
        cout<<"A : Personnages"<<endl;
        cout<<"Q : Quetes"<<endl;
        cout<<"S : sauvegarder"<<endl;
        cout<<"q : Quitter"<<endl;
        cout<<endl;
        //detection=getCh();
        cin>>detection;
        switch(detection){
            case 'C' : 
                m.setChoixMenu(carte);
                AffCarte(m.carte,m.joueuse);
                break;
            case 'P' : 
                m.setChoixMenu(profile);
                AffProfil(m.joueuse);
                break;
            case 'A' : 
                m.setChoixMenu(personnages);
                AffMenuPerso(m.p);
                break;
            case 'Q' : 
                m.setChoixMenu(quetes);
                AffQuetes(m.j, m.p, m.carte, m.joueuse);
                break;
            case 'S' : 
                m.setChoixMenu(sauvegarder);
                break;
            case 'M' :
                m.setChoixMenu(rien);
            case 'q' : 
                ok = false;
                break;
        }
    }while(ok);

}

void TXTboucle(Menu m){
    AffMenu(m);
}