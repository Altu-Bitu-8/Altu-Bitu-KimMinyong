#include <iostream>
#include <set>

using namespace std;

int s;

void setOperations(string input) {
	int x;

	if (input == "add") {
		cin >> x;
		x--;
		if (!(s & (1 << x))) {
			s += 1 << x;
		}
	}

	else if (input == "remove") {
		cin >> x;
		x--;
		if (s & (1 << x)) {
			s -= 1 << x;
		}
	}

	else if (input == "check") {
		cin >> x;
		cout << ((s & (1 << --x)) != 0) << "\n";
	}

	else if (input == "toggle") {
		cin >> x;
		x--;
		if (s & (1 << x)) {
			s -= 1 << x;
		}
		else {
			s += 1 << x;
		}
	}

	else if (input == "all") {
		for (int i = 0; i < 20; i++) {
			if (!(s & (1 << i))) {
				s += 1 << i;
			}
		}
	}

	else if (input == "empty") {
		s = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;
	string input;

	while (m--) {
		cin >> input;
		setOperations(input);
	}

	return 0;
}