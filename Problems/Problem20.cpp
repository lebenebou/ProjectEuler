
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<short> list;

void display(const vector<short>& v, const size_t& limit = 1){

    for(size_t i=0; i<limit; i++) cout << v[i] << " ";
}

void multiply(vector<short>& v, const short& number){

    if(number==0) return;

	short c;
	short carry = 0;

	short i = 0;

	while(i<v.size()){

		c = number*v[i] + carry;

		if(c<10){
			v[i] = c;
			carry = 0;
		} else {
			v[i] = c%10;
			carry = c/10;
		}
		i++;
	}
}

unsigned short sum(const vector<short>& v){

	return accumulate(v.begin(), v.end(), 0);
}


int main(){

    list v(201, 0);
    v[0] = 1;

    for(short i=2; i<100; i++){

        multiply(v, i);
    }

    cout << sum(v) << endl;
    
    

    return 0;
}