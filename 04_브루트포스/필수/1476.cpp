#include <iostream>

using namespace std;

#define MAX 10000

int main() {
	// 입력
	int e, s, m;
	cin >> e >> s >> m;

	// 연산
	int year;
	for (int i = 1; i <= MAX; i++) {
		if (i % 15 == e && i % 28 == s && i % 19 == m) {
			year = i;
			break;
		}
	}

	// 출력
	cout << year;
	return 0;
}