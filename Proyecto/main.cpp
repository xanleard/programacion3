
#include <SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<fstream>
#include "PersonajeJugador.h"
#include "NPC.h"
#include "NPC2.h"
#include "NPC3.h"
#include "NPC4.h"
#include "NPC5.h"
#include "NPC6.h"
#include "NPC7.h"
#include "NPC8.h"

#include <stdlib.h>

   /* srand, rand */

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character,*game_over,*menu,*nivel2,*gana,*nivel3,*historia,*ActoI,*ActoII,*ActoIII;
SDL_Rect rect_background,rect_character;
list<Personaje*>personajes;
bool reiniciar=false;


class Tile
{
public:
    int fuente_x;
    int fuente_y;
    int destino_x;
    int destino_y;
    Tile(int fuente_x, int fuente_y, int destino_x, int destino_y)
    {
        this->fuente_x=fuente_x;
        this->fuente_y=fuente_y;
        this->destino_x=destino_x;
        this->destino_y=destino_y;
    }
};

vector<Tile*> cargarTiles(string nombre_archivo)
{
    vector<Tile*> tiles;
    ifstream archivo(nombre_archivo.c_str());
    for(int destino_y=0; destino_y<10; destino_y++)
    {
        for(int destino_x=0; destino_x<10; destino_x++)
        {
            int fuente_x;
            int fuente_y;
            archivo>>fuente_x;
            archivo>>fuente_y;
            tiles.push_back(new Tile(fuente_x,fuente_y,destino_x,destino_y));
        }
    }
    archivo.close();
    return tiles;
}


void dibujarTile(SDL_Texture *tileset_texture, SDL_Renderer* renderer,
        int fuente_x, int fuente_y, int destino_x, int destino_y)
{
    SDL_Rect fuente,destino;
    fuente.x = 32*fuente_x;
    fuente.y = 32*fuente_y;
    fuente.w = 32;
    fuente.h = 32;

    destino.x = 32*destino_x;
    destino.y = 32*destino_y;
    destino.w = 32;
    destino.h = 32;


    SDL_RenderCopy(renderer,tileset_texture,&fuente,&destino);
}

void loopNivel3();
void loopNivel2();
void loopNivel1();
void loopMenu();
void loophistoria();

void actoIII(){
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
                if(Event.key.keysym.sym == SDLK_RETURN ){

                        personajes.clear();
                         loopNivel2();

                }
            }
        }

        SDL_RenderCopy(renderer, ActoIII, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}

void actoII(){
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
                if(Event.key.keysym.sym == SDLK_SPACE ){

                        personajes.clear();
                         loopNivel1();

                }
            }
        }

        SDL_RenderCopy(renderer, ActoII, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}

void actoI(){
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
                if(Event.key.keysym.sym == SDLK_SPACE ){

                        personajes.clear();
                         loopNivel3();

                }
            }
        }

        SDL_RenderCopy(renderer, ActoI, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}

void loopGanas(){
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
                if(Event.key.keysym.sym == SDLK_ESCAPE ){

                        personajes.clear();
                        loopMenu();

                }
            }
        }

        SDL_RenderCopy(renderer, gana, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}

void  loopMenu(){
    reiniciar = false;
    personajes.clear();
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
                        personajes.clear();
                        exit(0);
                }

                 if(Event.key.keysym.sym == SDLK_1 ){
                        personajes.clear();
//                        loopNivel3();
                        actoI();
                }
                if(Event.key.keysym.sym == SDLK_2 ){
                        personajes.clear();
                        //loopNivel1();
                        actoII();
                }
                if(Event.key.keysym.sym == SDLK_3 ){
                        personajes.clear();
                        //loopNivel2();
                        actoIII();
                }

                if(Event.key.keysym.sym == SDLK_h ){
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
                if(Event.key.keysym.sym == SDLK_ESCAPE ){

                        loopMenu();
                }
            }
        }

        SDL_RenderCopy(renderer, historia, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }


}

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
                if(Event.key.keysym.sym == SDLK_ESCAPE ){

                        personajes.clear();
                        loopMenu();

                }
            }
        }

        SDL_RenderCopy(renderer, game_over, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}

