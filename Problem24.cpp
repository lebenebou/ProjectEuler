
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



int main(){

    string word = "0123456789";

    unsigned int tations = 1;

    while(tations++ < 1000000) next_permutation(word.begin(), word.end());

    cout << "Permutation " << tations-1 << ": " << word << endl;
    
    return 0;
}