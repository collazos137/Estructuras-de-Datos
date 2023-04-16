/*
Punto 3 - a
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // April 12st 2023
====================================================================================================*/
#include "lista.h"

void insertarEnListaOrdenada(Lista &l, int v);

int main(){
    Lista l;
    int i, arry[] = {8, 9, 10, 1, 26, 12, 99, 66, 26, 11, -45};

    cout << "Elementos a ingresar en lista : [ ";
    for(i = 0; i < sizeof(arry)/sizeof(int) - 1 ; ++i)
        cout << arry[i] << ", ";
    cout << arry[i] << "]" << endl;

    for(i = 0; i < sizeof(arry)/sizeof(int) ; ++i)
        insertarEnListaOrdenada(l, arry[i]);
    
    cout << "Lista Ordenada : [";
    for(i = 1; i < l.longLista(); ++i)
        cout << l.infoLista(i) << ", ";
    cout << l.infoLista(i) << "]" << endl;

    return 0;
}

/*Punto 3 - a : insertarEnListaOrdenada
====================================================================================================
|funciones TAD usadas | Complejidad | Explicación
----------------------------------------------------------------------------------------------------
|longLista()          |  O(n)      | siendo n el tamaño de la lista.
----------------------------------------------------------------------------------------------------
|infoLista()          |  O(n)      | siendo n la posición que se le pasa a la función.
----------------------------------------------------------------------------------------------------
|insLista()           |  O(n)      | siendo n la posición que se le pasa a la función.
----------------------------------------------------------------------------------------------------
|vaciaLista()         |  O(1)      | Recuperar el estado de una lista siempre será constante
----------------------------------------------------------------------------------------------------
|anxLista()           |  O(1)      | por estar usando una lista doblemente enlazada circular, la operación 
|                     |            | de añadir un elemento al final se hacen en tiempo constante.
====================================================================================================
Complejidad de "insertarEnListaOrdenada()" : O(n^2) siendo n el tamaño de la lista
----------------------------------------------------------------------------------------------------
Explicación: En el peor de los casos el elemento que se quiere ingresar es mayor que todos los elementos
de la lista por lo que se recorrerá todo el tamaño de la lista al que llamaremos 'n', el ciclo sé 
repite n veces y dentro de ciclo se encuentra la operación 'infoLista()' que tiene complejidad O(n), estamos
invocando una operación de complejidad O(n) n veces, por lo tanto la complejidad es O(n^2), cuando sé 
llega al final se añade el elemento con la operación 'anxLista' de complejidad O(1).
====================================================================================================
*/

void insertarEnListaOrdenada(Lista &l, int v){
    if(!l.vaciaLista()){
        int len = l.longLista(), i = 1, flag = 1;
        while(i <= len && flag){
            if(l.infoLista(i) >= v){
                l.insLista(v, i);
                flag = 0;
            }
            ++i;
        }
        if(flag){
            l.anxLista(v);
        }
    }else{
        l.anxLista(v);
    }
}