#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>

using namespace std;

#include "funciones.h"
#include "rlutil.h"
#include "Hola.h"

int main(){

    int opc;

    while (true){
        rlutil::setBackgroundColor(rlutil::COLOR::MAGENTA);
        rlutil::setConsoleTitle("QUINIENTOS");
        rlutil::cls();
        opc=menuPrincipal();
        rlutil::cls();

        bool ganador = true;
        int contadorRondas = 0, pTotal = 0;
        int vDados[6], vPuntos[4];
        char nombre [10];

        switch (opc){
            case 1: rlutil::locate(53,13);
                    cout << "NOMBRE JUGADOR: " << endl;
                    rlutil::locate(57,15);
                    cin >> nombre;
                    while(ganador){
                        contadorRondas++;
                        entreRondas(nombre, contadorRondas, pTotal);
                        rlutil::cls();
                        pTotal += ronda(vDados, vPuntos);
                        ganador = pantallaGanador(pTotal, ganador);
                    }
                    break;
            case 2:
                    break;
            case 3:
                    break;
            case 0: rlutil::locate(45,15);
                    cout << "GRACIAS POR JUGAR NUESTRO JUEGO";
                    rlutil::anykey();
                    return 0;
                    break;
            default:break;
        }
    }
}
