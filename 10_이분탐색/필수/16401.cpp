#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parametricSearch(int left, int right, int m, int n, vector<int>& length) {
	while (left <= right) {
		int cnt = 0;
		int mid = (left + right) / 2;

		vector<int> temp(n);
		temp = length;

		for (int i = 0; i < n; i++) {
			while (temp[i] >= mid) {
				temp[i] = temp[i] - mid;
				cnt++;
			}
		}

		if (cnt >= m) {  // 길이 mid인 과자의 총 개수가 조카의 수보다 많다면
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return left - 1;
}

int main() {
	int m, n;

	// 입력
	cin >> m >> n;
	vector<int> L(n);
	for (int i = 0; i < n; i++) {
		cin >> L[i];
	}

	sort(L.begin(), L.end());

	// 연산 & 출력
	cout << parametricSearch(1, L.back(), m, n, L);

	return 0;
}