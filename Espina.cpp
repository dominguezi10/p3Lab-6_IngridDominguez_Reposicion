#include "Espina.h"
#include "Bombas.h"
#include <iostream>
#include <string>

using namespace std;


Espina::Espina():Bombas(){
    //creo
}

Espina::Espina(int x, int y):Bombas(x, y){
    //creo
}

void Espina::aumentarBombas(){
    bombasPuestas++;
}

Espina::~Espina(){
}

