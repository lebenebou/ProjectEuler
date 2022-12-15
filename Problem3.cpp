
#include <iostream>
#include <set>
using namespace std;

set<int> prime_facts_of(size_t n) {

    set<int> primes;
    
    while (n % 2 == 0) {
        primes.insert(2);
        n /= 2;
    }

    for (size_t div = 3; n > 1; div += 2) {
        
        while (n % div == 0) {
            primes.insert(div);
            n /= div;
        }
    }
    return primes;
}

int main() {

    cout << *(prime_facts_of(600851475143).rbegin()); // output last element in the set which is garanteed to be the largest

	return 0;
}