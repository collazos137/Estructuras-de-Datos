/*
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // March 20st 2023
====================================================================================================
Complejidad : O(n)
====================================================================================================
La complejidad de decodificar cada mensaje es O(n) (procesamiento), siendo n la cantidad de códigos
morse ingresados en el respectivo caso, y la complejidad de encontrar cada código en la lista es O(1)
amortizado, como la cantidad de los elementos dentro del vector no cambia la complejidad de la
operación find() es siempre constante en el peor de los casos (53 elementos).

La complejidad de la lectura de datos es lineal O(n) siendo n la cantidad de caracteres que compone 
cada mensaje.
====================================================================================================
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int cases, i, j;
    int flag, flag2;
    int ax;
    char letter[7], symbol;
    vector<string> codeMorse = {
        ".-", "-...", "-.-.", "-..",
        ".", "..-.", "--.", "....", "..",
        ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...",
        "-", "..-", "...-", ".--", "-..-",
        "-.--", "--..", "-----", ".----", "..---",
        "...--","....-", ".....","-....", "--...",
        "---..", "----.", ".-.-.-", "--..--", "..--..",
        ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-",
        ".-...", "---...", "-.-.-.", "-...-", ".-.-.",
        "-....-", "..--.-", ".-..-.", ".--.-.",};
    vector<string> alfa = {
                 "A", "B", "C", "D",
                 "E", "F", "G", "H", "I",
                 "J", "K", "L", "M", "N",
                 "O", "P", "Q", "R", "S",
                 "T", "U", "V", "W", "X",
                 "Y", "Z", "0", "1", "2",
                 "3", "4", "5", "6", "7",
                 "8", "9", ".", ",", "?",
                 "'", "!", "/", "(", ")",
                 "&", ":", ";", "=", "+",
                 "-", "_", "\"", "@",};

    scanf("%d", &cases);
    scanf("%c", &symbol);
    for(i = 0; i < cases; ++i){
        printf("Message #%d\n", i+1);
        flag = 1;
        flag2 = 0;
        j =  0;
        while(flag){
            scanf("%c", &symbol);
            if(symbol == '\n'){
                flag = 0;
                letter[j] = '\0';
                ax = find(codeMorse.begin(), codeMorse.begin() + 53, letter) - codeMorse.begin();
                cout << alfa[ax];
                
            }else if(symbol == ' '){
                if(flag2){
                    printf(" ");
                    flag2 = 0;    
                }else{
                    letter[j] = '\0';
                    ax = find(codeMorse.begin(), codeMorse.begin() + 53, letter) - codeMorse.begin();
                    cout << alfa[ax];                   
                    j = 0;
                    flag2 = 1;
                }
            }else{
                flag2 = 0;
                letter[j] = symbol;
                ++j;
            }
        }
        printf("\n");
        if(i != cases - 1){
            printf("\n"); 
        }
    }
    return 0;
}

