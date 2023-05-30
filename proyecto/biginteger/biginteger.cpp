/*
 * Autor: Juan Diego Collazos Mejía
 * Date: 29 May 2023
 * 
 * Impemnetacion Estructura BigInteger 
 */

#include "biginteger.h"

/*= Constructoras =================================================================================================================*/

/*
Constructor por defecto
Entrada: Ninguna
*/
BigInteger::BigInteger(){
    sign = false;
    digt = { 0 };
}

/*
Constructor que recibe string
Entrada: Un string del número a representar.
*/
BigInteger::BigInteger(const string& str){
    int len, n;
    n = (str[0] == '-') ? 1 : 0;
    sign = (n)? true : false;
    len = str.size() - n;
    digt.resize(len);
    for(int i = 0; i < len; ++i)
        digt[len - i - 1] = str[i + n] - '0';
    
}

/*
Constructor que recibe un Bigintger
Entrada: Un Bigintger a copiar.
*/
BigInteger::BigInteger(const BigInteger& num){
    sign = num.sign;
    digt = num.digt;
}

/* = Modificadoras ===========================================================================================================*/
    /* - Auxiliares ----------------------------------------------------------------------------------------------------------*/

/*
Operación sum
Entrada: Un vector de enteros y un objeto BigIngeger.
Descripción: Esta operación le suma al vector el número representado en el Biginteger.
*/
void sum(vector<int>& num1, BigInteger& num2){
    int n = (num1.size() > num2.size()) ? num1.size() : num2.size();
    int acu = 0, sum, i;
    num1.resize(n + 1);
    for(i = 0; i < n ; ++i){
        sum = acu;
        if(i < num1.size()) 
            sum += num1[i];
        if(i < num2.size()) 
            sum += num2[i];
        num1[i] = sum % 10;
        acu = sum / 10;
    }
    if(acu)
        num1[i] = acu;
    else
        num1.resize(n);
}

/*
Operación rest
Entrada: Un vector de enteros y un objeto BigIngeger.
Descripción: Esta operación le resta al vector el número representado en el Biginteger.
(Para que funcione correctamente, el valor representado en el vector debe de ser mayor al representado en el Biginteger).
*/
void rest(vector<int>& num1, BigInteger& num2){
    int flag2 = 0, i = 0, flag1 = 1, flag3 = 1, ax;
    while(i < num1.size() && flag1){
        if(i < num2.size()){
            if(num1[i] < num2[i]){
                num1[i] += 10;
                flag2 = 1;
            }
            num1[i] -= num2[i];
        }else if(!flag2) 
            flag1 = 0;

        if(flag2){
            if(num1[i + 1] != 0){
                num1[i + 1] -= 1;
                flag2 = 0;
            }else
                num1[i + 1] = 9;
        }
        if(num1[i] == 0){
            if(flag3 && i != 0){
                ax = i;
                flag3 = 0;
            }
        }else
            flag3 = 1;
        ++i;
    }
    if(!flag3 && (i == num1.size()))
        num1.resize(ax);
}

