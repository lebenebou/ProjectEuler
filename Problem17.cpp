
#include <iostream>
#include <string>
using namespace std;

const short letters(const string& word){

	return word.length();
}


int main(){

	// FORTY with an O !!!
	unsigned short answer = 0;
	
	answer += 190*letters("onetwothreefourfivesixseveneightnine");
	answer += 10*letters("teneleventwelvethirteenfourteenfifteensixteenseventeeneighteennineteen");
	answer += 100*letters("twentythirtyfortyfiftysixtyseventyeightyninety");

	answer += 900*letters("hundred");
	answer += 891*letters("and");

	answer += letters("onethousand");

	cout << answer << endl;

	return 0;
}