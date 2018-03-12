#include "Normal.h"
#include "Bombas.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

Normal::Normal():Bombas(){
    this->alcance = rand()% 4+1;
}

Normal::Normal(int x,  int y):Bombas(x, y){
    this->alcance = rand()% 4+1;
}

int Normal::getAlcance(){
    return alcance;
}

void Normal::setAlcance(int alcance){
    this->alcance = alcance;
}

Normal::~Normal(){
}