/*
Función divisionAux.
Entrada: Un vector de enteros y un objeto BigIngeger.
Salida: Un vector de enteros que el resultado de dividir de manera entera el numero representado en el vector sobre el Bigintger.
(Además de calcular la razón convierte al vector de entrada en el módulo de num1 % numn2).
*/
vector<int> divisionAux(vector<int>& num1, BigInteger& num2){
    int itBegin, itFinish, itNum1, itNum2;
    int  itAux, rationLen;
    bool flag1, flag2, flag3;
    bool compare;
    itBegin = num1.size() - 1;
    itFinish = itBegin - num2.size() + 1;
    if(num1.size() >= num2.size()){
        rationLen = num1.size() - num2.size() + 1;
        flag1 = true;
    }else{
        rationLen = 1;
        flag1 = false;
    }
    vector<int> ration(rationLen, 0);
    while(flag1 && itFinish >= 0){
        itNum1 = itBegin;
        itNum2 = num2.size() - 1;
        compare = true;
        flag2 = true;
        while(itNum2 >= 0 && flag2){
            if(num2[itNum2] != num1[itNum1]){
                compare = num1[itNum1] > num2[itNum2];
                flag2 = false;
            }
            --itNum2;
            --itNum1;
        }

        if(flag2) compare = true;
        
        if(!compare){
            if(itFinish > 0) 
                --itFinish; 
            else 
                flag1 = false;
        }

        if(flag1){
            ration[itFinish] += 1;
            itNum1 = itFinish;
            itNum2 = 0;
            itAux = itFinish - 1;
            flag3 = false;
            while(itBegin >= itNum1){
                if(flag3){
                    if(num1[itNum1]){
                        --num1[itNum1];
                        flag3 = false;
                    }else 
                        num1[itNum1] = 9;
                }
                if(itNum2 < num2.size()){
                    if(num2[itNum2] > num1[itNum1]){
                        num1[itNum1] += 10;
                        flag3 = true;
                    }
                    num1[itNum1] -= num2[itNum2];
                }
                if(num1[itNum1]) 
                    itAux = itNum1;
                ++itNum2;
                ++itNum1;
            }
            while(!num1[itAux] && itAux > 0)
                --itAux;

            itFinish = itAux - num2.size() + 1;
            itBegin = itAux;
        }
    }
    if(itBegin >= 0) 
        num1.resize(itBegin + 1);
    else 
        num1.resize(1);
    
    return ration;
}

/*
Operación productVector.
Entrada: Dos vectores de enteros.
Salida: Un vector de enteros que el resultado de multiplicar los dos números representados en los vectores de entrada.
*/
void productVector(vector<int>& num1, vector<int>& num2){
    vector<int> ans(num1.size() + num2.size());
    int product, i, j, acu = 0;
    for(i = 0; i < num1.size(); ++i){
        acu = 0;
        for(j = 0; j < num2.size(); ++j){
            product = (num1[i] * num2[j]) + ans[i + j] + acu;
            ans[i + j] = product % 10;
            acu = product / 10;
        }
        if(acu) ans[i + j] += acu; 
    }
    num1 = ans;
    if(!num1[num1.size() - 1] && num1.size() != 1) 
        num1.resize(num1.size() - 1);
}

    /* - Canonicas ----------------------------------------------------------------------------------------------------------------*/

/*
Operación add.
Entrada: Un Biginteger.
Descripción: Convierte al objeto actual en el resultado de sumarlo con el objeto de entrada.
*/
void BigInteger::add(BigInteger& num2){
    if(signf() == num2.signf())
        sum(digt, num2);
    else{
        if(esMenorOIgual(num2, digt)){
            rest(digt, num2);
            if(!digt[size() - 1]) 
                sign = false;
        }else{
            BigInteger ax1(*this);
            vector<int> ax2(num2.size());
            for(int i = 0; i < num2.size() ; ++i)
                ax2[i] = num2[i];
            rest(ax2, ax1);
            sign = num2.signf();
            digt = ax2;
        }
    }
}

/*
Operación substract.
Entrada: Un Biginteger.
Descripción: Convierte al objeto actual en el resultado de restarlo con el objeto de entrada.
*/
void BigInteger::substract(BigInteger& num2){
    if(signf() != num2.signf())
        sum(digt, num2);
    else{
        if(esMenorOIgual(num2, digt)){
            rest(digt, num2);
            if(!digt[size() - 1]) 
                sign = false;
        }else{
            BigInteger ax1(*this);
            vector<int> ax2(num2.size());
            for(int i = 0; i < num2.size() ; ++i)
                ax2[i] = num2[i];
            rest(ax2, ax1);
            sign = !num2.signf();
            digt = ax2;
        }
    }
}

/*
Operación product.
Entrada: Un Biginteger.
Descripción: Convierte al objeto actual en el resultado de multiplicarlo con el objeto de entrada.
*/
void BigInteger::product(BigInteger& num2){
    sign = !(num2.signf() == sign);
    if(num2.size() == 1 && num2[0] == 0 || digt.size() == 1 && digt[0] == 0){
        sign = false;
        digt = { 0 };
    }else if(!(num2.size() == 1 && num2[0] == 1)){
        vector<int> ans(size() + num2.size());
        int product, i, j, acu = 0;
        for(i = 0; i < size(); ++i){
            acu = 0;
            for(j = 0; j < num2.size(); ++j){
                product = (digt[i] * num2[j]) + ans[i + j] + acu;
                ans[i + j] = product % 10;
                acu = product / 10;
            }
            if(acu) ans[i + j] += acu; 
        }
        digt = ans;
        if(digt[digt.size() - 1] == 0)
            digt.resize(ans.size() - 1);
    }
}

