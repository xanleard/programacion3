#ifndef NPC5_H
#define NPC5_H

#include "Personaje.h"

class NPC5:public Personaje
{
    public:
        NPC5(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~NPC5();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // NPC5_H
