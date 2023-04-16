/*
Punto 4 - a
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // April 16st 2023
====================================================================================================*/
#include "lista.h"
void concatenarListas(Lista &l1, Lista &l2);

int main(){
    Lista l1;
    Lista l2;
    int i, arry1[] = {8, 9, 10, 1, 26, 12, 99, 66, 26, 11, -45}, arry2[] = {8, 9, 10, 1, 26, 12, 99, 66, 26, 11, -45};
    int len1 = sizeof(arry1)/sizeof(int), len2 = sizeof(arry2)/sizeof(int);
    for(i = 0; i < len1; ++i)
        l1.anxLista(arry1[i]);
    for(i = 0; i < len2 ; ++i)
        l2.anxLista(arry2[i]);

    cout << "Lista1 : [";
    for(i = 1; i < l1.longLista(); ++i)
        cout << l1.infoLista(i) << ", ";
    cout << l1.infoLista(i) << "]" << endl;

    cout << "Lista2 : [";
    for(i = 1; i < l2.longLista(); ++i)
        cout << l2.infoLista(i) << ", ";
    cout << l2.infoLista(i) << "]" << endl;

    concatenarListas(l1, l2);

    cout << "Lista1 + Lista2 : [";
    for(i = 1; i < l1.longLista(); ++i)
        cout << l1.infoLista(i) << ", ";
    cout << l1.infoLista(i) << "]" << endl;

    return 0;
}

/*Punto 4 - a : concatenarListas
====================================================================================================
|funciones TAD usadas | Complejidad | Explicación
----------------------------------------------------------------------------------------------------
|longLista()          |  O(n)      | siendo n el tamaño de la lista.
----------------------------------------------------------------------------------------------------
|infoLista()          |  O(n)      | siendo n la posicion que se le pasa a la función.
----------------------------------------------------------------------------------------------------
|anxLista()           |  O(1)      | por estar usando una lista doblemente enlazada circular, la operación 
|                     |            | de añadir un elemento al final se hacen en tiempo constante.
====================================================================================================
Complejidad de "concatenarListas()" : O(n^2) siendo n el tamaño de la segunda lista.
----------------------------------------------------------------------------------------------------
Explicación: para añadir todos los elementos de la lista 2 al final de lista 1, la operación 'longLista()' 
retorna el tamaño de la lista 2 (que llamaremos 'n') por tanto el ciclo se repite n veces y dentro de ciclo
se encuentra la operación 'infoLista()' (que consulta uno a uno los elementos de la lista 2) que tiene complejidad O(n)
y la operación 'anxLista()' (que añade a la lista 1 los elementos que devuelve la operación 'infoLista') 
que tiene complejidad O(1), estamos invocando una operación de complejidad O(n) n veces, por
lo tanto la complejidad es O(n^2).
====================================================================================================
*/

void concatenarListas(Lista &l1, Lista &l2){
    int i;
    int n = l2.longLista();
    for(i = 1; i <= n; ++i){
        l1.anxLista(l2.infoLista(i));
    }
}