#include "biginteger.h"

/*= Constructoras =================================================================================================================*/

BigInteger::BigInteger(const string& str){
    int len, i, n;
    n = (str[0] == '-') ? 1 : 0;
    sign = n, len = str.size() - n;
    digt.resize(len);
    for(i = 0; i < len; ++i)
        digt[len - i - 1] = str[i + n] - '0';
}

BigInteger::BigInteger(const BigInteger& num){
    sign = num.sign;
    digt = num.digt;
}

/* = Modificadoras ===========================================================================================================*/
    /* - Auxiliares ----------------------------------------------------------------------------------------------------------*/
void sum(vector<int>& num1, vector<int>& num2){
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

void rest(vector<int>& num1, vector<int>& num2){
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

vector<int> powAux(vector<int>& digt, int num2){
    vector<int> ans;
    if(num2 == 0){
        ans.push_back(1);
    }else if(num2 == 1){
        ans = digt;
    }else if(num2 % 2 == 0){
        ans = powAux(digt, num2/2);
        productVector(ans, ans);
    }else{
        ans = powAux(digt, (num2-1)/2);
        productVector(ans, ans);
        productVector(ans, digt);
    }
    return ans;
}

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

void BigInteger::add(BigInteger &num2){
    vector<int> ax(num2.size());
    for(int i = 0; i < num2.size() ; ++i)
        ax[i] = num2[i];

    if(signf() == num2.signf())
        sum(digt, ax);
    else{
        if(ax <= digt){
            rest(digt, ax);
            if(!digt[size() - 1]) 
                sign = 0;
        }else{
            rest(ax, digt);
            sign = num2.signf();
            digt = ax;
        }
    }
}

void BigInteger::substract(BigInteger &num2){
    vector<int> ax(num2.size());
    for(int i = 0; i < num2.size() ; ++i)
        ax[i] = num2[i];

    if(signf() != num2.signf())
        sum(digt, ax);
    else{
        if(ax <= digt){
            rest(digt, ax);
            if(!digt[size() - 1]) 
                sign = 0;
        }else{
            rest(ax, digt);
            sign = (!num2.signf()) ? 1 : 0;
            digt = ax;
        }
    }
}

void BigInteger::product(BigInteger& num2){
    if(num2.size() == 1 && num2[num2.size() - 1] == 0){
        sign = 0;
        digt = { 0 };
    }else if(!(num2.size() == 1 && num2[num2.size() - 1] == 1)){
        sign = (num2.signf() == sign) ? 0 : 1;
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

void BigInteger::quotient(BigInteger& num2){
    sign = (num2.signf() == sign)? 0 : 1;
    int flag1 = 1, flag2, flag3, i = size() - 1, t, j, k, n, l;
    l = (size() >= num2.size()) ? size() - num2.size() + 1 : 1;
    vector<int> ans(l, 0);
    while(flag1 && i >= num2.size() - 1){
        t = i, flag2 = 1, k = num2.size() - 1, j = t;
        while(k >= 0){
            if(num2[k] != digt[j]){
                flag2 = digt[j] > num2[k];
                k = 0;
            }
            --k, --j;
        }
        if(!flag2){
            if(t > num2.size() - 1) 
                --t; 
            else 
                flag1 = 0;
        }
        if(flag1){
            k = 0, j = t - num2.size() + 1, flag3 = 0, n = i;
            ans[j] += 1;
            while(j <= n){
                if(flag3){
                    if(digt[j]){
                        --digt[j];
                        flag3 = 0;
                    }else 
                        digt[j] = 9;
                }
                if(k < num2.size()){
                    if(num2[k] > digt[j]){
                        digt[j] += 10;
                        flag3 = 1;
                    }
                    digt[j] -= num2[k];
                }
                if(digt[j]) 
                    i = j;
                ++k, ++j;
            }
        }
    }
    digt = ans;
    if(!digt[digt.size() - 1] && digt.size() != 1) 
        digt.resize(digt.size() - 1);
}

void BigInteger::remainder(BigInteger& num2){
    int flag1 = 1, flag2, flag3, i = size() - 1, t, j, k, n;
    while(flag1 && i >= num2.size() - 1){
        t = i, flag2 = 1, k = num2.size() - 1, j = t;
        while(k >= 0){
            if(num2[k] != digt[j]){
                flag2 = digt[j] > num2[k];
                k = 0;
            }
            --k, --j;
        }
        if(!flag2){
            if(t > num2.size() - 1)
                --t;
            else 
                flag1 = 0;
        }
        if(flag1){
            k = 0, j = t - num2.size() + 1, flag3 = 0, n = i;
            while(j <= n){
                if(flag3){
                    if(digt[j]){
                        --digt[j];
                        flag3 = 0;
                    }else 
                        digt[j] = 9;
                }
                if(k < num2.size()){
                    if(num2[k] > digt[j]){
                        digt[j] += 10;
                        flag3 = 1;
                    }
                    digt[j] -= num2[k];
                }
                if(digt[j]) 
                    i = j;
                ++k, ++j;
            }
        }
    }
    digt.resize(++i);
}

void BigInteger::pow(int num2){
    digt = powAux(digt, num2);
}

/*= Analizadoras ===================================================================================================================*/
        /* - Auxiliares ----------------------------------------------------------------------------------------------------------*/

int BigInteger::signf(){
    return sign;
}

int BigInteger::size(){
    return digt.size();
}
        /* - Canonicas ----------------------------------------------------------------------------------------------------------------*/

string BigInteger::toString(){
    string ans = "";
    if(sign) ans += '-';
    for(int i = size() - 1; i >= 0 ; --i){
        ans += digt[i] + '0'; 
    }
    return ans;
}

/* = Operadores ======================================================================================================================================*/
    /* Modificadores ----------------------------------------------------------------------------------------------------------*/

BigInteger BigInteger::operator+(BigInteger& num2){
    BigInteger ans(*this);
    ans.add(num2);
    return ans;
}

BigInteger BigInteger::operator-(BigInteger& num2){
    BigInteger ans(*this);
    ans.substract(num2);
    return ans;
}

BigInteger BigInteger::operator*(BigInteger& num2){
    BigInteger ans(*this);
    ans.product(num2);
    return ans;
}
        
BigInteger BigInteger::operator/(BigInteger& num2){
    BigInteger ans(*this);
    ans.quotient(num2);
    return ans;
}
        
BigInteger BigInteger::operator%(BigInteger& num2){
    BigInteger ans(*this);
    ans.remainder(num2);
    return ans;
}

    /* Analiazdores ----------------------------------------------------------------------------------------------------------*/
        /* - Auxiliares ----------------------------------------------------------------------------------------------------------*/

bool operator<=(vector<int>& num1, vector<int>& num2){
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

int BigInteger::operator[](int pos){
    return digt[pos];
}

        /* - Canonicos ----------------------------------------------------------------------------------------------------------------*/

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

BigInteger sumarListaValores(list<BigInteger>& l ){
    list<BigInteger>::iterator it;
    BigInteger ans = *l.begin();
    for(it = ++l.begin(); it != l.end(); ++it)
        ans.add(*it);
    return ans;
}

BigInteger multiplicarListaValores(list<BigInteger>& l){
    list<BigInteger>::iterator it;
    BigInteger ans = *l.begin();
    for(it = ++l.begin() ; it != l.end(); ++it)
        ans.product(*it);
    return ans;
}

/*================================================================================================================================================================*/