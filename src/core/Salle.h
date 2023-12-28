#ifndef _SALLE
#define _SALLE

#include <string>
#include <vector>

class Salle{
    private :
        std::string nomS; // nom de la salle
        int nbBoutons; // le nombre de boutons de la salles
        int nbPerso; // le nombre de Perso dans la salle
        int idS; // l'identifiant de la salle
    public : 

    bool estAccessibleS; // pour savoir si la salle est accessible

    /**
    * @brief Constructeur par défaut de la classe Salle
    * @see Salle::Salle()
    */
    Salle();

    /**
    * @brief Constructeur de la classe: initialise toutes les données membres de la salle avec les données en paramètre
    * @param [in] nomSNv le nom de la salle
    * @param [in] nbBoutonsNv le nombre de boutons de la salle
    * @param [in] nbPersoNv le nombre de perso dans la salle
    * @param [in] estAccessibleSNv pour savoir si la salle est accessible
    * @param [in] idSNv l'identifiant de la salle
    * @see Salle ::Salle(const std::string& nomSNv, int nbBoutonsNv,int nbPersoNv,bool estAccessibleSNv,int idSNv)
    */
    Salle(const std::string& nomSNv, int nbBoutonsNv,int nbPersoNv,bool estAccessibleSNv,int idSNv);

    /**
    * @brief Destructeur de la classe: déallocation de la mémoire du tableau de boutons
    * @see Salle::~Salle()
    */
    ~Salle();

    /**
    * @brief Accesseur : récupère le nom de la salle
    * @see const string& Salle::getNom()
    * @retval string nom de la salle
    */
    const std::string& getNom() const;


    /**
    * @brief Accesseur : récupère le nombre de perso de la salle
    * @param none
    * @see int Salle::getNbPerso()
    * @retval int le nombre de perso de la salle
    */
    int getNbPerso() const;

    /**
    * @brief Accesseur : récupère l'accessibilité de la salle
    * @param none
    * @see bool Salle::getEstAccessible()
    * @retval bool pour savoir si la salle est accessible
    */
    bool getEstAccessible() const;

    /**
    * @brief Accesseur : récupère l'identifiant de la salle
    * @param none
    * @see bool Salle::getIdS()
    * @retval int l'identifiant de la salle
    */
    int getIdS() const;

    /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @see void Salle::testRegression() const
    */
    void testRegression() const;

};

#endif