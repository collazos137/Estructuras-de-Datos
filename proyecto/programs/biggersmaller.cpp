#include "..\biginteger\biginteger.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int nCase = 0;
    int i;
    string num1, num2;
    string ax1, ax2;
    while(cin >> num1){
        cin >> num2;
        i = 0;
        while(num1[i] != '.')
            ax1 += num1[i++];
        i = 0;
        while(num2[i] != '.')
            ax2 += num2[i++];

        BigInteger big1(ax1);
        BigInteger big2(ax2);
        
        cout << ax1 << endl;
        cout << ax2 << endl;
    }
    return 0; 
}