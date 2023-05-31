
#include <iostream>
#include <cmath>
using namespace std;

const bool form_triplet(const int& a, const int& b){

	return sqrt(pow(a, 2) + pow(b, 2)) == int(sqrt(pow(a, 2) + pow(b, 2)));
}

int main(){

	for(short a = 1000; a > 10; a--){

		for(short b = a; b > 10; b--){

			short c = sqrt(pow(a, 2) + pow(b, 2));
			if(form_triplet(a, b) && a+b+c==1000){

				cout << a*b*c << endl;
				exit(0);
			}
		}
	}

	return 0;
}