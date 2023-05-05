#include "queuep.h"
 
Nodo::~Nodo(){
  sig = NULL;
  ant = NULL;
  delete sig;
  delete ant;
}

Queuep::Queuep(){
  act = NULL;
}
/*
funcion: enqueue
====================================================================================================
|funciones TAD usadas | Complejidad | Explicación
----------------------------------------------------------------------------------------------------
|empty()              |  O(1)      | Recuperar el estado de una cola siempre será constante.
----------------------------------------------------------------------------------------------------
====================================================================================================
Complejidad de "enqueue()" : O(n) siendo n el tamaño de la cola.
----------------------------------------------------------------------------------------------------
Explicación: En el peor de los casos el elemento que se quiere ingresar es menor que todos los elementos
de la cola por lo que se recorrerá toda la cola para insertarlo en la última posición, por tanto la 
complejidad de insertar un elemento de manera ordenada ser O(n) siendo n el tamaño de la lista. 
====================================================================================================
*/

void Queuep::enqueue(Elemento elem){
  Nodo* tmp;
  Nodo* primero;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->ant = NULL;
  nuevo->sig = NULL;

  if(!empty()){
    tmp = act;
    primero = act;
    if(tmp->dato <= elem){
      tmp = tmp->ant; 
      act = nuevo;
    }else{
      while(tmp->sig != primero && tmp->sig->dato > elem){
        tmp = tmp->sig;
      }
    }
    nuevo->sig = tmp->sig;
    nuevo->ant = tmp;
    tmp->sig->ant = nuevo;
    tmp->sig = nuevo;
  }else{
    act = nuevo;
    nuevo->sig = nuevo;
    nuevo->ant = nuevo;
  }
}

/*
funcion : deque
====================================================================================================
|funciones TAD usadas | Complejidad | Explicación
----------------------------------------------------------------------------------------------------
|Ninguna              |             | 
----------------------------------------------------------------------------------------------------
====================================================================================================
Complejidad de "deque()" : O(1).
----------------------------------------------------------------------------------------------------
Explicación: eliminar el elemento con mas primoridad de una cola sera simpre de complejidad constante O(1) 
por que al la cola estar ordenada el elemneto con mas prioridad sera simpre el primero elemento.
====================================================================================================
*/
 
void Queuep::deque(){
  Nodo *tmp, *borrar;
  if(act != act->sig){
    tmp = act->ant;
    borrar = tmp->sig;
    act = act->sig;
    act->ant = tmp;
    tmp->sig = act;
  }
  else{
    borrar = act;
    act = NULL;
  }
  delete borrar;
}
/*
funcion : front
====================================================================================================
|funciones TAD usadas | Complejidad | Explicación
----------------------------------------------------------------------------------------------------
|Ninguna              |             | 
----------------------------------------------------------------------------------------------------
====================================================================================================
Complejidad de "front()" : O(1).
----------------------------------------------------------------------------------------------------
Explicación: ver dato del elemento con mas primoridad de una cola sera simpre de complejidad constante O(1) 
por que al la cola estar ordenada el elemneto con mas prioridad sera simpre el primero elemento.
====================================================================================================
*/

int Queuep::front(){
  return act->dato;
}

/*
funcion : empty
====================================================================================================
|funciones TAD usadas | Complejidad | Explicación
----------------------------------------------------------------------------------------------------
|Ninguna              |             | 
----------------------------------------------------------------------------------------------------
====================================================================================================
Complejidad de "empty()" : O(1).
----------------------------------------------------------------------------------------------------
Explicación: ver si una cola esta vacia se hace en tiempo O(1) porque basta con revisar si 'act' es nulo.
====================================================================================================
*/


bool Queuep::empty(){
  return act == NULL;
}
