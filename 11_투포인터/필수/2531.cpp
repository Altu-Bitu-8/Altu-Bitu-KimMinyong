#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxType(int N, int d, int k, int c, vector<int>& sushi, vector<int>& ans) {
	int cnt_types = 0;

	for (int i = 0; i < k; i++) {
		if (ans[sushi[i]]++ == 0) {
			cnt_types++;
		}
	}

	int max_types = cnt_types + (ans[c] == 0 ? 1 : 0);

	for (int i = k; i < N + k; i++) {
		if (--ans[sushi[(i - k) % N]] == 0) {
			cnt_types--;
		}
		if (ans[sushi[i % N]]++ == 0) {
			cnt_types++;
		}

		int temp = cnt_types + (ans[c] == 0 ? 1 : 0);

		if (temp > max_types) {
			max_types = temp;
		}
	}

	return max_types;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, d, k, c;

	// 입력
	cin >> N >> d >> k >> c;
	vector<int> sushi(N);
	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}

	vector<int> ans(d + 1, 0);

	// 연산 & 출력
	cout << getMaxType(N, d, k, c, sushi, ans);
	return 0;
}