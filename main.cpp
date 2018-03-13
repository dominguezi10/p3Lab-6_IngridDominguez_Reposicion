#include <iostream>
using namespace std;
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <vector>
#include <sstream>

#include "Escenario.h"
#include "Item.h"
#include "Jugador.h"
#include "Tren.h"
#include "Invisible.h"
#include "Bombas.h"
#include "V.h"
#include "Normal.h"
#include "Espina.h"
#include <typeinfo>


Escenario* escenario;
void salir();
int menu();
int kbhit(void);

Jugador* crearJugador(int);
int tipoBomba();
void movimientoTren();
void movimientoConMatriz(Item***, Jugador*, int);
int validacionMovimiento(Item***, int, int);
void impresion(Item***);
void movimientoVillanos(Item***&);
int verInstancia(Item***);
void explotarBombas(Item***&);
int gane(Item***);

int main(void){
    
    Jugador* jugador;
    int OpcionJuego;
    string nombreE;
    
    while (OpcionJuego != 3) {
        erase();
        OpcionJuego = menu();
        switch (OpcionJuego)
        {
        case 1: {
            erase();
            move(0, 20);
            printw("Escenario 1 Invisible");
            move(2,1);
            nombreE = "Invisible";
            //escenario->setNombre(nombreE);
            jugador = crearJugador(1);

            escenario = new Invisible(nombreE);
            
            int opcion ;
            opcion = tipoBomba();

            //movimientoInvisible();
            //movimiento();
            Item*** matriz  = escenario->getMatriz();
            movimientoConMatriz(matriz, jugador, opcion);
            refresh();
            usleep(1000000);
            
            refresh();
            break;
        }
        case 2: {
            erase();
            move(0, 20);
            printw("Opcion 2 Tren");
            nombreE = "Tren";
            move(2,1);
            nombreE = "Invisible";
            //escenario->setNombre(nombreE);
            jugador = crearJugador(2);

            escenario = new Tren(nombreE, 0,0);
            movimientoTren();
            refresh();
            usleep(1000000);
            //movimiento();
            break;
        }
        case 3:{
            salir();
        }
        }
    }

}

int menu(){
    initscr();
    erase();
    int x, y;
    getmaxyx(stdscr, y, x);
    move(0, (x / 2 - 6));
    if (has_colors()) {
        start_color();
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        //attron(COLOR_PAIR(1));
        move(1, 5);
        printw("Bombermang !!");
        //attroff(COLOR_PAIR(1));
        
        attron(COLOR_PAIR(2));
        move(2, 1);
        printw("1) Escenario Invisible\n");
        move(3, 1);
        printw("2) El Tren \n");
        move(4, 1);
        printw("3) Salir \n");
        attroff(COLOR_PAIR(2));
    }
    int enX = 0;
    int enY = 2;
    int tecla;
    move(enY, enX);
    refresh();
    while (true)
    {
        noecho();
        tecla = getch();
        if (tecla == 10)
        {
            if (enY == 2)
            {
                return 1;
            }
            if (enY == 3)
            {
                return 2;
            }
            if (enY == 4)
            {
                return 3;
            }
            if (enY == 5)
            {
                return 4;
            }
        }
        else
        {
            //printw("%i",tecla);
            if (tecla == 65 && enY > 2)
            {
                //printw(" arriba");
                enY = enY - 1;
                move(enY, enX);
            }
            else if (tecla == 66 && enY <= 4)
            {
                //printw(" abajo");
                enY = enY + 1;
                move(enY, enX);
            }
            else
            {
                //No hara nada
            }
        }
        refresh();
    }
    echo();
    return 0;
}

Jugador* crearJugador(int tipo){
    erase();
    char* nombre = new char[50];
    move(0,5);
    printw("---- Crear Jugador -----");
    move(1,0);
    echo();
    printw("Ingresa el nombre del jugador: ");
    scanw("%s", nombre);
    stringstream eso;
    eso << nombre; 
    string nombreJ;

    getline(eso, nombreJ);
    refresh();

    Jugador* jugador = new Jugador(nombreJ, 1 ,tipo, 0, 0);
    return jugador;
}

int tipoBomba(){
    char este[10];
    move(3,0);
    printw("Opcion de nomba: ");
    move(4,0);
    printw("1.- Normal");
    move(5,0);
    printw("2.- Espina ");
    move(6,0);
    printw("3.- Forma V ");
    move(7,0);
    scanw("%s", este);

    move(7,0);
    printw("%s", este);

    int opcion;
    opcion= atoi(este);
    return opcion;
}

