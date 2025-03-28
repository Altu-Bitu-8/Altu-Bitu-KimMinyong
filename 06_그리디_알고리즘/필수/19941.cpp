#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> people(n + 1, 0);
	vector<int> hamburger(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		char letter;
		cin >> letter;
		if (letter == 'H') {
			hamburger[i] = 1;
		}
		else {
			people[i] = 1;
		}
	}

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = -k; j <= k; j++) {
			if (i + j > 0 && i + j <= n) {  // 인덱스의 범위 검사
				// 해당 인덱스에 사람이 있고 그로부터 k만큼 떨어진 거리에 햄버거가 있다면
				if (people[i] == 1 && hamburger[i + j] == 1) {
					answer++;
					hamburger[i + j] = 0;
					break;
				}
			}
		}
	}

	cout << answer;
	return 0;
}