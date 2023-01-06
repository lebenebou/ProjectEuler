
#include <iostream>
#include <map>
#include <time.h>
using namespace std;

uint32_t steps(const uint32_t& number, map<uint32_t, short>& data){

	if(data[number] > 0) return data[number];

	if(number%2==0) data[number] = 1 + steps(number/2, data);
	else data[number] = 2 + steps((3*number + 1)/2, data);

	return data[number];
}

int main(){

	clock_t time = clock();

	map<uint32_t, short> data;
	data[1] = 1;

	short max_value = 10;
	uint32_t arg_max = 13;

	for(int i=14; i<1000000; ++i){

		steps(i, data);
		if(data[i] > max_value){

			arg_max = i;
			max_value = data[i];
		}
	}
	time = clock() - time;
	double time_taken = (double) time/CLOCKS_PER_SEC;
	cout << arg_max << " in " << time_taken << "s" << endl;
	
	return 0;
}