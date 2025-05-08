#include <iostream>
#include <deque>

using namespace std;

void rotateBelt(int n, deque<pair<bool, int>>& belt) {
	belt.push_front(belt.back());
	belt.pop_back();
	belt[n - 1].first = false;
}

void moveRobot(int n, deque<pair<bool, int>>& belt) {
	for (int i = n - 2; i >= 0; i--) {
		if (belt[i].first && belt[i + 1].first == false && belt[i + 1].second >= 1) {
			belt[i + 1].first = true;
			belt[i].first = false;
			belt[i + 1].second--;
		}
	}

	belt[n - 1].first = false;
}

void putRobot(deque<pair<bool, int>>& belt) {
	if (belt[0].second > 0) {
		belt[0].first = true;
		belt[0].second--;
	}
}

bool isExit(int n, int k, deque<pair<bool, int>>& belt) {
	int durable_zero = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (belt[i].second == 0) {
			durable_zero++;
		}
	}
	if (durable_zero >= k) {
		return true;
	}
	return false;
}

int beltMoving(int n, int k, deque<pair<bool, int>>& belt) {
	int count = 0;

	while (true) {
		// 4. 종료 확인
		if (isExit(n, k, belt))
			break;

		// 1. 벨트 회전
		rotateBelt(n, belt);

		// 2. 로봇 이동
		moveRobot(n, belt);

		// 3. 로봇 올리기
		putRobot(belt);

		count++;
	}

	return count;
}

int main() {
	int n, k;
	cin >> n >> k;

	deque<pair<bool, int>> belt(2 * n, { false, 0 });

	for (int i = 0; i < 2 * n; i++) {
		cin >> belt[i].second;
	}

	cout << beltMoving(n, k, belt);

	return 0;
}