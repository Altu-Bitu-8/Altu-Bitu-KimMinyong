#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	string str;
	cin >> str;

	set<string> s;

	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < str.length(); j++) {
			s.insert(str.substr(i, j));
		}
	}

	int sum = 0;
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		sum++;
	}

	cout << sum;
	return 0;
}