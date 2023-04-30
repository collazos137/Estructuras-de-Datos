/*
Autor: Juan Diego Collazos Mejia
Date: 29 April 2023

Representacion Estructura BigInteger 
 */
#ifndef BIG_INTEGER
#define BIG_INTEGER

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class BigInteger{
    private:
        vector<int> digt;
        int sign;
    public:
        /*Constructoras*/
        BigInteger(string str);
        BigInteger(BigInteger& num);

        /*Modificadoras*/
        void add(BigInteger& num2);
        void product(BigInteger& num2);
        void substract(BigInteger& num2);
        void quotien(BigInteger& num2);
        void remainder(BigInteger& num2);
        void pow(BigInteger& num2);

        /*Analizadoras*/
        string toString();
        int signf();
        int size();
         void display();

        /*Operadores*/
            /*Modificadores*/
        BigInteger operator+(BigInteger& num2);
        BigInteger operator-(BigInteger& num2);
        BigInteger operator*(BigInteger& num2);
        BigInteger operator/(BigInteger& num2);
        BigInteger operator%(BigInteger& num2);
            /*Analizadores*/
        bool operator==(BigInteger& num2);
        bool operator<(BigInteger& num2);
        bool operator<=(BigInteger& num2);
        int operator[](int pos);
        
};

#endif