void salir()
{
    int x, y;
    getmaxyx(stdscr, y, x);
    erase();
    if (has_colors)
    {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(y / 2, (x / 2 - 6));
        printw("Saliendo del Juego");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        printw(".");
        refresh();
        usleep(1000000 / 2);
        attroff(COLOR_PAIR(1));
    }
    endwin();
    exit(0);
}



void movimientoTren(){
    erase();
    char ser = '*';
    int x, y;
    int enX;
    int enY;
    getmaxyx(stdscr, y, x);
    
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();
    move(0,0);
    printw("A JUGAR...... (MUEVETE!!)");
    refresh();
    int direccion = 3;
    enX = 0;
    enY = 2;
    curs_set(0);
    erase();
    int tecla;
    tecla = getch();
    while (true)
    {
        
        if (kbhit())
        {
            tecla = getch();
            //ARRIBA
            if (tecla == 119)
            {
                direccion = 1;
            }
            //IZQUIERDA
            if (tecla == 97)
            {
                direccion = 2;
            }
            //DERECHA
            if (tecla == 100)
            {
                direccion = 3;
            }
            //ABAJO
            if (tecla == 115)
            {
                direccion = 4;
            }
            
        }
        if ((enX > -1 && enY > 1) && (enX < 13 && enY < 11))
        {
            move(enY, enX);
            printw("*");
            refresh();
            usleep(1000000 / 4);
            if (direccion == 1)
            {
                enY = enY - 1;
                move(enY + 1, enX);
                printw(" ");
            }
            if (direccion == 2)
            {
                enX = enX - 1;
                move(enY, enX + 1);
                printw(" ");
            }
            if (direccion == 3)
            {
                enX = enX + 1;
                move(enY, enX - 1);
                printw(" ");
            }
            if (direccion == 4)
            {
                enY = enY + 1;
                move(enY - 1, enX);
                printw(" ");
            }
        }
        else
        {
            break;
        }
    }
    move(y / 2, (x / 2 - 4));
    printw("Perdió!!");
    refresh();
    usleep(1000000 / 2);
    curs_set(1);
}







