
#include <iostream>
#include <cmath>
using namespace std;

long triangle(short n){
	return (n*(n+1))/2;
}

int factors(const int& number){

	int answer = 2;
	for(int div = 2; div<sqrt(number); ++div){ answer += 2*(number%div==0);}
	answer += (sqrt(number) == int(sqrt(number)));
	return answer;
}

int main(int argc, char const *argv[])
{
	short facts = 0;

	short i = 7;
	while(facts <= 500) facts = factors(triangle(++i));

	cout << triangle(i) << endl;
	
	return 0;
}