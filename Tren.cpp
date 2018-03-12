#include "Escenario.h"
#include "Tren.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Tren::Tren(string nombre, int dondeEstaX, int dondeEstaY) :Escenario(nombre){
    this->dondeEstaX = dondeEstaX;
    this->dondeEstaY = dondeEstaY;
}

int Tren::  getDondeEstaX(){
    return dondeEstaX;
}

void Tren:: setDondeEstaX(int dondeEstaX){
    this->dondeEstaX = dondeEstaX;
}

int Tren::  getDondeEstaY(){
    return dondeEstaY;
}

void Tren:: setDondeEstaY(int dondeEstaY){
    this->dondeEstaY = dondeEstaY;
}

int Tren:: tipoBombaUsar(){
    tipoBomba =  rand()% 3+1;
    return tipoBomba;
}

Tren:: ~Tren(){
}