
#include <iostream>
#include <cmath>
#include <string>
#include "./Files/BigInt.hpp"
using namespace std;

const bool is_prime(const int& n) {

    if (n == 2 || n == 3) return true; // 2 and 3 are prime, check 2 before 1 because it is even

    if (n < 2  || n % 2 == 0) return false; // numbers less than 1 return false, 1 is not prime, and every even number returns false

    for (int div = 3; div <= sqrt(n); div += 2) { // it's enough to check numbers up to the square root

        if (n % div == 0) return false; // n is divisble by a number less than its square root
    }
    return true; // reached the square root and no numbers could divide n
}

void remove_zeros(string& number){

    short i=0;
    short cut=0;
    while(i < number.length()){

        if(number[i]!='0') cut = i;
        i++;
    }
    number = number.substr(0, cut+1);
}

const short cycle_length(const BigInt& number){

    BigInt ten_2000 = BigInt(10);
    for(short i=0; i<1000*2; i++) ten_2000 *= 10;

    string cycle = (ten_2000/number).to_string();
    remove_zeros(cycle);
    // cout << cycle.substr(0, 70) << endl;

    short i = 6;
    while(i < cycle.length()){

        // cout << cycle.substr(0, i) << " against " << cycle.substr(i, i) << endl;
        if(cycle.substr(0, i)==cycle.substr(i, i)) return i;

        i++;
    }

    return 1;
}

int main(){

    short max_cycle = 7;
    short max_cycle_length = 6;
    short new_cl;

    // cout << cycle_length(501) << endl;
    // exit(0);

    for(short i = 7; i<997; i+=2){

        if(is_prime(i)){

            new_cl = cycle_length(i);
            if(new_cl > max_cycle_length){

                max_cycle_length = new_cl;
                max_cycle = i;
                cout << "New maximum for " << i << ": " << new_cl << endl;

            }
        }
        if(i%101==0) cout << "Passed " << i << endl;
    }

    return 0;
}