void loopNivel3(){

personajes.push_back(new PersonajeJugador (250,250,renderer,&personajes));


//dragon hembra nivel 3
 personajes.push_back(new NPC6 (300,200,renderer,&personajes));
 personajes.push_back(new NPC2 (200,400,renderer,&personajes));
 personajes.push_back(new NPC8 (0,0,renderer,&personajes));





    SDL_Texture* tileset_texture = IMG_LoadTexture(renderer, "assets/tileset.png");
    vector<Tile*>tiles=cargarTiles("assets/tile.map");

    //Main Loop
    int frame=0;
    int cons=0;
    int frame2=0;
    int cons2=0;

    while(true)
    {



        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {


            }
        }

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->logic((Uint8*)SDL_GetKeyboardState( NULL ));

        SDL_RenderCopy(renderer, nivel3, NULL, &rect_background);
//        for(int i=0;i<tiles.size();i++)
//        {
//            dibujarTile(tileset_texture,renderer,
//                    tiles[i]->fuente_x,tiles[i]->fuente_y,
//                    tiles[i]->destino_x,tiles[i]->destino_y);
//        }
//
//        dibujarTile(tileset_texture,renderer,
//                    0,6,
//                    5,4);

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->render(renderer);

//loop de game over si falta uno de los dos
         int cont = 0;
        for(std::list<Personaje*>::iterator i = personajes.begin();i!=personajes.end();i++){
                if((*i)->nombre=="Principal"){
                        cont ++;
                }
        }
        if(cont==0 ){
            reiniciar = true;
            personajes.clear();
            loopGameover();
        }
      //loop de ganeste si ya no hay NPC malos
        int cont4 = 0;
        int cont5=0;

        for(std::list<Personaje*>::iterator i = personajes.begin();i!=personajes.end();i++){
               if((*i)->nombre=="dragon_negro"){
                    cont4++;
                }else if ((*i)->nombre=="dragona"){
                    cont5++;
                }
        }

                 if(cont4==0 && cont5==0){
            reiniciar = true;
            loopGanas();
        }


        SDL_RenderPresent(renderer);

        SDL_Delay(16.66);
    }

}

void loopNivel2(){

//personaje jugador
personajes.push_back(new PersonajeJugador (425,100,renderer,&personajes));




 //arboles

    personajes.push_back(new NPC4 (160,300,renderer,&personajes));
    personajes.push_back(new NPC4 (220,300,renderer,&personajes));
    //
    personajes.push_back(new NPC3 (10,5,renderer,&personajes));
    personajes.push_back(new NPC3 (255,5,renderer,&personajes));
    personajes.push_back(new NPC3 (95,160,renderer,&personajes));
    personajes.push_back(new NPC3 (420,170,renderer,&personajes));
    // hoyo negro
    personajes.push_back(new NPC7 (270,200,renderer,&personajes));

//dragon agua
personajes.push_back(new NPC5 (380,380,renderer,&personajes));
//dragon hembra nivel 2
 personajes.push_back(new NPC6 (200,400,renderer,&personajes));
 //dragon negro
 personajes.push_back(new NPC2 (100,200,renderer,&personajes));

    SDL_Texture* tileset_texture = IMG_LoadTexture(renderer, "assets/tileset.png");
    vector<Tile*>tiles=cargarTiles("assets/tile.map");

    //Main Loop
    int frame=0;
    int cons=0;
    int frame2=0;
    int cons2=0;

    while(true)
    {


            //para los npc 1
            int creados=0;
            frame++;
            if(frame%100==0 && cons<3){
//                personajes.push_back(new NPC (50,rand() % 50,renderer,&personajes));
                    personajes.push_back(new NPC (150,100,renderer,&personajes));
                cons++;
                creados++;
            }

            //para el dragon 2 de agua

             frame2++;
            if(frame2%100==0 && cons2<3){

                //personajes.push_back(new NPC5 (380,380,renderer,&personajes));
                cons2++;
                creados++;
            }

        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {


            }
        }

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->logic((Uint8*)SDL_GetKeyboardState( NULL ));

        SDL_RenderCopy(renderer, nivel2, NULL, &rect_background);
//        for(int i=0;i<tiles.size();i++)
//        {
//            dibujarTile(tileset_texture,renderer,
//                    tiles[i]->fuente_x,tiles[i]->fuente_y,
//                    tiles[i]->destino_x,tiles[i]->destino_y);
//        }
//
//        dibujarTile(tileset_texture,renderer,
//                    0,6,
//                    5,4);

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->render(renderer);

//loop de game over si falta uno de los dos
         int cont = 0;
        int cont2 = 0;
        for(std::list<Personaje*>::iterator i = personajes.begin();i!=personajes.end();i++){
                if((*i)->nombre=="Principal"){
                        cont ++;
                }else if((*i)->nombre=="casa"){
                    cont2++;
                }
        }
        if(cont==0 || cont2==0){
            reiniciar = true;
            personajes.clear();
            loopGameover();
        }

   //loop de ganeste si ya no hay NPC malos
        int cont3 = 0;
        int cont4 = 0;
        int cont5=0;

        for(std::list<Personaje*>::iterator i = personajes.begin();i!=personajes.end();i++){
                if((*i)->nombre=="dragon_agua"){
                        cont3++;
                }else if((*i)->nombre=="dragon_negro"){
                    cont4++;
                }else if ((*i)->nombre=="dragona"){
                    cont5++;
                }
        }
        if(cont3==0 && cont4==0 && cont5==0){
            reiniciar = true;
            loopGanas();
        }



        SDL_RenderPresent(renderer);

        SDL_Delay(16.66);
    }




}

