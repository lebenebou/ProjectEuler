
#include <iostream>
#include <map>
using namespace std;

size_t steps(const size_t& number, map<size_t, size_t>& data){

	if(data[number] > 0) return data[number];

	if(number%2==0) data[number] = 1 + steps(number/2, data);
	else data[number] = 2 + steps((3*number + 1)/2, data);

	return data[number];
}

int main(){

	map<size_t, size_t> data;
	data[1] = 1;
	int counter = 0;

	size_t max_value = 10;
	size_t arg_max = 13;

	for(size_t arg=13; arg<=999999; ++arg){

		size_t value = steps(arg, data);

		if(value > max_value){

			max_value = value;
			arg_max = arg;
		}
	}

	cout << arg_max << endl;

	return 0;
}