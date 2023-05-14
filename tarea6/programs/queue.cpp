/*
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // May 12st 2023
====================================================================================================
Complejidad : O(n*log(n))
====================================================================================================
La complejidad para cada caso está definida aproximadamente por la expresión t(n, m) = n*log(n) + m*log(n)
siendo n el mayor entre el número de población y el número los comandos, y m el número de comandos.

* La complejidad de la creación inicial de los map está expresada en término de O(n*log(n)), ya que 
añadir o modificar una key en un map el O(log(n)).

* La complejidad del procesamiento de todos los comandos está expresada en el orden de O(m*log(n)), 
ya que añadir o borrar un elemento al final o principio de una lista es O(1) y la complejidad de buscar
un dato en un map con su respectiva clave es O(log(n)) (en el procesamiento de cada comando se hacen 
consultas de valores alojados en el map).

* dando así una complejidad de aproximada O(n*log(n) + m*log(n)), simplificando (porque se garantiza 
que n será el mayor entre el número de población y el número los comandos) seria O(n*log(n)).
====================================================================================================
*/
#include <list>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    list<int> hosptQueue;
    int nDuplicate[1000];
    map<int, bool> attend;
    char comman;
    int nPopula, nComm;
    int flag = 1;
    int ax1, i, n, cases = 0;
    while(flag){
        cin >> nPopula;
        cin >> nComm;
        n = (nPopula < nComm) ? nPopula : nComm;
        if(nPopula != 0){
            printf("Case %d:\n", ++cases);
            for(i = 1; i <= n; ++i){
                hosptQueue.push_back(i);
                attend[i] = true;
                nDuplicate[i] = 0;
            }
            for(i = 0; i < nComm; ++i){
                cin >> comman;
                if(comman == 'E'){
                    cin >> ax1;
                    attend[ax1] = true;
                    if(hosptQueue.front() != ax1){
                        hosptQueue.push_front(ax1);
                        if(ax1 <= n) 
                            nDuplicate[ax1] += 1;
                    }
                }else{
                    while(!attend[hosptQueue.front()]){
                        if(hosptQueue.front() <= n){
                            nDuplicate[hosptQueue.front()] -= 1;
                            if(!nDuplicate[hosptQueue.front()])
                                attend[hosptQueue.front()] = true;
                        }
                        hosptQueue.pop_front();
                    }
                    cout << hosptQueue.front() << endl;
                    attend[hosptQueue.front()] = false;
                    if(hosptQueue.front() <= n){
                        hosptQueue.push_back(hosptQueue.front());
                        if(!nDuplicate[hosptQueue.front()]) 
                            attend[hosptQueue.front()] = true;
                    }
                    hosptQueue.pop_front();
                }
            }
            while(!hosptQueue.empty()) hosptQueue.pop_front();
        }else flag = 0;
    }
    return 0;
}