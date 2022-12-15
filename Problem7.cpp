
#include <iostream>
#include <cmath>
using namespace std;

const bool is_prime(const int& n){

	if(n%2==0 || n<2) return false;
	if(n==2 or n==3) return true;

	for(int div = 3; div<=sqrt(n); div+=2){

		if(n%div==0) return false;
	}
	return true;
}

const int prime_at_position(const int& n){

	int primes_found = 1;
	int p = 1;

	while(primes_found!=n){

		p+=2;
		if(is_prime(p)) primes_found++;
	}
	return p;
}


int main(int argc, char const *argv[])
{
	
	cout << prime_at_position(10001) << endl;

	return 0;
}