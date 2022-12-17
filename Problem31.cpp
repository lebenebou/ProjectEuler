
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long ways_for(const int& number, unordered_map<int, long>& data, const vector<short>& coins){

    if(data[number] > 0) return data[number];

    short i=0;
    while(number < coins[i++]);
    
    cout << i << endl;

    return data[number];
}

int main(){

    unordered_map<int, long> data;
    data[1] = 1;

    vector<short> coins = {200, 100, 50, 20, 10, 5, 2, 1};

    cout << ways_for(2, data, coins) << endl;

    return 0;
}