#ifndef ABSTRACTBUILDER_H
#define ABSTRACTBUILDER_H

class AbstractBuilder
{
public:
    AbstractBuilder(void);
    
    virtual void* CreateInstance() = 0;
};

#endif // ABSTRACTBUILDER_H
