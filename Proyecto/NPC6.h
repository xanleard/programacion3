#ifndef NPC6_H
#define NPC6_H

#include "Personaje.h"

class NPC6:public Personaje
{
    public:
        NPC6(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~NPC6();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // NPC6_H
