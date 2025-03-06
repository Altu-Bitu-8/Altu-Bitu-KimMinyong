#include <iostream>
#include <vector>

using namespace std;

int getGcd(int a, int b) {  // a < b
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	int n, s, a;
	cin >> n >> s;

	vector<int> location(n);
	int gcd;

	cin >> a;
	location[0] = abs(s - a);
	if (n == 1) {
		gcd = location[0];
	}
	else {
		cin >> a;
		location[1] = abs(s - a);
		gcd = getGcd(location[0], location[1]);

		for (int i = 2; i < n; i++) {
			cin >> a;
			location[i] = abs(s - a);
			gcd = getGcd(gcd, location[i]);
		}
	}

	cout << gcd << '\n';

	return 0;
}