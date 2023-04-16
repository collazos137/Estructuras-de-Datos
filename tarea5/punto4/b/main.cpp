/*
Punto 4 - a
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // April 16st 2023
====================================================================================================*/
#include "lista.h"

void concatenarListas(Lista l1, Lista l2);

int main(){
    Lista l1;
    Lista l2;
    Lista l3;
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

    l3 = l1 + l2;

    cout << "Lista1 + Lista2 : [";
    for(i = 1; i < l3.longLista(); ++i)
        cout << l3.infoLista(i) << ", ";
    cout << l3.infoLista(i) << "]" << endl;

    return 0;
}
