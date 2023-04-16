/*
Punto 1 - 2
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // April 12st 2023
====================================================================================================*/
#include "lista.h"

int contarOcurrencias(Lista l, int v);
Lista obtenerMenores(Lista l, int v);

int main(){
    Lista l, menores;
    int arr[] = {1, 3, 5, 7, 8, 9, 9, 4, 2, 2, 2};
    int i, ocurrencias;
    for(i = 0; i < sizeof(arr)/sizeof(int); ++i)
        l.anxLista(arr[i]);

    cout << "Elementos de la lista : [";
    for(i = 1; i < l.longLista(); ++i)
        cout << l.infoLista(i) << ", ";
    cout << l.infoLista(i) << "]" << endl;

    ocurrencias = contarOcurrencias(l, 2);
    cout << "Ocurrecias del numero 2: " << ocurrencias << endl;

    menores = obtenerMenores(l, 7);
    cout << "Elementos de la lista que son menores que el numero 7: [";
    for(i = 1; i < menores.longLista(); ++i)
        cout << menores.infoLista(i) << ", ";
    cout << menores.infoLista(i) << "]" << endl;

    return 0;
}
/*Punto 1 : contarOcurrencias
====================================================================================================
|funciones TAD usadas | Complejidad | Explicación
----------------------------------------------------------------------------------------------------
|longLista()          |  O(n)      | siendo n el tamaño de la lista.
----------------------------------------------------------------------------------------------------
|infoLista()          |  O(n)      | siendo n la posición que se le pasa a la función.
====================================================================================================
Complejidad de "contarOcurrencias()" : O(n^2) siendo n el tamaño de la lista
----------------------------------------------------------------------------------------------------
Explicación: la operación 'longLIsta()' retorna el tamaño de la lista (que llamaremos 'n') por tanto
el ciclo se repite n veces y dentro de ciclo se encuentra la operación 'infoLista()' que tiene complejidad
O(n), estamos invocando una operación de complejidad O(n) n veces, por lo tanto la complejidad es O(n^2).
====================================================================================================
*/

int contarOcurrencias(Lista l, int v){
    int ans = 0;
    int len = l.longLista();
    for(int i = 1; i <= len; ++i){
        if(l.infoLista(i) == v){
            ++ans;
        }
    }
    return ans;
}

/*Punto 2 : obtenerMenores
====================================================================================================
|funciones TAD usadas | Complejidad | Explicación
----------------------------------------------------------------------------------------------------
|longLista()          |  O(n)       | siendo n el tamaño de la lista.
----------------------------------------------------------------------------------------------------
|infoLista()          |  O(n)       | siendo n la posición que se le pasa a la función.
----------------------------------------------------------------------------------------------------
|anxLista()           |  O(1)       | por estar usando una lista doblemente enlazada circular, la operación 
|                     |             | de añadir un elemento al final se hacen en tiempo constante.
====================================================================================================
Complejidad de "obtenerMenores()" : O(n^2) siendo n el tamaño de la lista.
-----------------------------------------------------------------------------------------------------------
Explicación: la operación 'longLIsta()' retorna el tamaño de la lista (que llamaremos 'n') por tanto
el ciclo se repite n veces y dentro de ciclo se encuentra la operación 'infoLista()' que tiene complejidad
O(n) y la operación 'anxLista' (pero esta se invoca cuando el elemento de listas es menor al valor 'v') 
de complejidad O(1), estamos invocando una operación de complejidad O(n) n veces, por lo tanto la 
complejidad es O(n^2).
====================================================================================================
*/

Lista obtenerMenores(Lista l, int v){
    Lista ans;
    int ax;
    int len = l.longLista();
    for(int i = 1; i <= len; ++i){
        ax = l.infoLista(i);
        if(ax < v){
            ans.anxLista(ax);
        }
    }
    return ans;
}