
#include <iostream>
#include <cmath>
using namespace std;

const bool is_prime(const int& n) {

    if (n == 2 || n == 3) return true; // 2 and 3 are prime, check 2 before 1 because it is even

    if (n < 2  || n % 2 == 0) return false; // numbers less than 1 return false, 1 is not prime, and every even number returns false

    for (int div = 3; div <= sqrt(n); div += 2) { // it's enough to check numbers up to the square root

        if (n % div == 0) return false; // n is divisble by a number less than its square root
    }
    return true; // reached the square root and no numbers could divide n
}

const short prime_count(const short& a, const short& b){

    short n = 0;
    while(is_prime(n*n + a*n + b)) n++;
    return n;
}

int main(){

    short max_prime_count = 35;

    for(short a = -1001; a<1000; a+=2){

        for(short b = 3; b<998; b+=2){

            if(is_prime(b)){

                short new_pc = prime_count(a, b);
                if(new_pc > max_prime_count){

                    max_prime_count = new_pc;
                    cout << "New max for (" << a << ", " << b << "): " << new_pc << ". Product is " << a*b << endl;
                }
            }
        }
    }


    return 0;
}