/*
Operación quotient.
Entrada: Un Biginteger.
Descripción: Convierte al objeto actual en el resultado de dividirlo por el objeto de entrada.
*/
void BigInteger::quotient(BigInteger& num2){
    sign = !(num2.signf() == sign);
    if(!(num2.size() == 1 && num2[0] == 1)){
        digt = divisionAux(digt, num2);
        if(!digt[digt.size() - 1] && digt.size() != 1)
            digt.resize(digt.size() - 1);
    }
}

/*
Operación remainder.
Entrada: Un Biginteger.
Descripción: Convierte al objeto actual en el resultado de aplicar la operacion modulo por el objeto de entrada.
*/
void BigInteger::remainder(BigInteger& num2){
    divisionAux(digt, num2);
}

/*
Operación pow.
Entrada: Un entero.
Descripción: Convierte al objeto actual en el resultado de elevarlo teniendo como exponente el entero de entrada.
*/
void BigInteger::pow(int num2){
    if(sign && !(num2 % 2)) sign = false;
    vector<int> rest = { 1 };
    while(num2 > 0){
        if(num2 % 2)
            productVector(rest, digt);
        productVector(digt, digt);
        num2 /= 2;
    }
    digt = rest;
}

/*= Analizadoras ===================================================================================================================*/
        /* - Auxiliares ----------------------------------------------------------------------------------------------------------*/

/*
Función signf.
Entrada: Ninguna.
Salida: Un bool que representa signo del objeto actual (Flase : +, True : -).
*/
bool BigInteger::signf(){
    return sign;
}

/*
Función size.
Entrada: Ninguna.
Salida: Un entero que presenta el número de dígitos de objeto actual.
*/
int BigInteger::size(){
    return digt.size();
}
        /* - Canonicas ----------------------------------------------------------------------------------------------------------------*/

/*
Función toString.
Entrada: Ninguna.
Salida: Un string que representa el signo y los dígitos del objeto actual.
*/
string BigInteger::toString(){
    string ans = "";
    if(sign) ans += '-';
    for(int i = size() - 1; i >= 0 ; --i){
        ans += digt[i] + '0'; 
    }
    return ans;
}

/* = Operadores ======================================================================================================================================*/
    /* Aritmético ----------------------------------------------------------------------------------------------------------*/

/*
Operador '+'.
Entrada: Un BigInteger.
Salida: Un Bigintger que es el resultado de la suma del objeto actual con el de entrada.
*/
BigInteger BigInteger::operator+(BigInteger& num2){
    BigInteger ans(*this);
    ans.add(num2);
    return ans;
}

/*
Operador '-'.
Entrada: Un BigInteger.
Salida: Un Bigintger que es el resultado de la resta del objeto actual con el de entrada.
*/
BigInteger BigInteger::operator-(BigInteger& num2){
    BigInteger ans(*this);
    ans.substract(num2);
    return ans;
}

/*
Operador '*'.
Entrada: Un BigInteger.
Salida: Un Bigintger que es el resultado de la multiplicación del objeto actual por el de entrada.
*/
BigInteger BigInteger::operator*(BigInteger& num2){
    BigInteger ans(*this);
    ans.product(num2);
    return ans;
}

/*
Operador '/'.
Entrada: Un BigInteger.
Salida: Un Bigintger que es el resultado de la división del objeto actual sobre el de entrada.
*/   
BigInteger BigInteger::operator/(BigInteger& num2){
    BigInteger ans(*this);
    ans.quotient(num2);
    return ans;
}

/*
Operador '%'.
Entrada: Un BigInteger.
Salida: Un Bigintger que es el resultado del objeto actual modulo el objeto de entrada.
*/      
BigInteger BigInteger::operator%(BigInteger& num2){
    BigInteger ans(*this);
    ans.remainder(num2);
    return ans;
}

    /* Analiazdores ----------------------------------------------------------------------------------------------------------*/
        /* - Auxiliares ----------------------------------------------------------------------------------------------------------*/

