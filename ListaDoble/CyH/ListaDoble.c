#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDoble.h"

//Generar letras random
char generarLetraAleatoria() {
    return 'A' + (rand() % 26);
}

void generarTexto(char *texto, int tamano) {
    for (int i = 0; i < tamano; i++) {
        texto[i] = generarLetraAleatoria();
    }
    texto[tamano] = '\0';  
}

Nodo* crearNodo() {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->sig = NULL;
    nodo->prev = NULL;
    nodo->dato = NULL;
    return nodo;
}


ListaDoble* crearLista() {
    ListaDoble* lista = (ListaDoble*)malloc(sizeof(ListaDoble));
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    lista->size = 0;
    return lista;
}

void pushFront(ListaDoble* lista, void* item) {
    Nodo* nodo = crearNodo();
    nodo->dato = item;
    if (lista->head == NULL) {
        lista->head = nodo;
        lista->tail = nodo;
    } else {
        nodo->sig = lista->head;
        lista->head->prev = nodo;
        lista->head = nodo;
    }
    lista->size++;
}


void pushBack(ListaDoble* lista, void* item) {
    Nodo* nodo = crearNodo();
    nodo->dato = item;
    if (lista->tail == NULL) {
        lista->head = nodo;
        lista->tail = nodo;
    } else {
        nodo->prev = lista->tail;
        lista->tail->sig = nodo;
        lista->tail = nodo;
    }
    lista->size++;
}


void pushPos(ListaDoble* lista, int pos, void* item) {
    if (pos == 0) {
        pushFront(lista, item);
    } else if (lista->size == pos) {
        pushBack(lista, item);
    } else {
        Nodo* nodo = crearNodo();
        nodo->dato = item;
        Nodo* ant = buscarNodo(lista, pos-1);
        if (ant != NULL) {
            nodo->sig = ant->sig;
            nodo->prev = ant;
            if (ant->sig != NULL) {
                ant->sig->prev = nodo;
            ant->sig = nodo;
            lista->size++;
        }
    }
    }
}

Nodo* buscarNodo(ListaDoble* lista, int pos) {
    if (pos < 0 || pos >= lista->size) {
        return NULL;
    }

    Nodo* actual = lista->head;
    for (int i = 0; i < pos; i++) {
        actual = actual->sig;
    }

    return actual;
}

void printChar(void* letra){
    printf("%c -- ", *(char*)letra);
}

void mostrarLista(ListaDoble* lista, void (*func)(void*)) {
    if (lista->head == NULL) {
        printf("La lista está vacía\n");
        return;
    }

    Nodo* actual = lista->head;
    int count = 0;

    
    while (count < lista->size) {
        func(actual->dato); 
        actual = actual->sig;
        count++;
    }
    
    printf("\n");
}


void liberarNodo(Nodo *nodo) {
    if (nodo != NULL) {
        free(nodo);
    }
}

void liberarLista(ListaDoble* lista) {

    Nodo* actual = lista->head;
    Nodo* siguiente = NULL;
    for (int count = 0; count < lista->size; ++count) {
        
        if (actual->dato != NULL) {
            free(actual->dato);
        }
        free(actual);
    
        actual = siguiente;
    }

    // Establecer los punteros en NULL y liberar la lista misma
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;

    free(lista);  // Liberar la lista misma
    printf("Lista liberada correctamente\n");
}



/*
ListaDoble* ordenarLista(ListaDoble* lista) {
    Nodo* actual;
    Nodo* sigActual;

    if (lista->size < 2) {
        return lista;
    }

    for (int i = 0; i < lista->size - 1; i++) {
        actual = lista->head;
        sigActual = actual->sig;

        for (int j = 0; j < lista->size - 1 - i; j++) {
            if ((actual->blog->cantLetrasComentario) > (sigActual->blog->cantLetrasComentario)) 
            {
                Blog* temp = actual->blog;
                actual->blog = sigActual->blog;
                sigActual->blog = temp;
            }
            actual = sigActual;
            sigActual = sigActual->sig;
        }
    }

    return lista;
}
*/

/*
int borrarPos(ListaDoble *lista, int pos){
    if(pos == 0){
        free(lista->head);
        lista->head = temp;
        lista->size--;
        return 1;
    }
    Nodo *temp1;
    temp1 = buscarNodo(lista, pos-1);
    Nodo *nodoAborrar = buscarNodo(lista, pos);
    temp1->sig = nodoAborrar->sig;
    free(nodoAborrar);
    if(pos == lista->size-1){
        lista->tail = temp1;
    }
    lista->size--;
    return 1;
}
*/

ListaDoble* ConcaInicio(ListaDoble *lista1, ListaDoble *lista2) {
    ListaDoble* listaFinal = crearLista();

    if (lista1 == NULL || lista1->size == 0) {
        return lista2;
    }
    if (lista2 == NULL || lista2->size == 0) {
        return lista1;
    }

    lista2->tail->sig = lista1->head;
    lista1->head->prev = lista2->tail;

    lista1->tail->sig = lista2->head;
    lista2->head->prev = lista1->tail;

    listaFinal->head = lista2->head;
    listaFinal->tail = lista1->tail;
    listaFinal->size = lista1->size + lista2->size;

    return listaFinal;
}

ListaDoble* ConcaFinal(ListaDoble *lista1, ListaDoble *lista2) {
    ListaDoble* listaFinal = crearLista();

    if (lista1 == NULL || lista1->size == 0) {
        return lista2;
    }
    if (lista2 == NULL || lista2->size == 0) {
        return lista1;
    }

    lista1->tail->sig = lista2->head;
    lista2->head->prev = lista1->tail;

    lista2->tail->sig = lista1->head;
    lista1->head->prev = lista2->tail;

    listaFinal->head = lista1->head;
    listaFinal->tail = lista2->tail;
    listaFinal->size = lista1->size + lista2->size;

    return listaFinal;
}

ListaDoble* ConcaPos(ListaDoble *lista1, ListaDoble *lista2, int pos) {
    
    if (lista2 == NULL || lista2->size == 0) {
        return lista1;
    }

    if (pos == 0) {
        return ConcaInicio(lista1, lista2);
    }
    
    if (pos == lista1->size) {
        return ConcaFinal(lista1, lista2);
    }

    
    Nodo* referencia = buscarNodo(lista1, pos);
    if (referencia == NULL) {
        return lista1;
    }
    Nodo* nodoPrevio = referencia->prev;

    
    lista2->tail->sig = referencia;
    referencia->prev = lista2->tail;

    nodoPrevio->sig = lista2->head;
    lista2->head->prev = nodoPrevio;

    lista1->size += lista2->size;

    return lista1;
}






