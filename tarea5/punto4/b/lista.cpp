#include "lista.h"
 
Nodo::~Nodo(){
  cout << "Borrando nodo " << dato << endl;
  sig = NULL;
  ant = NULL;
  delete sig;
  delete ant;
}

Lista::Lista(){
  act = NULL;
}

/*Punto 4 - b : Sobre Carga del operador '+' para concatenar Listas.
====================================================================================================
|funciones TAD usadas | Complejidad | Explicación
----------------------------------------------------------------------------------------------------
|longLista()          |  O(n)      | siendo n el tamaño de la lista.
----------------------------------------------------------------------------------------------------
|infoLista()          |  O(n)      | siendo n la posición que se le pasa a la función.
----------------------------------------------------------------------------------------------------
|vaciaLista()         |  O(1)      | Recuperar el estado de una lista siempre será constante
----------------------------------------------------------------------------------------------------
|anxLista()           |  O(1)      | por estar usando una lista doblemente enlazada circular, la operación 
|                     |            | de añadir un elemento al final se hacen en tiempo constante.
====================================================================================================
Complejidad : O(n^2) siendo n el tamaño de la segunda lista
----------------------------------------------------------------------------------------------------
Explicación:
Para añadir todos los elementos de la primera lista a la lista nueva, se recorre toda la lista de manera
y va añadiendo cada elemento a la nueva lista con al operación 'anxLista' que es de complejidad O(1), 
por tanto añadir todos los elementos de la primera lista tiene complejidad O(n), siendo n el tamaño de 
la primera lista. Por otro lado, para la segunda lista como no se puede acceder a ella para recorrerla
internamente para acceder a cada elemento se usa la operación 'infoLista' de complejidad O(n) como esta sé
repetirá n veces siendo n el tamaño de la segunda lista, se está invocando una operación de complejidad 
O(n) n veces, por lo tanto la complejidad de copiar cada elemento de la segunda lista es O(n^2).

Entones siendo más precisos la complejidad de concatenar obtener una nueva lista como concatenación 
de otras dos listas de esta forma seria O(n^2 + m), siendo n el tamaño de la segunda lista y m 
el tamaño de la primera.
====================================================================================================
====================================================================================================
*/

Lista Lista::operator+(Lista &l2){
  Lista ans;
  Nodo* tmp = act;
  Nodo* primero = act;
  int len = l2.longLista();
  if(!vaciaLista()){
    while(tmp->sig != primero){
      ans.anxLista(tmp->dato);  
      tmp = tmp->sig;
    }
    ans.anxLista(tmp->dato); 
  }
  for(int i = 1; i <= len; ++i){
    ans.anxLista(l2.infoLista(i));
  }
  return ans;
}

void Lista::anxLista(Elemento elem){
  Nodo *tmp, *primero;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = nuevo;
  nuevo->ant = nuevo;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act->ant;
    tmp->sig = nuevo;
    nuevo->ant = tmp;
    nuevo->sig = act;
    act->ant = nuevo;
  }
}

void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;
  nuevo->ant = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      tmp = act->ant;
      tmp->sig = nuevo;
      nuevo->ant = tmp;
      nuevo->sig = act;
      act->ant = nuevo;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
        tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      nuevo->ant = tmp;
      tmp->sig->ant = nuevo;
      tmp->sig = nuevo;
    }
  }
}
 
void Lista::elimLista(int pos){
  Nodo *tmp, *borrar;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
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
    }
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
          tmp = tmp->sig;
      borrar = tmp->sig;
      Nodo* sig = tmp->sig->sig;
      tmp->sig = sig;
      sig->ant = tmp;
    }

    delete borrar;
  }
}

Elemento Lista::infoLista(int pos){
   Nodo* tmp = act;
   
   for(int i = 1; i < pos; i++)
      tmp = tmp->sig;
      
   return tmp->dato;
}

int Lista::longLista(){
  int ans;
  if(vaciaLista())
    ans = 0;
  else{
    Nodo* tmp, *primero;
    int cont = 1;
    tmp = act;
    primero = act;

    while(tmp->sig != primero){
      tmp = tmp->sig;
      cont++;
    }

    ans = cont;
  }

  return ans;
}

bool Lista::vaciaLista(){
   return act == NULL;
}
