
#include <iostream>
using namespace std;

const unsigned long long int factorial(const short& n, const short& start = 1){

	unsigned long long int answer = start;
	for(short i = start+1; i<=n; i++){
		answer *= i;
	}
	return answer;
}

const unsigned long long int ways_for(const short& n){

	return factorial(2*n, n + 1)/factorial(n);
}

int main(int argc, char const *argv[])
{
	
	cout << ways_for(19) << endl;

	return 0;
}