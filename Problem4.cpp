
#include <iostream>
using namespace std;

const bool is_palindrome(const int& number) {

	int copy = number/10;
	int reverse = number%10;

	while (copy > 0) {

		reverse *= 10;
		reverse += copy % 10;
		copy /= 10;
	}

	return reverse == number;
}

int main() {

	int answer = 0;

	for (int n1 = 999; n1 > 100; n1--) {

		for (int n2 = n1; n2 > 100; n2--) {

			if (is_palindrome(n1 * n2) && (n1 * n2) > answer) {
				answer = n1 * n2;
			}
		}
	}

	cout << answer << endl;
	

	return 0;
}