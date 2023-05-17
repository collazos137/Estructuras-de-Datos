#include "bigInteger.h"
#include <list>



int main(){
    list<BigInteger> list1;
    vector<string> vec = { "123456789", "12345678", "7777888999996633325111"};
    for(int i = 0; i < vec.size(); ++i)
        list1.push_back(vec[i]);
    BigInteger ans = sumarListaValores(list1);
    cout << ans.toString() << endl;
    return 0;
}