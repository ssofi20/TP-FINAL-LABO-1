#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED


///Prototipo

void sumaDeDados(int v[], int VP[]);

int trio(int v[], int VP[]);

int sexteto(int v[], int VP[]);

int escalera (int v[], int VP[]);

int lanzamiento( int vDados[], int vPuntos[]);


///Desarrollo

void sumaDeDados(int v[], int VP[]){
    int i, cantRep, ptjRonda;
    for(i=1;i<=6;i++){
        cantRep = contarNumerosRepetidos(v,i,6);
        if(cantRep<3){
            VP[0] = sumarVector(v,6);
        }
    }
}

int trio(int v[], int VP[]){
    int i, cantRep, maxi = 0;
    for(i=1;i<=6;i++){
        cantRep = contarNumerosRepetidos(v,i,6);
        if(cantRep>=3 && cantRep<6){
            if (maxi<i*1){
                maxi = i*10;
            }
        }
        VP[1] = maxi;
    }
}

int sexteto(int v[], int VP[]){
    int i, cantRep;
    for(i=1;i<=6;i++){
        cantRep = contarNumerosRepetidos(v,i,6);
        if(cantRep==6){
            if (i!=6){
                VP[2] = i*50;
            }
            else {
                VP[2] = 500;
            }
        }
    }
}

int escalera (int v[], int VP[]){
    int i, cantRep, ptjRonda = 0, x = 0;
    for(i=1;i<=6;i++){
        cantRep = contarNumerosRepetidos(v,i,6);
        if(cantRep!=0){
            x = 1;
        }
    }
    if (x==0){
        VP[3] = ptjRonda;
    }
}

int lanzamiento( int vDados[], int vPuntos[]){

    int posMax, pLanzamiento;

    sumaDeDados(vDados, vPuntos);
    trio(vDados, vPuntos);
    sexteto(vDados, vPuntos);
    escalera(vDados, vPuntos);

    posMax = maximoVector(vPuntos,5);

    return pLanzamiento = vPuntos[posMax];
}

#endif // PUNTAJE_H_INCLUDED
