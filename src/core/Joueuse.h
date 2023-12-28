#ifndef _JOUEUSE
#define _JOUEUSE

#include <string.h>
#include <iostream>
#include "Batiment.h"
#include "Salle.h"
#include "Carte.h"
//#include "Objet.h"
//using namespace std;


enum Couleur { roseF,blancF}; // couleurs du fond
enum Voile { noirV, grisV}; // couleurs du voile
enum Peau { noirP,beigeP}; // couleurs de peau


class Joueuse{
    private:
        int positionB; // batiment de la joueuse 
        int positionS; // salle de la joueuse
     
    public:
        string pseudo; // pseudo de la joueuse
        Peau peau;  // peau de la joueuse       
        Couleur fond; // fond de la joueuse 
        Voile voile; // voile de la joueuse

        /**
        * @brief Constructeur par défaut de la Joueuse : initialise toutes les données de la joueuse.
        * @see Joueuse::Joueuse()
        */
        Joueuse();

        /**
        * @brief Accesseur : récupère l'id du batiment ou se trouve la joueuse
        * @see int Joueuse::getPositionB() const
        * @retval int
        */
        int getPositionB() const;

        /**
        * @brief Accesseur : récupère l'id de la salle ou se trouve la joueuse
        * @see int Joueuse::getPositionS() const
        * @retval int
        */
        int getPositionS() const;

        /**
        * @brief Mutateur : modifie l'id du batiment ou se trouve la joueuse
        * @see void Joueuse::setPositionB(int idBNv)
        * @param [in] idBNv nouveau id de batiment
        */
        void setPositionB(int idBNv);

        /**
        * @brief Mutateur : modifie l'id de la salle ou se trouve la joueuse
        * @see void Joueuse::setPositionS(int idSNv)
        * @param [in] idSNv nouveau id de la sallle
        */
        void setPositionS(int idSNv);

        /**
        * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
        * @see void Joueuse::testRegression() const
        */
        void testRegression() const;
};

#endif