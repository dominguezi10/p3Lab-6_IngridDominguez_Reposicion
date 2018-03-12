#include <string>
#include <iostream>
#include "Escenario.h"
#include <vector>
using namespace std;

#ifndef TREN_H
#define TREN_H


//Inicio clase
class Tren: public Escenario{
    private:
        vector<int> posiciones;
        int dondeEstaX;
        int dondeEstaY;
        int tipoBomba;

    public:
        Tren(string, int, int);
        void setDondeEstaX(int);
        int getDondeEstaX();

        void setDondeEstaY(int);
        int getDondeEstaY();       
        int tipoBombaUsar();

        ~Tren();

};
#endif