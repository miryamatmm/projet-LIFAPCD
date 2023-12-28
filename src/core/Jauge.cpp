#include <iostream>
#include <cassert>
using namespace std;

#include "Jauge.h"

 Jauge::Jauge(){
    pourcentage= 0;
 }

int Jauge::getAmour() const{
   return pourcentage;
}
// ? Garder setAmour ou ne pas le garder telle est la question
void Jauge::setAmour(int majJauge){
   pourcentage = pourcentage + majJauge;
}

void Jauge::testRegression() const{
   Jauge j;
   assert(j.pourcentage==0);
   
   Jauge j2;
   j2.pourcentage=25;
   assert(j2.getAmour()==25);

   j.setAmour(13);
   assert(j.pourcentage==13);
}