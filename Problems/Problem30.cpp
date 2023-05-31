
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long int pos_int;

const int ctoi(const char& c){

	return c - '0';
}

const bool cbw(const pos_int& number){

    pos_int sum = 0;
    for(char c : to_string(number)){
        
        sum += pow(ctoi(c), 5);
        if(sum > number) return false;
    }
    return sum==number;
}

int main(){

    pos_int answer = 0;
    for(pos_int i=pow(2, 10); i<pow(2, 20); i++){

        if(cbw(i)) answer += i;
    }
    
    cout << answer << endl;


    return 0;
}