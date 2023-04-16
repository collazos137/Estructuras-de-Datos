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

/*Punto 3 - b : insListaOrdenada
====================================================================================================
|funciones TAD usadas | Complejidad | Explicación
----------------------------------------------------------------------------------------------------
|vaciaLista()         |  O(1)      | Recuperar el estado de una lista siempre será constante.
----------------------------------------------------------------------------------------------------
====================================================================================================
Complejidad de "insListaOrdenada()" : O(n) siendo n el tamaño de la lista.
----------------------------------------------------------------------------------------------------
Explicación: En el peor de los casos el elemento que se quiere ingresar es mayor que todos los elementos
de la lista por lo que se recorrerá toda la lista para insertarlo en la última posición, por tanto la 
complejidad de insertar un elemento de manera ordenada ser O(n) siendo n el tamaño de la lista. 
====================================================================================================
*/

void Lista::insListaOrdenada(Elemento elem){
  Nodo* tmp;
  Nodo* primero;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->ant = NULL;
  nuevo->sig = NULL;
  if(!vaciaLista()){
    tmp = act;
    primero = act;
    if(tmp->dato >= elem){
      tmp = tmp->ant; 
      act = nuevo;
    }else{
      while(tmp->sig != primero && tmp->sig->dato < elem){
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
