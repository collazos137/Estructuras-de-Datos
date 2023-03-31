/*
====================================================================================================
Juan Diego Collazos Mejia // ID: 8977837 // March 20st 2023
====================================================================================================
Complejidad : O(n)
====================================================================================================
La complejidad de decodificar cada mensaje es O(n), siendo n la cantidad de códigos morse ingresados
en el respectivo caso, y la complejidad de encontrar cada código en la lista es O(1) amortiguado, ya 
que en el peor de los casos el código buscado se encontraría al final de la lista de 53 elementos.
====================================================================================================
*/

#include <stdio.h>
#include <cstring>

void answer(char* letter, char codeMorse[][7], char alfa[][2]){
    int i = 0;
    int flag = 1;
    while(flag){
        if(strcmp(letter, codeMorse[i]) == 0){
            flag = 0;
        }
        i += 1;
    }
    printf("%s", alfa[i-1]);
}

int main(){
    int cases, i, j;
    int flag, flag2;
    char letter[7], symbol;
    char codeMorse[][7] = {
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
    char alfa[][2] = {"A", "B", "C", "D",
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
                answer(letter, codeMorse, alfa);
                
            }else if(symbol == ' '){
                if(flag2){
                    printf(" ");
                    flag2 = 0;    
                }else{
                    letter[j] = '\0';
                    answer(letter, codeMorse, alfa);                    
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

