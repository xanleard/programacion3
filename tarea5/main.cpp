
#include<SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<list>
#include "PersonajeJugador.h"
#include "NPC.h"
#include "NPC2.h"
#include <fstream>
#include <vector>
#include <stdlib.h>     /* srand, rand */

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character,*tileset_texture;
SDL_Rect rect_background,rect_character;


class Tile{
public:
    int fuente_x;
    int fuente_y;
    int destino_x;
    int destino_y;
    Tile(int fuente_x,int fuente_y,int destino_x,int destino_y ){
        this->fuente_x=fuente_x;
        this->fuente_y=fuente_y;
        this->destino_x=destino_x;
        this->destino_y=destino_y;
    }
};

vector<Tile*>cargartiles(string nombre_archivo){
    vector<Tile*>tiles;
    ifstream archivo(nombre_archivo.c_str());

    for(int destino_y=0;destino_y<8;destino_y++){
            for(int destino_x=0;destino_x<6;destino_x++){
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

void dibujarTile(SDL_Texture *tileset_texture,SDL_Renderer *renderer,int fuente_x,int fuente_y,int destino_x,int destino_y){
  SDL_Rect fuente,destino;
        fuente.x=32*fuente_x;
        fuente.y=32*fuente_y;
        fuente.w=32;
        fuente.h=32;

        destino.x=32*destino_x;
        destino.y=32*destino_y;
        destino.w=32;
        destino.h=32;

        SDL_RenderCopy(renderer,tileset_texture,&fuente,&destino);
}


int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
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

    character = IMG_LoadTexture(renderer, "assets/personaje/down.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = w;
    rect_character.h = h;


    list<Personaje*>personajes;
    personajes.push_back(new PersonajeJugador (0,0,renderer,&personajes));
//    personajes.push_back(new NPC2 (50,50,renderer,&personajes));//el del agua
//    personajes.push_back(new NPC2 (50,70,renderer,&personajes));//el del agua
//    personajes.push_back(new NPC2 (20,50,renderer,&personajes));//el del agua
//    personajes.push_back(new NPC2 (20,70,renderer,&personajes));//el del agua
    personajes.push_back(new NPC2 (35,60,renderer,&personajes));//el del agua



    personajes.push_back(new NPC (160,0,renderer,&personajes));//derecha
    personajes.push_back(new NPC (160,30,renderer,&personajes));//derecha
    personajes.push_back(new NPC (160,100,renderer,&personajes));//derecha
    personajes.push_back(new NPC (160,130,renderer,&personajes));//derecha
    personajes.push_back(new NPC (160,160,renderer,&personajes));//derecha
    personajes.push_back(new NPC (130,160,renderer,&personajes));//iquierda
    personajes.push_back(new NPC (100,160,renderer,&personajes));//iquierda
    personajes.push_back(new NPC (70,160,renderer,&personajes));//iquierda
    personajes.push_back(new NPC (40,160,renderer,&personajes));//iquierda
    personajes.push_back(new NPC (10,160,renderer,&personajes));//iquierda
    //hielo
    personajes.push_back(new NPC (300,130,renderer,&personajes));
    personajes.push_back(new NPC (300,160,renderer,&personajes));
    personajes.push_back(new NPC (300,190,renderer,&personajes));
    personajes.push_back(new NPC (330,130,renderer,&personajes));
    personajes.push_back(new NPC (330,160,renderer,&personajes));
    personajes.push_back(new NPC (330,190,renderer,&personajes));
    //rocas
      personajes.push_back(new NPC (480,0,renderer,&personajes));
    personajes.push_back(new NPC (480,30,renderer,&personajes));

    personajes.push_back(new NPC (480,60,renderer,&personajes));
    personajes.push_back(new NPC (480,90,renderer,&personajes));
    personajes.push_back(new NPC (480,120,renderer,&personajes));
    personajes.push_back(new NPC (480,150,renderer,&personajes));
    personajes.push_back(new NPC (480,180,renderer,&personajes));
    personajes.push_back(new NPC (480,230,renderer,&personajes));
    personajes.push_back(new NPC (430,230,renderer,&personajes));
    personajes.push_back(new NPC (400,230,renderer,&personajes));
    personajes.push_back(new NPC (370,230,renderer,&personajes));

    personajes.push_back(new NPC (340,230,renderer,&personajes));
    personajes.push_back(new NPC (310,230,renderer,&personajes));
    personajes.push_back(new NPC (280,230,renderer,&personajes));

    personajes.push_back(new NPC (250,230,renderer,&personajes));
    personajes.push_back(new NPC (220,230,renderer,&personajes));
    personajes.push_back(new NPC (190,230,renderer,&personajes));

    personajes.push_back(new NPC (160,230,renderer,&personajes));
    personajes.push_back(new NPC (130,230,renderer,&personajes));
    personajes.push_back(new NPC (100,230,renderer,&personajes));

    personajes.push_back(new NPC (70,230,renderer,&personajes));
    personajes.push_back(new NPC (40,230,renderer,&personajes));
    personajes.push_back(new NPC (10,230,renderer,&personajes));












    SDL_Texture *tileset_texture=IMG_LoadTexture(renderer, "assets/tileds.png");
    vector<Tile*>tiles=cargartiles("assets/miarchivo.txt");



    //Main Loop
    int frame=0;
    while(true)
    {
        frame++;
        //if(frame%100==0)
           // personajes.push_back(new NPC (100,rand() % 100,renderer,&personajes));
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
        }

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->logic((Uint8*)SDL_GetKeyboardState( NULL ));




        SDL_RenderCopy(renderer, background, NULL, &rect_background);


        for(int i=0;i<tiles.size();i++){
            dibujarTile(tileset_texture,renderer,
                        tiles[i]->fuente_x,tiles[i]->fuente_y,
                        tiles[i]->destino_x,tiles[i]->destino_y);
        }


        dibujarTile(tileset_texture,renderer,0,6,5,0);
        dibujarTile(tileset_texture,renderer,0,6,5,1);
        dibujarTile(tileset_texture,renderer,0,6,5,3);
        dibujarTile(tileset_texture,renderer,0,6,5,4);
        dibujarTile(tileset_texture,renderer,0,6,5,5);
        dibujarTile(tileset_texture,renderer,0,6,4,5);
        dibujarTile(tileset_texture,renderer,0,6,3,5);
        dibujarTile(tileset_texture,renderer,0,6,2,5);
        dibujarTile(tileset_texture,renderer,0,6,1,5);
        dibujarTile(tileset_texture,renderer,0,6,0,5);
        //dibujarTile(tileset_texture,renderer,0,6,3,4);
        dibujarTile(tileset_texture,renderer,15,14,0,1);
        dibujarTile(tileset_texture,renderer,16,14,1,1); dibujarTile(tileset_texture,renderer,17,14,2,1);
        dibujarTile(tileset_texture,renderer,15,15,0,2);
        dibujarTile(tileset_texture,renderer,16,15,1,2);dibujarTile(tileset_texture,renderer,17,15,2,2);
         dibujarTile(tileset_texture,renderer,15,16,0,3);
         dibujarTile(tileset_texture,renderer,16,16,1,3);dibujarTile(tileset_texture,renderer,17,16,2,3);

         //hielo
          dibujarTile(tileset_texture,renderer,18,14,9,4); dibujarTile(tileset_texture,renderer,19,14,10,4);dibujarTile(tileset_texture,renderer,20,14,11,4);
          dibujarTile(tileset_texture,renderer,18,15,9,5); dibujarTile(tileset_texture,renderer,19,15,10,5);dibujarTile(tileset_texture,renderer,20,15,11,5);
          dibujarTile(tileset_texture,renderer,18,16,9,6); dibujarTile(tileset_texture,renderer,19,16,10,6);dibujarTile(tileset_texture,renderer,20,16,11,6);
        //
        dibujarTile(tileset_texture,renderer,30,18,15,0);
        dibujarTile(tileset_texture,renderer,30,18,15,1);
        dibujarTile(tileset_texture,renderer,30,18,15,2);
        dibujarTile(tileset_texture,renderer,30,18,15,3);
        dibujarTile(tileset_texture,renderer,30,18,15,4);
        dibujarTile(tileset_texture,renderer,30,18,15,5);
        dibujarTile(tileset_texture,renderer,30,18,15,6);
        dibujarTile(tileset_texture,renderer,30,18,15,7);
        dibujarTile(tileset_texture,renderer,30,18,14,7);
        dibujarTile(tileset_texture,renderer,30,18,13,7);
        dibujarTile(tileset_texture,renderer,30,18,12,7);
        dibujarTile(tileset_texture,renderer,30,18,11,7);
        dibujarTile(tileset_texture,renderer,30,18,10,7);
        dibujarTile(tileset_texture,renderer,30,18,9,7);
        dibujarTile(tileset_texture,renderer,30,18,8,7);
        dibujarTile(tileset_texture,renderer,30,18,7,7);
        dibujarTile(tileset_texture,renderer,30,18,6,7);
        dibujarTile(tileset_texture,renderer,30,18,5,7);
        dibujarTile(tileset_texture,renderer,30,18,4,7);
        dibujarTile(tileset_texture,renderer,30,18,3,7);
        dibujarTile(tileset_texture,renderer,30,18,2,7);
        dibujarTile(tileset_texture,renderer,30,18,1,7);
        dibujarTile(tileset_texture,renderer,30,18,0,7);





        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->render(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(16.66);
    }

	return 0;
}
