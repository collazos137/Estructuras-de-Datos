/*
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // May 12st 2023
====================================================================================================
Complejidad : O(n)
====================================================================================================
La complejidad de para cada caso (entendiendo cada caso como cada combinación de letras dada después
del primer '#') estaría descrita por la ecuación t(n) = n*25 + n*26, siendo n la cantidad de palabras
proporcionadas en la primera parte. Como sé específica en el problema la cantidad máxima de letras 
por palabras es 25, además de eso por cada palabra debe crear una copia del arreglo donde sé contiene
información de la combinación de letras; como este arreglo contiene siempre todo el abecedario 
(26 caracteres) la complejidad de hacer una copia seria O(1) por tanto en el peor de los casos 
la complejidad seria O(n(25 + 26)) simplificando O(n).
====================================================================================================
*/
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<string> words(1000);
    char dic[26], dicax[26];
    string strax1;
    char charax;
    int flag1 = 1, flag2, flag3;
    int i = 0, j;
    int ans, n;
    while(flag1){
        cin >> strax1;
        if(strax1 != "#"){
            words[i] = strax1;
            ++i;
        }else flag1 = 0;
    }
    n = i;
    scanf("%c", &charax);
    flag1 = 1;
    while(flag1){
        for(i = 0; i < 26; ++i) 
            dic[i] = 0;
        flag2 = 1;
        while(flag2 && flag1){
            scanf("%c", &charax);
            if(charax == '#') 
                flag1 = 0;
            else if(charax == '\n') 
                flag2 = 0;
            else if(charax != ' ') 
                dic[charax - 'a'] += 1;
        }
        if(flag1){
            ans = 0;
            for(i = 0; i < n; ++i){
                for(j = 0; j < 26; ++j) 
                    dicax[j] = dic[j];
                j = 0;
                flag3 = 1;
                while(j < words[i].size() && flag3){
                    if(dicax[words[i][j] - 'a'] == 0)
                        flag3 = 0;
                    else 
                        dicax[words[i][j] - 'a'] -= 1;
                    ++j;
                }
                if(flag3) ans += 1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}