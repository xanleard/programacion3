#include "NPC2.h"
#include "PersonajeJugador.h"

NPC2::NPC2(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc2/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/down2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";
}

NPC2::~NPC2()
{
    //dtor
}

void NPC2::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;

    rectangulo.x;
    //if(rectangulo.x>1000)
//        //rectangulo.x=0;
// PersonajeJugador *v = new PersonajeJugador (450,0,renderer,&personajes);
//        for(std::list<Personaje*>::iterator i = personajes.begin();i!=personajes.end();i++){
//                if((*i)->nombre == "Principal"){
//                        cont ++;
//                }
//        }
    for(list<Personaje*>::iterator i = personajes->begin();
            i!=personajes->end();
            i++)
    {
        if(this==(*i))
            continue;
        if(colision(this->rectangulo, (*i)->rectangulo)){
            personajes->erase(i);

//                rectangulo=temp;

            break;

        }
    }

}
