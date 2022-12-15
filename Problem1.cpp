
#include <iostream>
using namespace std;

const int sum_ints_below(const int limit) {

	return limit * (limit + 1) / 2;
}

const int sum_multiples(const int mult, const int limit) {

	return sum_ints_below(limit / mult) * mult;
}

int main() {

	cout << sum_multiples(3, 1000) + sum_multiples(5, 1000) - sum_multiples(15, 1000);

	return 0;
}