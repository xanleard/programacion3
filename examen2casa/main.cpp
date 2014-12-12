#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int fila;int columna;
int ganados=0;int perdidos=0;int out=0;
int arreglo[5][5];
bool Bool;
int cx;int cy;
int can_min;

void ingresarminas(){
    int contador=0;
    while(contador<5){
        cx=rand()%5;
        cy=rand()%5;
        if(arreglo[cx][cy]!=-1){
            arreglo[cx][cy]=-1;
            contador++;
        }
    }

}

void creartablero(){
    for(fila=0; fila<5; fila++){
         for(columna=0; columna<5; columna++)
            arreglo[fila][columna]=0;

    }
    ingresarminas();
}
void imprimir(){


for(fila=0; fila<5; fila++){
         for(columna=0; columna<5; columna++){
            if(arreglo[columna][fila]==0 || arreglo[columna][fila]==-1)
                cout<<"|___|";
            /*else if  (arreglo[columna][fila]==-1)
                cout<<"|_^_|";*/
            else if(arreglo[columna][fila]==1  )
                cout<<"|_O_|";
            else if(arreglo[columna][fila]==2  )
                cout<<"|_X_|";
            else
                cout<<".";
         }
        cout<<""<<endl;
    }
}

void menu(){
cout <<"         MENU         "<< endl;
cout <<" 1. reglas del juego "<< endl;
cout <<" 2. Juegar           "<< endl;
cout <<" 3. Resultados           "<< endl;
cout <<" 4. salir            "<< endl;
}
void imprimirbarco(){

cout<<""<<endl;
cout <<"________$$$$$$$$$$________ "<< endl;
cout <<"_____d$$$$$$$$$$$$$b______ "<< endl;
cout <<"_____$$$$$$$$$$$$$$$$_____ "<< endl;
cout <<"____4$$$$$$$$$$$$$$$$F____ "<< endl;
cout <<"____4$$$$$$$$$$$$$$$$F____ "<< endl;
cout <<"____$$$$'_'$$$$'_'$$$$_____"<< endl;
cout <<"_____$$F___4$$F___4$$_____ "<< endl;
cout <<"_____'$F___4$$F___4$'_____ "<< endl;
cout <<"______$$___$$$$___$P______ "<< endl;
cout <<"______4$$$$$'_'$$$$4_____  "<< endl;
cout <<"_______$$$$F__4$$$$_______ "<< endl;
cout <<"________'$$$ee$$$'________ "<< endl;
cout <<"________._*$$$$F4_________ "<< endl;
cout <<"_________$_____.$_________ "<< endl;
cout <<"_________'$$$$$$'_________ "<< endl;
cout <<"__________'$$$$'___________ "<< endl;
cout <<"     Buscaminas Especial   "<< endl;


}
//va a colocar las 5 minas en posisiones randon sin repetir las


void revisar(int x ,int y){
if(x>0){
   if(y>0){
        if(arreglo[x-1][y]==-1)
               can_min++;
        if(arreglo[x-1][y-1]==-1)
                can_min++;
   }else if(y<4){
        if(arreglo[x-1][y+1]==-1)
                can_min++;
   }
}
if(x<4){
        if(arreglo[x+1][y]==-1)
                can_min++;
        if(y>0)
           if(arreglo[x+1][y-1]==-1)
                can_min++;
        if (y<4)
            if(arreglo[x+1][y+1]==-1)
                can_min++;
}
    if(y>0)
        if(arreglo[x][y-1]==-1)
            can_min++;
    if (y<4)
        if(arreglo[x][y+1]==-1)
            can_min++;
}


int main()
{

    imprimirbarco();
    creartablero();
    menu();
    //salto();
    int n;
    do{//

    printf("Introduce un numero: ");
    scanf("%d",&n);
    switch ( n ){
    case 3:
        cout<<"partidas Ganadas :";cout<<ganados <<endl;
        cout<<"partidas Perdidas :";cout<<out <<endl;
        menu();
        Bool=true;
        break;
        case 4:
             Bool=false;
            break;
        case 1:
            int codigo;
            cout<<"Es un Juego basado en el clasico juego "<<endl;
            cout<<"de buscaminas solo que en una version"<<endl;
            cout<<"mas reducida que la origial "<<endl;
            cout<<""<<endl;
            cout<<"juego creado por rudy "<<endl;
            menu();
            Bool=true;
            break;
         case 2:
//             cx=rand()%5;
//             cy=rand()%5;
            //cout <<cx<< endl;
            //cout <<cy<< endl;


            int in=0;
            int op=0;
            do{



            imprimir();
            int x,y;
            do{
                 printf("Introduce Cordenada X 0 a 4: ");
                    scanf("%d",&x);
            }while(x>4 ||x<0);

            do{
                printf("Introduce Cordenada Y 0 a 4: ");
                scanf("%d",&y);
            }while(y>4 || y<0);

            if(arreglo[x][y] == -1){
                arreglo[x][y]=2;

                cout<<"Has perdido"<<endl;
                op=1;
                out++;
                imprimir();
            }else{
                arreglo[x][y]=1;
                in++;
                cout<<"Has Acertado"<<endl;
                revisar(x,y);
                cout<<"Cantidad de minas Cerca :"<<can_min<<endl;
                can_min=0;
            }

            if(in==20){
                cout<<"Has ganado el juego "<<endl;
                ganados++;
                op=1;
            }

            }while(op!=1);
            creartablero();
            menu();
            Bool=true;
            break;


      }
    }while(Bool);



return 0;




}


