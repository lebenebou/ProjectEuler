
#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(const size_t& limit){

    vector<bool> prime(limit+1, true);
    for(size_t i=4; i<=limit; i+=2) prime[i] = false;

    for(size_t i=3; i<=limit; i+=2){

        if(!prime[i]) continue; // i is not prime, skip to next

        for(size_t j=i*i; j<=limit; j+=i) prime[j] = false;
    }
    return prime;
}

vector<size_t> primes_below(const size_t& limit){

    vector<size_t> answer(limit/log(limit-1));

    vector<bool> s = sieve(limit);
    size_t primes_found = 0;

    for(size_t i=2; i<=limit; i++){

        if(!s[i]) continue; // i is not prime, skip to next

        if(primes_found < answer.size()) answer[primes_found] = i;
        else answer.push_back(i);

        primes_found++;
    }
    return answer;
}

int main(){

	cout << "Sum of primes below 2 million: ";
    const auto p = primes_below(2 * pow(10, 6));
    cout << std::accumulate(p.begin(), p.end(), size_t(0)) << endl;

    return 0;
}