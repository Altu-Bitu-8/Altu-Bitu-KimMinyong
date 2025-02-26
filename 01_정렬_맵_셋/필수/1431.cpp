#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int shiftToNum(string& str) {
	int sum = 0;
	for (char c : str) {
		if (isdigit(c))
			sum += (c - '0');
	}
	return sum;
}

bool comp(string& a, string& b) {
	if (a.length() != b.length()) {
		return (a.length() < b.length());
	}
	if (shiftToNum(a) != shiftToNum(b)) {
		return (shiftToNum(a) < shiftToNum(b));
	}
	return (a < b);
}

int main() {
	int n;
	cin >> n;
	vector<string> serial(n);

	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}

	sort(serial.begin(), serial.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << serial[i] << '\n';
	}
	return 0;
}