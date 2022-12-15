
#include <iostream>
using namespace std;

const int square_sum(const int& n){

	return (n*(n+1)*(2*n + 1))/6;
}

const int sum_squares(const int& n){

	return (n*(n+1)/2)*(n*(n+1)/2);
}

int main(){

	// O(1)
	cout << sum_squares(100) - square_sum(100) << endl;

	return 0;
}