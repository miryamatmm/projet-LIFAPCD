#ifndef _OBJET
#define _OBJET


class Objet{
    private :
        bool aEtePris; // booléen pour savoir si l'objet à été pris
        bool estVisible; // booléen pour savoir si l'objet est visible
        int objetpositionB; // id du batiment ou se trouve l'objet
        int objetpositionS; // id de la salle ou se trouve l'objet
    public : 

    /**
    * @brief Constructeur par défaut de Objet : initialise toutes les données.
    * @see Menu::Menu()
    */
    Objet();

    /**
    * @brief Accesseur : récupère aEtePris
    * @see bool Objet::testPris()
    * @retval bool
    */
    bool testPris();

    /**
    * @brief Accesseur : récupère estVisible
    * @see bool Objet::testVisible()
    * @retval bool
    */
    bool testVisible();

    /**
    * @brief Accesseur : récupère l'id du batiment ou se trouve l'objet
    * @see int Objet::getObjetpositionB()
    * @retval int
    */
    int getObjetpositionB();

    /**
    * @brief Accesseur : récupère l'id de la salle ou se trouve l'objet
    * @see int Objet::getObjetpositionS()
    * @retval int
    */
    int getObjetpositionS();

    /**
    * @brief Mutateur : modifie aEtePris
    * @see void Objet::setAEtePris(bool aEtePrisNv)
    * @param [in] aEtePrisNv nouveau aEtePris 
    */
    void setAEtePris(bool aEtePrisNv);

    /**
    * @brief Mutateur : modifie estVisible
    * @see void Objet::setEstVisible(bool estVisibleNv)
    * @param [in] estVisible nouveau estVisible 
    */
    void setEstVisible(bool estVisibleNv);

    /**
    * @brief Mutateur : modifie l'id du batiment ou se trouve l'objet
    * @see void Objet::setObjetpositionB(int objetpositionBNv)
    * @param [in] objetpositionBNv nouveau id de batiment
    */
    void setObjetpositionB(int objetpositionBNv);

    /**
    * @brief Mutateur : modifie l'id de la salle ou se trouve l'objet
    * @see void Objet::setObjetpositionS(int objetpositionSNv)
    * @param [in] objetpositionSNv nouveau id de la salle
    */
    void setObjetpositionS(int objetpositionSNv);

    /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @see void Objet::testRegression() const
    */
    void testRegression() const;
};

#endif