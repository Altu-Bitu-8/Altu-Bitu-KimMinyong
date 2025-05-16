#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getLongest(int left, int right, int n, int k, vector<int>& a) {
	int length = 0;
	int max_length = 0;
	vector<int> sequence(100001, 0);

	while (left < n && right < n) {
		// 특정 정수가 k번 초과로 등장하기 전까지 right 이동하며 수열 길이 추가
		if (++sequence[a[right]] <= k) {
			length++;
			right++;
		}
		else {
			sequence[a[right]]--;
			if (length > max_length) {
				max_length = length;
			}
			// 특정 정수가 k번 초과로 등장하면 left 이동
			sequence[a[left]]--;
			left++;
			length--;
		}
	}

	if (length > max_length) {
		max_length = length;
	}

	return max_length;
}

int main() {
	int n, k;

	// 입력
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 출력 & 연산
	cout << getLongest(0, 0, n, k, a);

	return 0;
}