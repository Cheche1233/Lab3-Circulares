#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ListaDoble.h>



int main() {

    ListaDoble* lista1 = crearLista();
    ListaDoble* lista2 = crearLista();


    char letra1 = 'I';
    char letra2 = 'N';
    char letra3 = 'G';
    char letra4 = 'E';
    char letra5 = 'N';
    char letra6 = 'I';
    char letra7 = 'E';
    char letra8 = 'R';
    char letra9 = 'O';
    
    pushBack(lista1, &letra1);
    pushBack(lista1, &letra2);
    pushBack(lista1, &letra3);
    pushBack(lista1, &letra4);
    pushBack(lista1, &letra5);
    pushBack(lista1, &letra6);
    pushBack(lista1, &letra7);
    pushBack(lista1, &letra8);
    pushBack(lista1, &letra9);

    char letra11 = 'S';
    char letra12 = 'O';
    char letra13 = 'F';
    char letra14 = 'T';
    char letra15 = 'W';
    char letra16 = 'A';
    char letra17 = 'R';
    char letra18 = 'E';

    pushBack(lista2, &letra11);
    pushBack(lista2, &letra12);
    pushBack(lista2, &letra13);
    pushBack(lista2, &letra14);
    pushBack(lista2, &letra15);
    pushBack(lista2, &letra16);
    pushBack(lista2, &letra17);
    pushBack(lista2, &letra18);
    
    mostrarLista(lista1, printChar);
    printf("\n");
    mostrarLista(lista2, printChar);

    ListaDoble* listaConcaInicio = ConcaInicio(lista1, lista2);
    mostrarLista(listaConcaInicio, printChar);

    ListaDoble* listaConcaFinal = ConcaFinal(lista1, lista2);
    mostrarLista(listaConcaFinal, printChar);

    ListaDoble* listaConcaPos = ConcaPos(lista1, lista2, 3);
    mostrarLista(listaConcaPos, printChar);


    liberarLista(lista1);
    liberarLista(lista2);
    liberarLista(listaConcaInicio);
    liberarLista(listaConcaFinal);
    
    return 0;
    
}
