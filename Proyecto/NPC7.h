#ifndef NPC7_H
#define NPC7_H

#include "Personaje.h"

class NPC7:public Personaje
{
    public:
        NPC7(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~NPC7();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // NPC7_H
