
#include<SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<stdlib.h>
#include<list>
using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*game_background,*pelotita_buena,*pelotita_mala,*game_over,*historia;
SDL_Rect rect_background,rect_pelotita;

//programa para hacer las imagenes paint y adobe cc photoshop 5


float velocidad=0.01;//variable  que incrementa la velocidad
int puntos=0;// lleva el conteo de puntos

void loopMenu();

//funcion que nos da unapequeña introduccion del juego y el creador
void loophistoria(){
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

                        loopMenu();
                }
            }
        }

        SDL_RenderCopy(renderer, historia, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }

}
//funcion que nos muestra en pantalla cuadnno el juego a terminado
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
                if(Event.key.keysym.sym == SDLK_RETURN ){

                        loopMenu();
                }
            }
        }

        SDL_RenderCopy(renderer, game_over, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}


void loopJuego(){

    list<float>pelotitas_x;
    pelotitas_x.push_back(0);
    pelotitas_x.push_back(100);
    pelotitas_x.push_back(200);
    pelotitas_x.push_back(300);


    list<float>pelotitas_y;  //Posiciones de la pelotitas en Y en una lista
    pelotitas_y.push_back(0);
    pelotitas_y.push_back(68);
    pelotitas_y.push_back(136);
    pelotitas_y.push_back(204);


    //float pelotita_x=0;
    bool setvisible=true;

    int var=0;//
    while(true){
        while(SDL_PollEvent(&Event)){
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE )
                        return;
                        //loopMenu();
            }
                if(Event.type==SDL_MOUSEBUTTONDOWN){
                    int clic_x,clic_y;
                    SDL_GetMouseState(&clic_x,&clic_y);
                    std::cout<<clic_x<<","<<clic_y<<std::endl;

                for(list<float>::iterator i=pelotitas_x.begin();
                        i!=pelotitas_x.end();
                        i++){

                    //if(clic_x<66+(*i) && clic_x>(*i) && clic_y<66 && clic_y>0){
                    if(clic_y<66+(*i) && clic_y>(*i) && clic_x<66 && clic_x>0){//

                        pelotitas_x.erase(i);
                        puntos+=10;
                        var++;

                        break;
                    }

                }
                }


                //_______________




//if que nos muestra la funcion de loopgameover si el juego ya termino
                if(var==4){
                    velocidad=0.01;
                    loopGameover();

                    break;
                }

            }

            for(list<float>::iterator i=pelotitas_x.begin();
                        i!=pelotitas_x.end();
                        i++){



//_____________



//______________
                    //(*i)+=0.01;
                    (*i)+=velocidad;//variable que incrementa segund la condicon dada
                    if((*i)>500)
                    (*i)=0;
                }



        SDL_RenderCopy(renderer, game_background, NULL, &rect_background);

                    rect_pelotita.x=0;



        //SDL_RenderCopy(renderer, pelotita_buena, NULL, &rect_pelotita);

       for(list<float>::iterator i=pelotitas_x.begin();
                        i!=pelotitas_x.end();
                        i++) {
        rect_pelotita.y=(*i);// movimiento en eje y

                SDL_RenderCopy(renderer, pelotita_mala, NULL, &rect_pelotita);
       }

       SDL_RenderPresent(renderer);
    }

}




void loopMenu(){
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

                        loopJuego();
                }
                //para mostras una historia y origen del juego
                 if(Event.key.keysym.sym == SDLK_f ){

                        loophistoria();
                }
                //invremneta la velocidad del juego
                if(Event.key.keysym.sym == SDLK_v ){
                        velocidad=0.10;

                        loopJuego();
                }
            }
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderPresent(renderer);
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
    background = IMG_LoadTexture(renderer,"menu.png");//imagen de menu hechas por mi
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;



    game_background = IMG_LoadTexture(renderer,"background.png");//imagen de game brackground hechas por mi

    game_over= IMG_LoadTexture(renderer,"game_over.png");//imagen de game over hechas por mi
    historia=IMG_LoadTexture(renderer,"historia.png");//magen del modo historia hecas por mi

    pelotita_mala = IMG_LoadTexture(renderer,"pelotita_mala.png");
    pelotita_buena = IMG_LoadTexture(renderer,"pelotita_Buena.png");
    SDL_QueryTexture(pelotita_buena, NULL, NULL, &rect_pelotita.w, &rect_pelotita.h);
    rect_pelotita.x=0;
    rect_pelotita.y=0;

    loopMenu();
    //loopGameover();

	return 0;
}
