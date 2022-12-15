
#include <iostream>
#include <vector>
#include <set>
#include "./Files/BigInt.hpp"
using namespace std;

int main(){

    vector<BigInt> nums(99*99);

    unsigned int index = 0;
    for(short a=2; a<=100; a++){
        for(short b=2; b<=100; b++){

            nums[index++] = pow(BigInt(a), b);
        }
    }

    set<BigInt> unique_nums(nums.begin(), nums.end());

    cout << unique_nums.size() << endl;
    

    return 0;
}