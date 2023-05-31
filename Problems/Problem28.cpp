
#include <iostream>
#include <cmath>
using namespace std;

// too lazy for mathmatical analysis
int main(){

    short gap = 2;
    short cycle = 1;

    unsigned long int answer = 1;
    for(long int i=3; i<=pow(1001, 2); i+=gap){

        answer += i;

        if(cycle%4==0){
            gap+=2;
            cycle = 1;
        } else {
            cycle++;
        }
        
    }
    cout << answer << endl;

    return 0;
}