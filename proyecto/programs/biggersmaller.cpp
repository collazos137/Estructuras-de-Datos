#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;

/* Estructura ======================================================================================================================================*/

class BigInteger{
    private:
        vector<int> digt;
        int sign;
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
        string toString();
        int signf();
        int size();

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

/*= Constructoras =================================================================================================================*/

BigInteger::BigInteger(const string& str){
    int len, n;
    n = (str[0] == '-') ? 1 : 0;
    sign = n;
    len = str.size() - n;
    digt.resize(len);
    for(int i = 0; i < len; ++i)
        digt[len - i - 1] = str[i + n] - '0';
    
}

/* = Operadores ======================================================================================================================================*/

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

int BigInteger::operator[](int pos){
    return digt[pos];
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

/*======================================================================================================================================*/

int main(){
    int nCase = 1;
    int i, j;
    bool flag1, flag2;
    string num1, num2;
    string ax1, ax2;
    while(cin >> num1){
        cout << "Case " << nCase++ << ": ";
        ax1 = "";
        ax2 = "";
        cin >> num2;
        i = 0;
        while(num1[i] != '.')
            ax1 += num1[i++];
        j = 0;
        while(num2[j] != '.')
            ax2 += num2[j++];

        BigInteger big1(ax1);
        BigInteger big2(ax2);

        if(big1 < big2){
            cout << "Smaller" << endl;
        }else if(big2 < big1){
            cout << "Bigger" << endl;
        }else{
            ax2 = "";
            ax1 = "";
            ++i;
            ++j;
            flag1 = false;
            flag2 = false;
            while(num1.size() > i && num2.size() > j){
                if(!flag1 && num1[i] != '0')
                    flag1 = true;
                if(!flag2 && num2[i] != '0')
                    flag2 = true;
                
                if(num1.size() > i)
                    ax1 += num1[i++];
                else
                    ax1 += '0';

                if(num2.size() > j)
                    ax2 += num2[j++];
                else
                    ax2 += '0';
            }
            BigInteger big1(ax1);
            BigInteger big2(ax2);

            if(big1 < big2){
                cout << "Smaller" << endl;
            }else if(big2 < big1){
                cout << "Bigger" << endl;
            }else{
                cout << "Same" << endl;
            }
        }
    }
    return 0; 
}