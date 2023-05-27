/*
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // March 20st 2023
====================================================================================================
*/
#include <stack>
#include <list>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
/*
1) eliminarPosicionesPila
====================================================================================================
Complejidad : O(n)
====================================================================================================
En el peor de los casos la lista elemento el tamaño de pila menos uno, por lo que tendra qeu recorrerse
toda la pila con el uso de una pila axuliar donde se guarden lo elementos temporalmente y posteriormente 
volver a poner todos los elemntos en pila original, por lo tanto su complejidad sera O(2n) o simplificando
O(n) siendo n la cantidad de elemento de la pila.
====================================================================================================
*/
void eliminarPosicionesPila(stack<int>& pil, list<int>& l){
    int cont = 0;
    stack<int> axu;
    list<int>::iterator it = l.begin();
    while(it != l.end()){
        if(cont != *it)
            axu.push(pil.top());
        else
            ++it;
        pil.pop();
        ++cont;
    }
    while(!axu.empty()){
        pil.push(axu.top());
        axu.pop();
    }
}
/*
2) ordenarConMonticulo
====================================================================================================
Complejidad : O(n)
====================================================================================================
Crear un heap con make_heap tiene un costo O(n) siendo n la cantidad de elementos del vector,
adicional a eso se debe hacer n veces la operacion pop_heap() que tiene un costo log(n). Por tanto 
la complejidad de organizar un vector convirtiendolo en un heap seria O(n + n*log(n)), simplifinado 
seria O(n*log(n)).
====================================================================================================
*/
void ordenarConMonticulo(vector<int>& vec){
    make_heap(vec.begin(), vec.end());
    vector<int>::iterator it = vec.end();
    while(it != vec.begin()){
        pop_heap(vec.begin(), it);
        --it;
    }
}
/*
3) verificarOrdenadoCola
====================================================================================================
Complejidad : O(n)
====================================================================================================
En todos lo casos este algoritmo tendra complejidad O(n) siendo n la cantidad de elementos en la
cola, basicamente recorre una vez toda la cola quitando elementos del front y encolandolos de nuevo, y
al mismo tiempo verificando su orden.
====================================================================================================
*/
bool verificarOrdenadoCola(queue<int>& col ){
    int len = col.size();
    int ax1, ax2; 
    bool max = true, min = true;
    int i = 0;
    ax1 = col.front();
    col.push(ax1);
    col.pop();
    while(i < len - 1){
        ax2 = col.front();
        col.push(ax2);
        col.pop();
        if(ax1 > ax2)
            min = false;
        if(ax1 < ax2)
            max = false;
        ax1 = ax2;
        ++i;
    }
    return max || min;
}