/*
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // May 12st 2023
====================================================================================================
Complejidad : O(n)
====================================================================================================
La complejidad de producir el 'Beiju text' para cada caso es O(n) siendo n la cantidad de caracteres
ingresados, porque se recorre carácter a carácter y se guarda en una lista; como la complejidad
de añadir un elemento a una lista conociendo el iterador es O(1) la complejidad del programa resulta O(n).
====================================================================================================
*/
#include <list>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    list<char> ans;
    list<char>::iterator it = ans.begin();
    int flag1 = 1, flag2 = 1;
    char chax;
    while(flag1){
        flag2 = 1;
        while(flag2){
            if(scanf("%c", &chax) == EOF)
                flag1 = 0, flag2 = 0;
            else if(chax == '\n')
                flag2 = 0;
            else{
                if(chax == '[')
                    it = ans.begin();
                else if(chax == ']') 
                    it = ans.end();
                else 
                    ans.insert(it, chax);
            }
        }
        if(flag1){
            for(it = ans.begin(); it != ans.end(); ++it)
                cout << *it;
            cout << endl;
        }
        ans.clear();
    }
    return 0;
}