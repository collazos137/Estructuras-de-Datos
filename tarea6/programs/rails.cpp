/*
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // May 12st 2023
====================================================================================================
Complejidad : O(n)
====================================================================================================
La complejidad de para cada caso seria O(n) siendo n la cantidad de vagones, ya que en el peor de los
casos la combinación resulta ser posible y por tanto se sacan todos los vagones del primer stack y 
posteriormente del segundo (se verifican el orden todos los vagones) como añadir y borrar elementos 
de un stack tiene complejidad O(1), entonces la complejidad resultante es aproximadamente O(2n), 
simplificando O(n).
====================================================================================================
*/
#include <stack>
#include <cstdio>

using namespace std;
int main(){
    stack<int> station;
    stack<int> rail;
    int flag1, flag2, flag3;
    int nCoaches;
    int ax1, cont;
    int i;
    flag1 = 1;
    while(flag1){
        scanf("%d", &nCoaches);
        if(nCoaches != 0){
            flag2 = 1;
            while(flag2){
                i = 0;
                while(i < nCoaches && flag2){
                    scanf("%d", &ax1);
                    if(ax1) 
                        rail.push(ax1);
                    else flag2 = 0;
                    ++i;
                }
                if(flag2){
                    flag3 = 1;
                    cont = nCoaches;
                    while(flag3){
                        if(!station.empty() && station.top() == cont){
                            station.pop();
                            --cont;
                        }else if(!rail.empty()){
                            station.push(rail.top());
                            rail.pop();
                        }else flag3 = 0;
                    }
                    if(station.empty()) 
                        printf("Yes\n");
                    else{
                        printf("No\n");
                        while(!station.empty()) station.pop();
                    }
                }
            }
            printf("\n");
        }else flag1 = 0;
    }
    return 0;
}