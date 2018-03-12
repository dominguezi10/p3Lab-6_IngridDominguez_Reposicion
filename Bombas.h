#include <string>
#include <iostream>

using namespace std;

#ifndef BOMBAS_H
#define BOMBAS_H


//Inicio clase
class Bombas{

    //Atributos
    private:
        int contador;


    //metodos publicos
    public:
        Bombas();

        //metodos accersores / mutadores
        int getContador();
        void setContador(int);

    //Destructor
    ~Bombas();


};//Fin de la clase


#endif