/////*****
void movimientoConMatriz(Item***  matriz, Jugador* jugador, int opcionBomba){
    erase();
    noecho();

    //// los villanos
    Jugador* villano1 = new Jugador("in",1,2, 0,12);
    Jugador* villano2 = new Jugador("in",1,2, 10,12);
    Jugador* villano3 = new Jugador("in",1,2, 5,6);
    Jugador* villano4 = new Jugador("in",1,2, 10,0);
    
    ///

    //char ser = '*';
    int x, y;
    int posicionX;
    int posicionY;
    getmaxyx(stdscr, y, x);
    move(y / 2, x / 2 - 18);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printw("Presione cualquier tecla para inciar.");
    move(y / 2 + 1, x / 2 - 29);
    printw("*Las bombas se muestra cuando presionas Enter!");
    refresh();
    attroff(COLOR_PAIR(1));
    int tecla;
    tecla = getch();
    while (tecla<=0){
        tecla = getch();
    }
    
    int direccion = 3;
    posicionX = 0;
    posicionY = 0;
    curs_set(0);
    erase();
    matriz[0][0] = jugador;
    matriz[0][0]->setSalida("*");

    matriz[0][12] = villano1;
    matriz[0][12]->setSalida("X");
    matriz[10][12] = villano2;
    matriz[10][12]->setSalida("X");
    matriz[5][6] = villano3;
    matriz[5][6]->setSalida("X");
    matriz[10][0] = villano4;
    matriz[10][0]->setSalida("X");

    int bombasAPoner;
    bombasAPoner = rand()%3+1;

    for(int i=0; i<11; i++){
        for(int j = 0; j<13; j++){
            if (( j%2!=0 && i%2!=0)){    
                matriz[i][j]->setSalida("@");
            }
        }
    }

    for(int i=0; i<bombasAPoner; i++){
        int pX =-1, pY=-1;
        int condicion;
        condicion = 0;
        while( condicion != 1 ){
            pX = rand()%5+1;
            pY = rand()%5+1;
            condicion = validacionMovimiento(matriz, pY, pX);
            
        }
        

        if( (opcionBomba == 1 && condicion ==1)&& (pX>=0 && pY>=0)){
            Item* normal = new Normal(pY, pX);
            matriz[pY][pX] = normal;
            matriz[pY][pX]->setSalida("O");
            //impresion(matriz);
        }

        if( (opcionBomba == 2 && condicion ==1)&& (pX>=0 && pY>=0)){
            Item* espina = new Normal(pY, pX);
            matriz[pY][pX] = espina;
            matriz[pY][pX]->setSalida("O");
            //impresion(matriz);
        }

        if( (opcionBomba == 3 && condicion ==1)&& (pX>=0 && pY>=0)){
            Item* v = new V(pY, pX);
            matriz[pY][pX] = v;
            matriz[pY][pX]->setSalida("O");
            //impresion(matriz);
        }
    }

    move(0,20);
    printw("Vidas");
    
    int vida = rand()%3+1;
    move(1,20);
    printw("%i", vida);
    
    int condicionBomba;
    condicionBomba = 1;
    int pasos;
    pasos = 0;
    
    int condicionJuego;
    while (true){
        refresh();
        impresion(matriz);


        refresh();
        
        tecla = getch();
            //ARRIBA
        if (tecla == 119){
            direccion = 1;
        }
        //IZQUIERDA
        if (tecla == 97){
            direccion = 2;
        }
        //DERECHA
        if (tecla == 100){
            direccion = 3;
        }
        //ABAJO
        if (tecla == 115){
            direccion = 4;
        }

        if(tecla==10 && condicionBomba == 0){
            
            if( ( (posicionX >=0 && posicionY >=0) && (posicionX < 13 && posicionY < 11) ) ){
                matriz[posicionY][posicionX] = new Item();
                Item* normal = new Normal(posicionY, posicionX);
                matriz[posicionY][posicionX] = normal;
                matriz[posicionY][posicionX]->setSalida("O");

                int indicador;
                int contadorEnemigos;
                contadorEnemigos = 0;
                indicador = 0;
                int condicion;
                if(posicionY+1<11){
                    condicion = validacionMovimiento(matriz, posicionY+1, posicionX);
                    if(condicion== 1){
                        posicionY = posicionY+1;
                        matriz[posicionY][posicionX] = jugador;
                        matriz[posicionY][posicionX]->setSalida("*");
                        indicador++;
                        
                    }
                }
                
                if(posicionY-1>=0 && indicador == 0){
                    condicion = validacionMovimiento(matriz, posicionY-1, posicionX);
                    if(condicion== 1){
                        posicionY = posicionY-1;
                        matriz[posicionY][posicionX] = jugador;
                        matriz[posicionY][posicionX]->setSalida("*");
                        indicador++;
                    }else{
                        indicador = 0;
                    }
                }

                if(posicionX-1>=0 && indicador == 0){
                    condicion = validacionMovimiento(matriz, posicionY, posicionX-1);
                    if(condicion== 1){
                        posicionX = posicionX-1;
                        matriz[posicionY][posicionX] = jugador;
                        matriz[posicionY][posicionX]->setSalida("*");
                        indicador++;
                    }else{
                        indicador = 0;
                    }
                }

                if(posicionX+1<13 && indicador == 0){
                    condicion = validacionMovimiento(matriz, posicionY, posicionX+1);
                    if(condicion== 1){
                        posicionX  = posicionX+1;
                        matriz[posicionY][posicionX] = jugador;
                        matriz[posicionY][posicionX]->setSalida("*");
                        indicador++;
                    }else{
                        indicador = 0;
                    }
                }

                contadorEnemigos = gane(matriz);
                move(20,10);
            printw("%i", contadorEnemigos);
                if(contadorEnemigos == 0){
                    condicionJuego = 1;
                    break;
                }
            impresion(matriz);
            //refresh;
            }

            condicionBomba = 1;
        }
            
            
        

        

        int condicion;
        if ( ( (posicionX >=0 && posicionY >=0) && (posicionX < 13 && posicionY < 11) )   && (direccion>=1 && direccion<=4) ){
            if(direccion == 1  && (posicionY-1 >=0) ){
                condicion = validacionMovimiento(matriz,(posicionY - 1) , posicionX);
                if(condicion == 1){
                    posicionY = posicionY - 1;
                    matriz[posicionY][posicionX] = jugador;
                    matriz[posicionY][posicionX]->setSalida("*");
                    matriz[posicionY+1][posicionX] = new Item();
                    matriz[posicionY+1][posicionX]->setSalida(" ");
                    
                    
                }else if(condicion == 3){
                    vida--;
                    move(0,20);
                    printw("Vidas");
    
                    move(1,20);
                    printw("%i", vida);
                    
                }
            }

            if(direccion == 2  && (posicionX-1 >=0) ){
                condicion = validacionMovimiento(matriz, posicionY  , posicionX-1);
                if(condicion == 1){
                    posicionX = posicionX - 1;
                    matriz[posicionY][posicionX] = jugador;
                    matriz[posicionY][posicionX]->setSalida("*");
                    matriz[posicionY][posicionX+1] = new Item();
                    matriz[posicionY][posicionX+1]->setSalida(" ");
                }else if(condicion == 3){
                    vida--;
                    move(0,20);
                    printw("Vidas");
    
                    move(1,20);
                    printw("%i", vida);
                }
            }

             if (direccion == 3 && (posicionX+1 <13))
            {
                condicion = validacionMovimiento(matriz, posicionY  , posicionX+1);
                if(condicion == 1){
                    posicionX = posicionX + 1;
                    matriz[posicionY][posicionX] = jugador;
                    matriz[posicionY][posicionX]->setSalida("*");
                    matriz[posicionY][posicionX-1] = new Item();
                    matriz[posicionY][posicionX-1]->setSalida(" ");
                }else if(condicion == 3){
                    vida--;
                    move(0,20);
                    printw("Vidas");
    
                    move(1,20);
                    printw("%i", vida);
                }
            }
            if (direccion == 4 && (posicionY+1 <11) ){
                condicion = validacionMovimiento(matriz, posicionY+1, posicionX);
                if(condicion == 1){
                    posicionY = posicionY + 1;
                    matriz[posicionY][posicionX] = jugador;
                    matriz[posicionY][posicionX]->setSalida("*");
                    matriz[posicionY-1][posicionX] = new Item();
                    matriz[posicionY-1][posicionX]->setSalida(" ");
                }else if(condicion == 3){
                    vida--;
                    move(0,20);
                    printw("Vidas");
    
                    move(1,20);
                    printw("%i", vida);
                    
                }
            }
            
            if(condicionBomba == 1){
                pasos++;
                move(0,45);
                printw("Tiempo-Bombas");
                move(1,45);
                printw("%i", pasos);
                refresh;
            }

            if(pasos==3){
                condicionBomba = 0;
                explotarBombas(matriz);
                impresion;
                refresh;
                pasos = 0;
                move(0,45);
                printw("Tiempo-Bombas");
                move(1,45);
                printw("%i", pasos);
            }
            
            movimientoVillanos(matriz);
            int elJugadorEsta;
            elJugadorEsta = verInstancia(matriz);
            if(elJugadorEsta == 0 ){
                vida--;
                
            }

            if(vida == 0){
                break;
            }

            
            impresion(matriz);
            refresh();
            
        }

        direccion = 0;
        impresion(matriz);
        refresh();
        
    }
    move(y / 2, (x / 2 - 4));
    if(condicionJuego == 1){
        printw("Ganastes!!!");
    }else {
        printw("Perdió!!");
    }
    refresh();
    usleep(1000000 / 2);
    curs_set(1);
}
//*****

