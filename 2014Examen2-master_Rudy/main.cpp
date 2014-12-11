#include "Lista.h"
#include "ArbolTrinario.h"
#include "Evaluador.h"
#include <fstream>
#include <list>
#include <vector>
#include <math.h>

#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <algorithm>
using namespace std;

//1 a realizar estan ubicados en el archivo Lista.h

float obtenerPromedio(std::list<float> mi_lista)
{
    float sum=0;
    float num=0;
    float prom=0;
    int cont=0;
  while( !mi_lista.empty() )
    {
      num = mi_lista.front();
      //cout <<num << endl;
      sum += num;
      cont++;
      mi_lista.pop_front();
    }
    prom=sum/cont;

    return prom;
}

int obtenerMediana(std::vector<int> mi_vector)
{
    float numer_Ve=(mi_vector.size()/2)+.5;
    sort(mi_vector.begin(),mi_vector.end());
    return mi_vector[numer_Ve];

}

bool existeEnArchivo(string nombre_archivo, string cadena)
{
     ifstream in(nombre_archivo.c_str());
        string str1;
        int con;
        while (in.good()){
            in>>str1;
            con =strcmp(str1.c_str(), cadena.c_str());
            if(con == 0){
                return true;
           }
        }
    return false;
}

char obtenerUltimaLetra(string nombre_archivo)
{
        ifstream in(nombre_archivo.c_str());
        char come;
        while(in>>come){

        }
        return come;


}

int contarEnArbol(NodoTrinario* raiz, int num)
{


    //return 0;
//    int r=0;   // 0 indica que lo encontre
//
//     if(raiz==NULL)
//        return r;
//
//     if(num<raiz->num)
//         r = contarEnArbol(raiz->izq, num);
//
//     else if(num> raiz->num)
//         r = contarEnArbol(raiz->der, num);
//
//     else
//        r = 1;   // son iguales, lo encontre
//
//     return r;

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

