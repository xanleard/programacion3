#ifndef ARBOLTRINARIO_H
#define ARBOLTRINARIO_H

#include <iostream>

class NodoTrinario
{
public:
    NodoTrinario *izq,*medio,*der;
    int num;
    NodoTrinario(int num)
    {
        this->num = num;
        izq=medio=der=NULL;
    }
};

#endif // ARBOLTRINARIO_H
