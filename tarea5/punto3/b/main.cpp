/*
Punto 3 - b
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // April 14st 2023
====================================================================================================*/
#include "lista.h"

int main(){
    Lista l;
    int i, arry[] = {8, 9, 10, 1, 26, 12, 99, 66, 26, 11, -45};

    cout << "Elementos a ingresar en lista : [ ";
    for(i = 0; i < sizeof(arry)/sizeof(int) - 1 ; ++i)
        cout << arry[i] << ", ";
    cout << arry[i] << "]" << endl;

    for(i = 0; i < sizeof(arry)/sizeof(int) ; ++i)
        l.insListaOrdenada(arry[i]);
    
    cout << "Lista Ordenada : [";
    for(i = 1; i < l.longLista(); ++i)
        cout << l.infoLista(i) << ", ";
    cout << l.infoLista(i) << "]" << endl;

    return 0;
}