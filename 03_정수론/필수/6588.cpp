#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000000

using namespace std;

vector<bool> isPrime() {
	vector<bool> is_prime(MAX + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= sqrt(MAX); i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false;
			}
		}
	}

	return is_prime;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> is_prime = isPrime();

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		int a = 0, b = 0;

		for (int i = 0; i < is_prime.size(); i++) {
			if (is_prime[i] && is_prime[n - i]) {  // a + b = n이 되는 두 수가 모두 소수라면
				a = i;
				b = n - i;
				break;
			}
		}

		if (a == 0 && b == 0) {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
		else {
			cout << n << " = " << a << " + " << b << '\n';
		}
	}

	return 0;
}