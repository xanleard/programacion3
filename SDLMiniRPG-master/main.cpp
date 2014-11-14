
#include<SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<list>
#include <algorithm>
#include "PersonajeJugador.h"
#include "NPC.h"
#include "NPC2.h"
#include "NPC3.h"
#include <stdlib.h>
using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character,*menu,*historia,*game_over;
SDL_Rect rect_background,rect_character;
bool reiniciar=false;

void loophistoria();
void loopgame();
void loopMenu();

void loopGameover(){
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_c ){

                        loopMenu();
                }
            }
        }

        SDL_RenderCopy(renderer, game_over, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}

 void  loopMenu(){
    reiniciar = false;
    while(true)
    {
        reiniciar = false;
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE ){

                        exit(0);
                }

                 if(Event.key.keysym.sym == SDLK_RETURN ){
                        loopgame();
                }

                if(Event.key.keysym.sym == SDLK_c ){
                        loophistoria();


                }
            }
        }

        SDL_RenderCopy(renderer,menu, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}

void loophistoria(){
while(true)//
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_q ){

                        loopMenu();
                }
            }
        }

        SDL_RenderCopy(renderer, historia, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }


}


void loopgame(){
list<Personaje*>personajes;

            personajes.push_back(new PersonajeJugador (450,0,renderer,&personajes));//
   // personajes.push_back(new NPC (50,50,renderer,&personajes));
    //personajes.push_back(new NPC2 (100,100,renderer,&personajes));


    //Main Loop
    int frame=0;

    while(!reiniciar)
    {
        frame++;
        if(frame%400==0){
            personajes.push_back(new NPC (0+(rand()%100),0/*rand() % 100*/,renderer,&personajes));
            personajes.push_back(new NPC2 (0+(rand()%100),250,renderer,&personajes));
             personajes.push_back(new NPC3 (300+(rand()%400),300,renderer,&personajes));
        }
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }
        }

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->logic((Uint8*)SDL_GetKeyboardState( NULL ));

        SDL_RenderCopy(renderer, background, NULL, &rect_background);

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->render(renderer);
        int cont = 0;
        PersonajeJugador *v = new PersonajeJugador (450,0,renderer,&personajes);
        for(std::list<Personaje*>::iterator i = personajes.begin();i!=personajes.end();i++){
                if((*i)->nombre == "Principal"){
                        cont ++;
                }
        }
        if(cont==0){
            reiniciar = true;
            loopGameover();
        }
//        list<Personaje>::iterator pos;
//        pos = personajes.begin();
//        while( pos != personajes.end())
//        {
//            pos++;
//        }
        SDL_RenderPresent(renderer);

        SDL_Delay(16.66);

    }
}


int main( int argc, char* args[] )
{

    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 280/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    menu = IMG_LoadTexture(renderer,"menu.png");
    historia=IMG_LoadTexture(renderer,"historia.png");
    game_over=IMG_LoadTexture(renderer,"game_over.png");

    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    character = IMG_LoadTexture(renderer, "assets/personaje/down.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = w;
    rect_character.h = h;

    loopMenu();
	return 0;
}
