
#include <iostream>
#include <cmath>
using namespace std;

const int triangular(const int& n){

	return n*(n+1)/2; // O(1)
}

const short number_of_factors(const int& n){

	short answer = 2;

	for(int div = 2; div <= sqrt(n); div++){

		if(n%div==0){
			answer+=2; // two factors for each division
			if((n/div)==div) answer--; // unless it's a square
		}
	}
	return answer;
}

int main(int argc, char const *argv[])
{

	int i = 7;
	while(number_of_factors(triangular(i)) <= 500){
		i++;
	}

	cout << triangular(i) << endl;

	return 0;
}