#include <string>
#include <iostream>
#include "Bombas.h"
using namespace std;

#ifndef ESPINA_H
#define ESPINA_H

class Espina: public Bombas{
    private:
        int bombasPuestas;

    public:
        Espina();
        Espina(int, int);
        
        int getCantidad();
        void aumentarBombas();
        
    ~Espina();


};


#endif
