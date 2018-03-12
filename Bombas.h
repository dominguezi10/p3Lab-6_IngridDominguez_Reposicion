#include <string>
#include <iostream>
#include "Item.h"
using namespace std;

#ifndef BOMBAS_H
#define BOMBAS_H


//Inicio clase
class Bombas:public Item{

    //Atributos
    private:
        int contador;


    //metodos publicos
    public:
        Bombas();
        Bombas(int, int);

        //metodos accersores / mutadores
        int getContador();
        void setContador(int);

    //Destructor
    ~Bombas();


};//Fin de la clase


#endif
