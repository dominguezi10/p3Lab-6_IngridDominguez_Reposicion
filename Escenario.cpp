#include "Escenario.h"
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

Escenario::Escenario(string nombre){
    this->nombre = nombre;
    
    matriz = new Item**[11];
    for(int i=0; i<11; i++){
        matriz[i] = new Item*[13];
    }

    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 13; j++){
            matriz[i][j] = new Item(i,j);
            matriz[i][j]->setSalida(" ");
        }
    }
}

Escenario::Escenario(){

}

Item*** Escenario::getMatriz(){
    return matriz;
}

Escenario:: ~Escenario(){
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 13; j++) {
            delete matriz[i][j];
            matriz[i][j] = NULL;
        }
        delete matriz[i];
        matriz[i] = NULL;
    }
    delete[] matriz;
    matriz = NULL;
}

void Escenario:: setNombre(string nombre){
    this->nombre = nombre;
}

void Escenario::Impresion(){
    for(int i = 0; i<11; i++){
        for(int j = 0; j<13; j++){

        }
    }
}