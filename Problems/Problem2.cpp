
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

int fib(const size_t& index, vector<int>& data){

	assert(index < data.size() && "Out of range!");

	if(data[index] > -1) return data[index];

	data[index] = fib(index-1, data) + fib(index-2, data);

	return data[index];
}

int main(){

	vector<int> data(35, -1); // 35 > log1.61 (4 000 000) + 2
	data[0] = 0;
	data[1] = 1;

	fib(34, data); // calculate all

	int answer = 0;
	for(int i=3; i<data.size(); i+=3) answer += data[i];

	cout << answer << endl;

	return 0;
}