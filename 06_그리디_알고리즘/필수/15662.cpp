#include <iostream>
#include <vector>

using namespace std;

void clockwise(vector<bool>& wheel, int num) {
	bool tmp = wheel[num * 8 + 7];
	for (int i = 7; i > 0; i--) {
		wheel[num * 8 + i] = wheel[num * 8 + (i - 1)];
	}
	wheel[num * 8] = tmp;
}

void counterclockwise(vector<bool>& wheel, int num) {
	bool tmp = wheel[num * 8];
	for (int i = 0; i < 7; i++) {
		wheel[num * 8 + i] = wheel[num * 8 + (i + 1)];
	}
	wheel[num * 8 + 7] = tmp;
}

void rotate(vector<int> wheelDir, vector<bool>& wheel, int num) {
	if (wheelDir[num] == 1) {  // 시계 방향 회전
		clockwise(wheel, num);
	}
	else if (wheelDir[num] == -1) {  // 반시계 방향 회전
		counterclockwise(wheel, num);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, k;

	// 입력1 - 톱니바퀴 정보
	cin >> t;
	int T = t;
	vector<bool> wheel;

	while (T--) {
		string tmp;
		cin >> tmp;
		for (char c : tmp) {
			wheel.push_back(c == '1');
		}
	}

	// 입력2 - 회전 정보
	cin >> k;

	// 연산
	while (k--) {
		int num, direction;
		cin >> num >> direction;
		num--;

		vector<int> wheelDir(t, 0);  // 톱니바퀴마다 회전 방향 저장
		wheelDir[num] = direction;

		// 회전시킨 톱니바퀴 오른쪽으로 가면서 저장
		for (int i = num; i < t - 1; i++) {
			if (wheel[i * 8 + 2] == wheel[(i + 1) * 8 + 6]) {
				break;
			}
			else {
				wheelDir[i + 1] = -wheelDir[i];
			}
		}

		// 회전시킨 톱니바퀴 왼쪽으로 가면서 저장
		for (int i = num; i > 0; i--) {
			if (wheel[(i - 1) * 8 + 2] == wheel[i * 8 + 6]) {
				break;
			}
			else {
				wheelDir[i - 1] = -wheelDir[i];
			}
		}

		for (int i = 0; i < t; i++) {
			rotate(wheelDir, wheel, i);
		}
	}

	int answer = 0;
	for (int i = 0; i < t; i++) {
		if (wheel[8 * i]) {
			answer++;
		}
	}

	// 출력
	cout << answer;
	return 0;
}