#include "NPC7.h"
NPC7::NPC7(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    this->nombre = "remolino";

    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc7/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc7/down2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";


    //resien agragado



    //
}

NPC7::~NPC7()
{
    //dtor
}

void NPC7::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;


      rectangulo.y;



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
}  //dtor}
