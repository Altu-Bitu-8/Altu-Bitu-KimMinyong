#include <iostream>
#include <deque>

using namespace std;

int belt_moving(int n, int k, deque<pair<bool, int>>& belt) {
	int count = 0;

	while (true) {
		// 4. 종료 확인
		int durable_zero = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (belt[i].second == 0) {
				durable_zero++;
			}
		}
		if (durable_zero >= k) {
			break;
		}

		// 1. 벨트 회전
		belt.push_front(belt.back());
		belt.pop_back();
		belt[n - 1].first = false;

		// 2. 로봇 이동
		for (int i = n - 2; i >= 0; i--) {
			if (belt[i].first && belt[i + 1].first == false && belt[i + 1].second >= 1) {
				belt[i + 1].first = true;
				belt[i].first = false;
				belt[i + 1].second--;
			}
		}

		belt[n - 1].first = false;

		// 3. 로봇 올리기
		if (belt[0].second > 0) {
			belt[0].first = true;
			belt[0].second--;
		}

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

	cout << belt_moving(n, k, belt);

	return 0;
}