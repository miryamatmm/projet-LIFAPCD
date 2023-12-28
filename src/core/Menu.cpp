#include <cassert>
#include "Menu.h"

Menu::Menu(){
    choixMenu = debut;
    categorieChoisie = rienC;
    persoChoisi = rienP;
    p.RemplirDialogue();
    j.RemplirQuete();
}

ChoixMenu Menu::getChoixMenu() const{
    return choixMenu;
}

void Menu::setChoixMenu(ChoixMenu choixMenuNv){
    choixMenu = choixMenuNv;
}


void Menu:: testRegression() const{
    Menu m;
    
    //test du constructeur par défaut

    assert(m.choixMenu == debut);

    //test de getChoixMenu

    assert(m.getChoixMenu() == debut);

    //test de setChoixMenu
    m.setChoixMenu(profile);
    assert(m.getChoixMenu() == profile);
}