#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int binarySearch(int left, int right, int n, int dist, vector<int>& x) {
	int height = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (x[0] - mid <= 0 && x[x.size() - 1] + mid >= n && mid * 2 >= dist) {
			height = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return height;
}

int main() {
	int n, m;

	// 입력
	cin >> n >> m;
	vector<int> x(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i];
	}

	// 가로등 사이의 최대 간격 찾기
	int max = 0;
	for (int i = 1; i < m; i++) {
		if (x[i] - x[i - 1] > max) {
			max = x[i] - x[i - 1];
		}
	}

	// 연산 & 출력
	cout << binarySearch(1, n, n, max, x);

	return 0;
}