void loopNivel1(){

    personajes.push_back(new PersonajeJugador (425,100,renderer,&personajes));
    //personajes.push_back(new NPC (50,100,renderer,&personajes));
//casas
    personajes.push_back(new NPC3 (0,150,renderer,&personajes));
    personajes.push_back(new NPC3 (0,200,renderer,&personajes));
    personajes.push_back(new NPC3 (0,260,renderer,&personajes));
    personajes.push_back(new NPC3 (425,80,renderer,&personajes));

 //arboles
    personajes.push_back(new NPC4 (100,300,renderer,&personajes));
    personajes.push_back(new NPC4 (160,300,renderer,&personajes));
    personajes.push_back(new NPC4 (220,300,renderer,&personajes));

//dragno negro
personajes.push_back(new NPC2 (400,350,renderer,&personajes));
    SDL_Texture* tileset_texture = IMG_LoadTexture(renderer, "assets/tileset.png");
    vector<Tile*>tiles=cargarTiles("assets/tile.map");

    //Main Loop
    int frame=0;
    int conts=0;
    int frame2=0;
    int conts2=0;

    while(true)
    {


            //para los npc 1
            frame++;
            if(frame%100==0 && conts<3){
//                personajes.push_back(new NPC (50,rand() % 50,renderer,&personajes));
                    personajes.push_back(new NPC (50,100,renderer,&personajes));
                conts++;
            }

            //para el dragon


             frame2++;
            if(frame2%250==0 || conts2<3){
//                personajes.push_back(new NPC (50,rand() % 50,renderer,&personajes));

                conts2++;
            }

        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {

            }
        }

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->logic((Uint8*)SDL_GetKeyboardState( NULL ));

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
//        for(int i=0;i<tiles.size();i++)
//        {
//            dibujarTile(tileset_texture,renderer,
//                    tiles[i]->fuente_x,tiles[i]->fuente_y,
//                    tiles[i]->destino_x,tiles[i]->destino_y);
//        }
//
//        dibujarTile(tileset_texture,renderer,
//                    0,6,
//                    5,4);

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->render(renderer);


        //loop de game over si falta uno de los dos
         int cont = 0;
        int cont2 = 0;
        for(std::list<Personaje*>::iterator i = personajes.begin();i!=personajes.end();i++){
                if((*i)->nombre=="Principal"){
                        cont ++;
                }else if((*i)->nombre=="casa"){
                    cont2++;
                }
        }
        if(cont==0 || cont2==0){
            reiniciar = true;
            loopGameover();
        }

            //

   //loop de ganeste si ya no hay NPC malos
        int cont3 = 0;
        int cont4 = 0;

        for(std::list<Personaje*>::iterator i = personajes.begin();i!=personajes.end();i++){
                 if((*i)->nombre=="dragon_negro"){
                    cont4++;
                }
        }
        if( cont4==0){
            reiniciar = true;
            loopGanas();
        }



            //

        SDL_RenderPresent(renderer);
        SDL_Delay(16.66);
    }
}


int main( int argc, char* args[] )
{
    cargarTiles("assets/tile.map");
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 500/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
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
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;
game_over=IMG_LoadTexture(renderer,"game_over.png");
menu = IMG_LoadTexture(renderer,"menu.png");
nivel2 =IMG_LoadTexture(renderer,"nivel2.png");
gana=IMG_LoadTexture(renderer,"gana.png");
nivel3=IMG_LoadTexture(renderer,"nivel3.png");
historia=IMG_LoadTexture(renderer,"historia.png");
ActoI=IMG_LoadTexture(renderer,"ActoI.png");
ActoII=IMG_LoadTexture(renderer,"ActoII.png");
ActoIII=IMG_LoadTexture(renderer,"ActoIII.png");
    character = IMG_LoadTexture(renderer, "assets/personaje/down.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = w;
    rect_character.h = h;

    loopMenu();

	return 0;
}
