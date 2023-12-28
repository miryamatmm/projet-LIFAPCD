#include "../core/Menu.h"
#include <iostream>

using namespace std;

int main(){
    Menu m;
    m.carte.getBatiment(1).getSalle(0).testRegression();
    m.carte.getBatiment(1).testRegression();
    //test de personne
    m.p.personnages[1].testRegression();
    //test de jauge_amour
    m.p.personnages[1].jauge_amour.testRegression();
    m.carte.testRegression();
    m.j.testRegression();
    m.joueuse.testRegression();
    m.testRegression();
    return 0;
}