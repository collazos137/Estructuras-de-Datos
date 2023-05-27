/*
 * Autor: Juan Diego Collazos Mejía
 * Date: 27 May 2023
 * 
 * Representacion Estructura BigInteger 
 */
#ifndef BIG_INTEGER
#define BIG_INTEGER

#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;

class BigInteger{
    private:
        vector<int> digt;
        bool sign;
    public:
        /*Constructoras*/
        BigInteger();
        BigInteger(const string& str);
        BigInteger(const BigInteger& num);

        /*Modificadoras*/
        void add(BigInteger& num2);
        void product(BigInteger& num2);
        void substract(BigInteger& num2);
        void quotient(BigInteger& num2);
        void remainder(BigInteger& num2);
        void pow(int num2);

        /*Analizadoras*/
            /*Canonicas*/
        string toString();
            /*Axuliares*/
        bool signf();
        int size();

        /*Operadores*/
            /*Aritmético*/
        BigInteger operator+(BigInteger& num2);
        BigInteger operator-(BigInteger& num2);
        BigInteger operator*(BigInteger& num2);
        BigInteger operator/(BigInteger& num2);
        BigInteger operator%(BigInteger& num2);
            /*Analizadores*/
                /*Canonicas*/
        bool operator==(BigInteger& num2);
        bool operator<(BigInteger& num2);
        bool operator<=(BigInteger& num2);
                /*Axuliares*/
        int operator[](int pos);


        /*Operaciones estáticas*/
        static BigInteger sumarListaValores(list<BigInteger>& l );
        static BigInteger multiplicarListaValores(list<BigInteger>& l);
};

/*Prototipos de operaciones auxiliares*/
bool operator<=(BigInteger& num1, vector<int>& num2);
void sum(vector<int>& num1, BigInteger& num2);
void rest(vector<int>& num1, BigInteger& num2);
void productVector(vector<int>& num1, vector<int>& num2);
vector<int> divisionAux(vector<int>& num1,BigInteger& num2);

#endif