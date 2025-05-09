#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int target, vector<int>& arr) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (target == arr[mid]) {
			return 1;
		}
		else if (target < arr[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, target;
	// 입력
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cin >> m;
	while (m--) {
		cin >> target;
		// 연산 & 출력
		cout << binarySearch(n, target, arr) << ' ';
	}

	return 0;
}