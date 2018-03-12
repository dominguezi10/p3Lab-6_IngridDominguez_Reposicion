#include <string>
#include <iostream>
//#include "Bombas.h"
#include <vector>
using namespace std;

#ifndef ITEM_H
#define ITEM_H


//Inicio clase
class Item{
    private:
        int x;
        int y;
        string salida;
        //vector<Bombas*> bombas;

    public:
        Item();
        Item(int,int);
        int getX();
        void setX(int);
        int getY();
        void setY(int);
        string getSalida();
        void setSalida(string);

    ~Item();


};
#endif
