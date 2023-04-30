#include "biginteger.h"

/*Constructoras*/

BigInteger::BigInteger(string str){
    int len, i, n;
    n = (str[0] == '-') ? 1 : 0;
    sign = n;
    len = str.size() - n;
    digt.resize(len);
    for(i = 0; i < len; ++i){
        digt[len - i - 1] = str[i + n] - '0';
    }
}

BigInteger::BigInteger(BigInteger& num){
    int len = num.size();
    sign = num.signf();
    digt.resize(len);
    for(int i = 0; i < len; ++i){
        digt[i] = num[i];
    }
}

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

void sum(vector<int>& num1, vector<int>& num2){
    int n = (num1.size() > num2.size()) ? num1.size() : num2.size();
    int acu = 0, sum, i;
    num1.resize(n + 1);
    for(i = 0; i < n ; ++i){
        sum = acu;
        if(i < num1.size()) sum += num1[i];
        if(i < num2.size()) sum += num2[i];
        num1[i] = sum % 10;
        acu = sum / 10;
    }
    if(acu){
        num1[i] = acu;
    }else{
        num1.resize(n);
    }
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
        }else if(!flag2){
            flag1 = 0;
        }

        if(flag2){
            if(num1[i + 1] != 0){
                num1[i + 1] -= 1;
                flag2 = 0;
            }else{
                num1[i + 1] = 9;
            }
        }
        if(num1[i] == 0){
            if(flag3 && i != 0){
                ax = i;
                flag3 = 0;
            }
        }else{
            flag3 = 1;
        }
        ++i;
    }
    if(!flag3 && (i == num1.size()))num1.resize(ax);
}

void BigInteger::add(BigInteger &num2){
    vector<int> ax(num2.size());
    for(int i = 0; i < num2.size() ; ++i){
        ax[i] = num2[i];
    }
    if(signf() == num2.signf()){
        sum(digt, ax);
    }else{
        if(ax <= digt){
            rest(digt, ax);
            if(!digt[size() - 1]) sign = 0;
        }else{
            rest(ax, digt);
            sign = num2.signf();
            digt = ax;
        }
    }
}

void BigInteger::substract(BigInteger &num2){
    vector<int> ax(num2.size());
    for(int i = 0; i < num2.size() ; ++i){
        ax[i] = num2[i];
    }
    if(signf() != num2.signf()){
        sum(digt, ax);
    }else{
        if(ax <= digt){
            rest(digt, ax);
            if(!digt[size() - 1]) sign = 0;
        }else{
            rest(ax, digt);
            sign = (!num2.signf())? 1 : 0;
            digt = ax;
        }
    }
}

void BigInteger::product(BigInteger& num2){
    sign = (num2.signf() == sign)? 0 : 1;
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
    if(digt[i - 1] == 0) digt.resize(ans.size() - 1);
}

void BigInteger::quotien(BigInteger& num2){
    vector<int> ax1(num2.size());
    vector<int> ax2;
    vector<int> ans;
    int cont = 1;
    for(int i = 0; i < num2.size() ; ++i){
        ax1[i] = num2[i];
    }

    ax2 = ax1;

    while(size() - 1 > ax2.size()){
        ax2.push_back(0);
        cont *= 10;
    }

    rest(digt, ax2);

    while(ax1 <= digt){
        rest(digt, ax1);
        ++cont;
    }
    if(!cont) ans.push_back(0);
    while(cont > 0){
        ans.push_back(cont % 10);
        cont /= 10;
    }
    digt = ans;
    
}

void BigInteger::remainder(BigInteger& num2){
    vector<int> ax(num2.size());
    for(int i = 0; i < num2.size() ; ++i){
        ax[i] = num2[i];
    }
    while(ax <= digt){
        rest(digt, ax);
    }
}

string BigInteger::toString(){
    string ans = "";
    if(sign) ans += '-';
    for(int i = size() - 1; i >= 0 ; --i){
        ans += digt[i] + '0'; 
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

int BigInteger::signf(){
    return sign;
}

void BigInteger::display(){
    if(sign) printf("-");
    for(int i = digt.size() - 1; i >= 0; --i){
        printf("%d", digt[i]);
    }
    printf("\n");
}

int BigInteger::size(){
    return digt.size();
}

int BigInteger::operator[](int pos){
    return digt[pos];
}