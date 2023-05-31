
#include <iostream>
using namespace std;

const bool is_divisible_by_all(const int& number) {

	for (int div = 20; div >= 11; div--) {
		if (number % div != 0) {
			return false;
		}
	}

	return true;
}

int main() {

	int answer = 20;

	while (!is_divisible_by_all(answer)) {

		answer += 20;
	}

	cout << answer << endl;



	return 0;
}