int verInstancia(Item*** matriz){
    Jugador* jugador = NULL;
    for(int i=0; i<11; i++){
        for(int j=0; j<13; j++){
            Item* tem = matriz[i][j];
            jugador = dynamic_cast<Jugador*>(tem ); // si hay instancia retornara un direccion en memoria
	        if(jugador != NULL){
                move(1,30);
                printw("Jugador");
                return 1;
        	}
        }
    }

    return 0;
}

int validacionMovimiento(Item*** matriz , int x, int y){
    int condicion;
    string salida;
    salida = matriz[x][y]->getSalida();

    if(salida == "@"){
        return 0;
    }

    if(salida == "X"){
        return 3;
    }

    if(salida == "O"){
        return 2;
    }

    return 1;
}

void impresion(Item*** matriz){
    for(int i=0; i<11; i++){
        for(int j = 0; j<13; j++){
            
            move(i,j);
            string est;
            est = matriz[i][j]->getSalida();
            char s;
            s = est.at(0);
            printw("%c", s);
        }
    }
}// imprimimos en pantalla

void movimientoVillanos(Item*** &matriz){
    int direccion;
    int condicion;
    


    for(int i = 0; i<11; i++){
        for(int j=0; j<13; j++){
            direccion = rand()%4+1;
            move(3,20);
            printw("%i", direccion);
            if(matriz[i][j]->getSalida() == "X" ){
                if(direccion== 1 && (i-1)>=0){
                    condicion = validacionMovimiento(matriz, i-1, j);
                    if(condicion!=0 && condicion!=3 && condicion!=2){
                        Item* temporal = matriz[i][j];
                        matriz[i-1][j] = temporal;
                        matriz[i][j] = new Item();
                        matriz[i][j]->setSalida(" ");
                        impresion(matriz);
                    }
                }

                if(direccion== 2 && (j-1)>=0){
                    condicion = validacionMovimiento(matriz, i, j-1);
                    if(condicion!=0 && condicion!=3 && condicion!=2){
                        Item* temporal = matriz[i][j];
                        matriz[i][j-1] = temporal;
                        matriz[i][j] = new Item();
                        matriz[i][j]->setSalida(" ");
                        impresion(matriz);
                    }
                }

                if(direccion== 3 && (j+1)<13){
                    condicion = validacionMovimiento(matriz, i, j+1);
                    if(condicion!=0 && condicion!=3 && condicion!=2){
                        Item* temporal = matriz[i][j];
                        matriz[i][j+1] = temporal;
                        matriz[i][j] = new Item();
                        matriz[i][j]->setSalida(" ");
                        impresion(matriz);
                    }
                }

                if(direccion== 4 && (i+1)<11){
                    condicion = validacionMovimiento(matriz, i+1, j);
                    if(condicion!=0 && condicion!=3 && condicion!=2){
                        Item* temporal = matriz[i][j];
                        matriz[i+1][j] = temporal;
                        matriz[i][j] = new Item();
                        matriz[i][j]->setSalida(" ");
                        impresion(matriz);
                    }
                }
                


                
            }


        }// segundo for
    }// primer for

}// el metodo


