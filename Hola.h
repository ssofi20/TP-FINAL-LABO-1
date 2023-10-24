#ifndef HOLA_H_INCLUDED
#define HOLA_H_INCLUDED

#include "puntaje.h"

/*esta funcion muestra el texto de la opcion, lo ubica en la posicion deseada, y si se encuentra en la
posicion de z que le corresponde lo pinta de un colo diferente para hacer la idea de que esta seleccionado. */

void showItem(const char* text, int posx, int posy, bool selected){
    if(selected){
        rlutil::setBackgroundColor(rlutil::COLOR::LIGHTMAGENTA);
    }
    else {
        rlutil::setBackgroundColor(rlutil::COLOR::MAGENTA);
    }
    rlutil::locate(posx,posy);
    cout << text << endl;

    rlutil::setBackgroundColor(rlutil::COLOR::MAGENTA);
}

int menuPrincipal(){

    //z controla la posicion del cursor en la pantalla.
    int z = 0;
        //esto es el encabezado del menu principal
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        rlutil::locate(54,3);
        cout << "MENU PRINCIPAL" <<endl;
        rlutil::locate(1,5);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

    while(true){

        //utilizo la funcion showIntem para mostrar las opciones del menu.
        rlutil::hidecursor();
        showItem("JUEGO NUEVO 1 JUGADOR", 50, 10, z == 0);
        showItem("JUEGO NUEVO 2 JUGADORES", 49, 12, z == 2);
        showItem("MOSTRAR PUNTUACION MAS ALTA", 47, 14, z == 4);
        showItem("SALIR DEL JUEGO", 53, 16, z == 6);

        //esta es la "flechita" que aparece en el menu para acompania a la seleccion de un item.
        rlutil::locate(44,10+z);
        cout << (char)175 << endl;

        /*cuando el usuario presiona la flecha para arriba recibo en key = 14, flecha para abajo key = 15
        y cuando presiona enter obtengo 1. En base a eso muevo la felchita del costado.
        Esta funcion retorna al main 1, 2, 3 o 0, cuando al presionar enter se selecciona alguna opcion.*/
        int key = rlutil::getkey();

        switch (key){
            case 14: ///UP
                    rlutil::locate(44,10+z);
                    cout << " " << endl;
                    z-=2;
                    if (z<0){
                        z=0;
                    }
                    break;
            case 15: ///DOWN
                    rlutil::locate(44,10+z);
                    cout << " " << endl;
                    z+=2;
                    if (z>6){
                        z=6;
                    }
                    break;
            case 1 : ///ENTER
                    if(z==0){
                        return 1;
                    }
                    else if(z==2){
                        return 2;
                    }
                    else if(z==4){
                        return 3;
                    }
                    else {
                        return 0;
                    }
                    break;
            default:
                    break;
        }
    }
}

/*
Recibe el vector del nombre, contador de rondas y acumulador de puntake total.
*/
void entreRondas(char nombre[], int nRonda, int pTotal){

    int i;

    //dibuja un cuadro
    for (i=46;i<76;i++){
        rlutil::locate(i,10);
        cout << "-";
    }
    for (i=46;i<76;i++){
        rlutil::locate(i,20);
        cout << "-";
    }
    for (i=11;i<20;i++){
        rlutil::locate(46,i);
        cout << (char)221;
    }
    for (i=11;i<20;i++){
        rlutil::locate(76,i);
        cout << (char)221;
    }

    //muestra el nuermo de ronda, de quien es el proximo turno y cual es el puntaje total de esa persona.
    rlutil::locate(48,13);
    cout << "RONDA N " << nRonda << endl;
    rlutil::locate(48,15);
    cout << "PROXIMO TURNO " << nombre << endl;
    rlutil::locate(48,17);
    cout << "PUNTAJE TOTAL " << pTotal << endl;

    rlutil::anykey();
}

//esta funcion recibe dos vectores, uno es el de los dados y otro es el vector de los puntajes posibles.
int ronda(int vDados[], int vPuntos[]){

    int i, CR = 0;
    int pTotal = 0, pRonda = 0, pLanzamiento = 0, maxi = 0, pasaPuntos = 0;

    for(i=0;i<3;i++){

        cout << "PUNTAJE TOTAL " <<pTotal << endl;
        cout << "PUNTAJE DE RONDA " << pRonda << endl;
        //cargar el vector aleatoreamente y poner en cero el de contador de lanzamientos.
        cargarAleatorio(vDados,6,6);
        ponerCero(vPuntos, 4);
        //mostrar los dados en la pantalla
        mostrarVector(vDados,6);
        cout << endl;
        //evaluar a cada posible puntuacion de la lanzada.
        pLanzamiento = lanzamiento(vDados, vPuntos);
        //buscar la puntiacion mas alta de la ronda.
        if(pLanzamiento>maxi){
            maxi = pLanzamiento;
            pRonda = pLanzamiento;
        }

        cout << "PUNTAJE DE LANZAMIENTO " << pLanzamiento << endl;

        rlutil::anykey();
        rlutil::cls();
    }
    return pRonda;
}

int pantallaGanador(int pTotal, bool ganador){
    if (pTotal>=500){
        rlutil::locate(45,15);
        cout << "!FELICIDADES GANASTE LA PARTIDA!";
        rlutil::locate(35,25);
        cout << "PRECIONA CUALQUIER TECLA PARA VOLVER AL MENU PRINCIPAL";
        rlutil::anykey();
        return ganador = false;
    }
}

#endif // HOLA_H_INCLUDED
