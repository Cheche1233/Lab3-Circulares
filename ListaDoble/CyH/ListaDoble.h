#pragma once

typedef struct Nodo{
    void* dato;
    char letra;
    struct Nodo *sig;
    struct Nodo *prev;

}Nodo;

typedef struct Lista{
    Nodo *head;
    Nodo *tail;
    Nodo *current;
    int size;

}ListaDoble;

Nodo* crearNodo();
ListaDoble* crearLista();
void pushFront(ListaDoble *lista, void* item);
void pushBack(ListaDoble *lista, void* item);
void pushPos(ListaDoble *lista, int pos, void* item);
Nodo* buscarNodo(ListaDoble *lista, int pos);
void liberarNodo(Nodo *nodo);
void mostrarLista(ListaDoble *lista, void (*func)(void*));
void liberarLista(ListaDoble *lista);
ListaDoble* ordenarLista(ListaDoble* lista);
int borrarPos(ListaDoble *lista, int pos);
ListaDoble* ConcaInicio(ListaDoble *lista1, ListaDoble *lista2);
void printChar(void* letra);
ListaDoble* ConcaFinal(ListaDoble *lista1, ListaDoble *lista2);
ListaDoble* ConcaPos(ListaDoble *lista1, ListaDoble *lista2, int pos);