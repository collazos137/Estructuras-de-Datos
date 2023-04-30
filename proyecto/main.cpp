#include "bigInteger.h"
#include <iostream>

int main(){
    BigInteger num1("789634412566398759852");
    BigInteger num2("741852963");
    //
    //num1.display();
    //string ans = (num1 <= num2) ? "true" : "false";

    cout << num1.toString() <<  " % " << num2.toString() << " : ";
    num1.remainder(num2);
    num1.display();
    /*while(num2 <= num1){
        num1.substract(num2);
        num1.display();
        //num2.display();
    }*/

    //num1.product(num2);
    //num1.display();
    
    
    return 0;
}
