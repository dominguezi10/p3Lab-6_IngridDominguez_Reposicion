#include <string>
#include <iostream>
#include "Item.h"
#include "Bombas.h"
#include <vector>
using namespace std;

#ifndef ESCENARIO_H
#define ESCENARIO_H


//Inicio clase
class Escenario{
    private:
        string nombre;
        Item*** matriz;
        vector<Bombas*> bombas;

    public:
        Escenario(string);
        Escenario();

        void setNombre(string);
        Item*** getMatriz();
        void Impresion();
        ~Escenario();


};
#endif
