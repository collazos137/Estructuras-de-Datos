/*
 * Autor: Juan Diego Collazos, Juan David Vazques
 * Fecha de creación: 5 Mayo
 * Archivo encabezado libreria TAD Lista
 * Representación Estructuras Cola de Prioridad
 */

#ifndef __COLA_P
#define __COLA_P

#include <iostream>

using namespace std;

/************************
* ESTRUCTURAS DE DATOS *
************************/
typedef int Elemento;

class Nodo{
   public:
     Elemento dato;
     Nodo* sig;
     Nodo* ant;

     ~Nodo();
};

class Queuep{
  private:
    Nodo* act;

  public:
    /************************
    * OPERACIONES DEL TAD *
    ************************/

    /* Constructoras */
    Queuep();

    /* Modificadoras */
    void enqueue(Elemento elem);
    void deque();

    /* Analizadoras */
    int front();
    bool empty();

};

#endif
