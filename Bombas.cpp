#include "Bombas.h"
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

//Cosntructor 1
Bombas::Bombas(){
    this->contador=3;
}//Fin constructor


Bombas::Bombas(int x , int y):Item(x,y){
     this->contador=3;
}

int Bombas::getContador(){
    return contador;
}

void Bombas:: setContador(int contador){

    this->contador=contador;

}

Bombas::~Bombas(){

}
