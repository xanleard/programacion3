#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int ganados=0;int perdidos=0;int out=0;
 int fila;int columna;
string arreglo[5][5];
int cx;int cy;//variable para cordenad de barco
bool Bool;
void creartablero(){

    for(fila=0; fila<5; fila++){
         for(columna=0; columna<5; columna++)

            arreglo[fila][columna]="|___|";
         cout <<""<< endl;
    }
}
void imprimir(){

for(fila=0; fila<5; fila++){
         for(columna=0; columna<5; columna++)
            cout <<arreglo[columna][fila];
         cout <<""<< endl;
    }
}
//------Arreglo dos para barco oculto ------
int fila2;int columna2;
string arreglo2[5][5];

void creartablero2(){

    for(fila2=0; fila2<5; fila2++){
         for(columna2=0; columna2<5; columna2++)

            arreglo2[fila2][columna2]="|___|";
         cout <<""<< endl;
    }
}
void imprimir2(){

for(fila2=0; fila2<5; fila2++){
         for(columna2=0; columna2<5; columna2++)
            cout <<arreglo2[columna2][fila2];
         cout <<""<< endl;
    }
}

//-----------------

//void generanumala(){
//
//             cx=rand()%6;
//
//
//             cy=rand()%6;
//
//                arreglo2[cy][cx]="barco";
//}

void imprimirbarco(){
cout <<"        Batalla Naval          "<< endl;

cout <<"            |*                 "<< endl;
cout <<"            |_*                "<< endl;
cout <<"            |__*               "<< endl;
cout <<"            |___*              "<< endl;
cout <<"            |____*             "<< endl;
cout <<"            |_____*            "<< endl;
cout <<"            |______*           "<< endl;
cout <<"    ________|_____________     "<< endl;
cout <<"   *                      /    "<< endl;
cout <<"    *____________________/    "<< endl;
cout <<""<< endl;
}
void menu(){
cout <<"    MENU             "<< endl;
cout <<" 1. reglas del juego "<< endl;
cout <<" 2. Juegar           "<< endl;
cout <<" 3. Resultados           "<< endl;
cout <<" 4. salir            "<< endl;
}

int main()
{

    imprimirbarco();
    creartablero();
    menu();
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
            cout<<"de batalla naval solo que en una version"<<endl;
            cout<<"mas reducida que la origial "<<endl;
            cout<<""<<endl;
            cout<<"juego creado por rudy "<<endl;
            menu();
            Bool=true;
            break;
         case 2:
             cx=rand()%5;
             cy=rand()%5;
            //cout <<cx<< endl;
            //cout <<cy<< endl;

            int in=0;
            int op=0;
            do{



            imprimir();
            int x,y;
            printf("Introduce cordenada x 0 a 4: ");
            scanf("%d",&x);

            printf("Introduce cordenada y 0 a 4: ");
            scanf("%d",&y);

            if(x+1!=cx && y+1!=cy){
                arreglo[x][y]="|_O_|";
                in++;
                cout<<"Has Fallado"<<endl;
            }else{
                arreglo[x][y]="|_x_|";

                cout<<"Has Acertado"<<endl;
                ganados++;
                op=1;
                imprimir();
            }
            if(in==3){
                cout<<"se te acabado los turnos"<<endl;
                out++;
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
