
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void display(const vector<short>& v, const size_t& limit = 1){

    for(size_t i=0; i<limit; i++) cout << v[i] << "";
}

unsigned short sum(const vector<short>& v){

	return accumulate(v.begin(), v.end(), 0);
}

void double_up(vector<short>& v){

	short c;
	short carry = 0;

	short i = 0;

	while(i<v.size()){

		c = 2*v[i] + carry;

		if(c<10){
			v[i] = c;
			carry = 0;
		} else {
			v[i] = c%10;
			carry = 1;
		}
		i++;
	}
}

int main(int argc, char const *argv[])
{
	vector<short> v(302, 0);
	v[0] = 1;

	for(short i=0; i<1000; i++){
		double_up(v);
	}

	cout << sum(v) << endl;

	return 0;
}