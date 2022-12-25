
#include <iostream>
#include <vector>
using namespace std;

vector<bool> primes_under(const int& limit){

	vector<bool> data(limit, true);
	data[0] = data[1] = false;

	for(size_t i=4; i<limit; i+=2) data[i] = false;

	size_t i = 2;
	while(i < limit){

		while(i < limit && !data[++i]); // stop at next prime
		for(size_t j=2*i; j<limit; j+=i) data[j] = false;
	}

	return data;
}

int main(int argc, char const *argv[])
{
	vector<bool> data = primes_under(120004);

	int primes = 0;
	int num = 2;
	while(primes < 10001) primes += data[num++];
	cout << --num << endl;

	return 0;
}