/*
Función esMenorOIgual.
Entrada: Un BigInteger y un vector.
Salida: Un bool que es true si la representación del primer parámetro es menor o igual al segundo y false en caso contrario.
*/     
bool esMenorOIgual(BigInteger& num1, vector<int>& num2){
    bool ans;
    int i = num1.size() - 1, flag = 1;
    if(num1.size() != num2.size()){
        ans = num1.size() < num2.size();
    }else{
        while(i >= 0 && flag){
            if(num1[i] != num2[i]){
                ans = num1[i] < num2[i];
                flag = 0;
            }
            --i;
        }
        if(flag) ans = true;
    }
    return ans;
}

/*
Operador '[]'.
Entrada: Un entero.
Salida: Un entero que es el valor que se encuentra en la posición de del entero de entrada.
*/    
int BigInteger::operator[](int pos){
    return digt[pos];
}

        /* - Canonicos ----------------------------------------------------------------------------------------------------------------*/

/*
Operador '=='.
Entrada: Un Binteger.
Salida: Un bool que es true si la representación del objeto actual es igual al de entrada y false en caso contrario.
*/    
bool BigInteger::operator==(BigInteger& num2){
    bool ans;
    int i = size() - 1, flag = 1;
    if(sign != num2.signf()){
        ans = false;
    }else if(size() != num2.size()){
        ans = false;
    }else{
        while(i >= 0 && flag){
            if(digt[i] != num2[i])
                flag = 0;
            --i;
        }
        ans = flag;
    }
    return ans;
}

/*
Operador '<'.
Entrada: Un Binteger.
Salida: Un bool que es true si la representación del objeto actual es menor al de entrada y false en caso contrario.
*/   
bool BigInteger::operator<(BigInteger& num2){
    bool ans;
    int i = size() - 1, flag = 1;
    if(sign != num2.signf()){
        ans = !num2.signf();
    }else if(size() != num2.size()){
        ans = (sign) ? size() > num2.size() : size() < num2.size();
    }else{
        while(i >= 0 && flag){
            if(digt[i] != num2[i]){
                ans = (sign) ? digt[i] > num2[i] : digt[i] < num2[i];
                flag = 0;
            }
            --i;
        }
        if(flag) ans = false;
    }
    return ans;
}

/*
Operador '<='.
Entrada: Un Binteger.
Salida: Un bool que es true si la representación del objeto actual es menor o igual al de entrada y false en caso contrario.
*/   
bool BigInteger::operator<=(BigInteger& num2){
    bool ans;
    int i = size() - 1, flag = 1;
    if(sign != num2.signf()){
        ans = !num2.signf();
    }else if(size() != num2.size()){
        ans = (sign) ? size() > num2.size() : size() < num2.size();
    }else{
        while(i >= 0 && flag){
            if(digt[i] != num2[i]){
                ans = (sign) ? digt[i] > num2[i] : digt[i] < num2[i];
                flag = 0;
            }
            --i;
        }
        if(flag) ans = true;
    }
    return ans;
}

/* operaciones estáticas =========================================================================================================================================*/

/*
Función sumarListaValores.
Entrada: Una Lista de Bigintegers.
Salida: Un Biginteger que es el resultado de sumar entre si todos lo elementos de la lista.
*/   
BigInteger BigInteger::sumarListaValores(list<BigInteger>& l ){
    list<BigInteger>::iterator it;
    BigInteger ans = *l.begin();
    for(it = ++l.begin(); it != l.end(); ++it)
        ans.add(*it);
    return ans;
}

/*
Función sumarListaValores.
Entrada: Una Lsita de Bigintegers.
Salida: Un Biginteger que es el resultado de multiplicar entre si todos lo elementos de la lista.
*/   
BigInteger BigInteger::multiplicarListaValores(list<BigInteger>& l){
    list<BigInteger>::iterator it;
    BigInteger ans = *l.begin();
    for(it = ++l.begin() ; it != l.end(); ++it)
        ans.product(*it);
    return ans;
}

/*================================================================================================================================================================*/