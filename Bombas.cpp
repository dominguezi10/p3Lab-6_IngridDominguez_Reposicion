#include "Bombas.h"
#include <iostream>
#include <string>

using namespace std;

//Cosntructor 1
Bombas::Bombas(){
    this->contador=3;
}//Fin constructor


int Bombas::getContador(){
    return contador;
}

void Bombas:: setContador(int contador){

    this->contador=contador;

}

Bombas::~Bombas(){

}
