
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned short num;

const num sum_divisors(const num& number){

    num answer = 1;

    num div = 2;
    while(div <= sqrt(number)){

        if(number%div==0){

            answer += div;
            if(number/div != div) answer += number/div;
        }

        div++;
    }

    return answer;
}

const bool are_amicable(const num& n1, const num& n2){

    return sum_divisors(n1)==n2 && sum_divisors(n2)==n1;
}

const bool makes_amicable_pair(const num& number){

    num s = sum_divisors(number);
    return sum_divisors(s)==number && s!=number;
}

int main(){

    unsigned int answer = 0;
    for(short i = 1; i<10000; i++){

        if(makes_amicable_pair(i)) answer += i;
    }
    cout << answer << endl;

    return 0;
}