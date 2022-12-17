
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int ways_for(int number, unordered_map<int, int>& data){

    if(data[number] > 0) return data[number];

    return data[number];
}

int main(){

    unordered_map<int, int> data;
    data[1] = 1;

    vector<short> coins(8, -1);
    coins[0] = 1; coins[1] = 2; coins[2] = 5; coins[3] = 10; coins[4] = 20; coins[5] = 50; coins[6] = 100; coins[7] = 200;

    for(auto elt : coins) cout << elt << " ";

    return 0;
}