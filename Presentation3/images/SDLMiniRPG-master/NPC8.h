#ifndef NPC8_H
#define NPC8_H
 #include "Personaje.h"
class NPC8:public Personaje
{
    public:
        NPC8(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~NPC8();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // NPC8_H