void explotarBombas(Item*** &matriz){
    Bombas* bomba = NULL;
    for(int i=0; i<11; i++){
        for(int j=0; j<13; j++){
            Item* tem = matriz[i][j];
            bomba = dynamic_cast<Bombas*>(tem ); 
	        if(bomba != NULL){
                //move(i,60);
                //printw("es bomba");

                int condicion;
                if(i-1>=0){
                    condicion = validacionMovimiento(matriz, i-1,j);
                    if(condicion !=2 && condicion!=0){
                        matriz[i-1][j] = new Item();
                        matriz[i-1][j]->setSalida(" ");
                        matriz[i][j] = new Item();
                        matriz[i][j]->setSalida(" ");
                        impresion(matriz);
                    }
                }

                if(i+1<11){
                    condicion = validacionMovimiento(matriz, i+1,j);
                    if(condicion !=2 && condicion!=0){
                        matriz[i+1][j] = new Item();
                        matriz[i+1][j]->setSalida(" ");
                        matriz[i][j] = new Item();
                        matriz[i][j]->setSalida(" ");
                        impresion(matriz);
                    }
                }
                
                if(j+1<13){
                    condicion = validacionMovimiento(matriz, i,j+1);
                    if(condicion !=2 && condicion!=0){
                        matriz[i][j+1] = new Item();
                        matriz[i][j+1]->setSalida(" ");
                        matriz[i][j] = new Item();
                        matriz[i][j]->setSalida(" ");
                        impresion(matriz);
                    }
                }

                if(j-1>=0){
                    condicion = validacionMovimiento(matriz, i,j-1);
                    if(condicion !=2 && condicion!=0){
                        matriz[i][j-1] = new Item();
                        matriz[i][j-1]->setSalida(" ");
                        matriz[i][j] = new Item();
                        matriz[i][j]->setSalida(" ");
                        impresion(matriz);
                    }
                }
        	}
        }
    }
}

int gane(Item*** matriz){
    int contador;
    contador = 0;
    for(int i =0; i<11; i++){
        for(int j=0; j<13; j++ ){
            if(matriz[i][j]->getSalida()== "X"){
                contador++;
            }
        }
    }

    return contador;
}

int kbhit(void)
{
    struct timeval timeout;
    fd_set readfds;
    int how;

    /* look only at stdin (fd = 0) */
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    /* poll: return immediately */
    timeout.tv_sec = 0L;
    timeout.tv_usec = 0L;

    how = select(1, &readfds, (fd_set *)NULL, (fd_set *)NULL, &timeout);
    /* Change "&timeout" above to "(struct timeval *)0"       ^^^^^^^^
         * if you want to wait until a key is hit
         */

    if ((how > 0) && FD_ISSET(0, &readfds))
        return 1;
    else
        return 0;
}