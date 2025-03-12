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
	gcd = location[0];
	if (n > 1) {   // 코드 중복되지 않도록 수정
		for (int i = 1; i < n; i++) {
			cin >> a;
			location[i] = abs(s - a);
			gcd = getGcd(gcd, location[i]);
		}
	}

	cout << gcd << '\n';

	return 0;
}