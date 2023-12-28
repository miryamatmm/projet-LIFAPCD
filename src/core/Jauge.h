#ifndef _JAUGE
#define _JAUGE

class Jauge{
    private : 
        int pourcentage; // valeur numerique de la jauge 
    public : 

    /**
    * @brief Constructeur par défaut de la Jauge : initialise le pourcentage.
    * @see Jauge::Jauge()
    */
    Jauge();

    /**
    * @brief Accesseur : récupère le pourcentage d'une jauge
    * @see int Jauge::getAmour() const
    * @retval int
    */
    int getAmour() const;

    /**
    * @brief Mutateur : augmente le pourcentage de la jauge
    * @see void Jauge::setAmour(int majJauge)
    * @param [in] majJauge entier à ajouter au pourcentage de la jauge
    */
    void setAmour(int majJauge);

    /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @see void Jauge::testRegression() const
    */
    void testRegression() const;
};

#endif