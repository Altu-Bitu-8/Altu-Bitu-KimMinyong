#include <iostream>
#include <vector>

using namespace std;

int main() {
	int  n, k;
	cin >> n >> k;

	vector<char> wheel(n, '?');
	int previous = 0;
	bool isExist = true;

	for (int i = 0; i < k; i++) {
		int s;
		char letter;
		cin >> s >> letter;

		int idx = (previous + s) % n;

		if (wheel[idx] != '?' && wheel[idx] != letter) {
			isExist = false;
			break;
		}

		for (int i = 0; i < n; i++) {
			if (wheel[i] == letter && i != idx) {
				isExist = false;
				break;
			}
		}

		wheel[idx] = letter;
		previous = (previous + s);
	}

	if (!isExist) {
		cout << '!';
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << wheel[(previous - i) % n];
		}
	}

	return 0;
}