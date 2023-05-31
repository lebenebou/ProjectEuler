
#include <iostream>
#include <cmath>
#include "./Files/BigInt.hpp"
using namespace std;

unsigned int digit_count(const BigInt& number){

    return number.to_string().length();
}


int main(){

    BigInt a(1);
    BigInt b(1);

    size_t index = 2;
    while(true){

        a = a + b;
        index++;
        // cout << a << " at index " << index << endl;
        if(digit_count(a) >= 1000){

            cout << index << endl;
            exit(0);
        }
        
        b = a + b;
        index++;
        // cout << b << " at index " << index << endl;
        if(digit_count(b) >= 1000){

            cout << index << endl;
            exit(0);
        }
    }

    return 0;
}