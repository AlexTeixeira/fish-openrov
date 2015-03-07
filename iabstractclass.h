#ifndef IABSTRACTCLASS_H
#define IABSTRACTCLASS_H

class IAbstractClass
{
public:
    IAbstractClass();
    
    int getId();
    
    void setId(int _id);
    
protected:
    int id;
};

#endif // IABSTRACTCLASS_H
