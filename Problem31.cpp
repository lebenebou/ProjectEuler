
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){

    const vector<size_t> coins = {1, 2, 5, 10, 20, 50, 100, 200};

    vector<size_t> ways_for(201, 0);
    ways_for[0] = 1;

    for(auto coin : coins){

        for(size_t i=coin; i<=200; ++i){

            ways_for[i] += ways_for[i - coin];
        }
    }

    cout << ways_for[200] << endl;

    return 0;
}