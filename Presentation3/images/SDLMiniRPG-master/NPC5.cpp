#include "NPC5.h"

NPC5::NPC5(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    this->nombre = "dragon_agua";

    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc2/dragonw.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/dragonw2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";


    //resien agragado



    //
}

NPC5::~NPC5()
{
    //dtor
}

void NPC5::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;

     rectangulo.x;



    for(list<Personaje*>::iterator i = personajes->begin();
            i!=personajes->end();
            i++)
    {
        if(this==(*i))
            continue;
        if(colision(this->rectangulo, (*i)->rectangulo))
            //rectangulo=temp;
            personajes->erase(i);
    }
}
