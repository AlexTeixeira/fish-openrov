#ifndef IABSTRACTCLASS_H
#define IABSTRACTCLASS_H

class IAbstractClass
{
public:
    IAbstractClass();
    
    /*!
     *  \brief GetId()
     *     Fonction qui permet de récupérer l'id d'une IAbstractClass
     *  \return int
     */
    int GetId();
    
    /*!
     *  \brief SetId()
     *      Méthode qui permet de setter l'id d'un lieu
     *  \param int _id : id de la framme
     */
    void SetId(int _id);
    
protected:
    int id;
};

#endif // IABSTRACTCLASS_H
