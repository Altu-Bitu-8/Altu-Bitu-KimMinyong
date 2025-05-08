#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_answer = INT_MIN, min_answer = INT_MAX;

int operation(int a, int b, int i) {
	switch (i) {
	case 0:
		return (a + b);
	case 1:
		return (a - b);
	case 2:
		return (a * b);
	case 3:
		return (a / b);
	}
}

void backtracking(int idx, int n, int result, vector<int>& a, vector<int>& check) {
	if (idx == n) {
		max_answer = max(max_answer, result);
		min_answer = min(min_answer, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (check[i] == 0) {
			continue;
		}

		// 사용
		int new_result = operation(result, a[idx], i);
		check[i]--;

		// 연산
		backtracking(idx + 1, n, new_result, a, check);

		// 반납
		check[i]++;
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> check(4);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> check[i];
	}

	int result = a[0];
	backtracking(1, n, result, a, check);

	cout << max_answer << '\n';
	cout << min_answer << '\n';

	return 0;
}