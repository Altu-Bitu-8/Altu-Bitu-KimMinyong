#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxType(int N, int k, vector<int>& sushi, vector<int>& ans) {
	int cnt_types = 0;
	vector<int> tmp = ans;

	for (int i = 0; i < k; i++) {
		if (find(ans.begin(), ans.end(), sushi[i]) != ans.end()) {
			continue;
		}
		ans.push_back(sushi[i]);
	}

	cnt_types = ans.size();

	int max_types = cnt_types;

	for (int i = k; i < N; i++) {
		if (find(ans.begin(), ans.end(), sushi[i]) != ans.end()) {
			continue;
		}
		remove(ans.begin(), ans.end(), sushi[i - k]);
		ans.push_back(sushi[i]);

		if (ans.size() > max_types) {
			max_types = ans.size();
		}
	}

	return max_types;
}

int main() {
	int N, d, k, c;
	cin >> N >> d >> k >> c;

	vector<int> sushi(N);
	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}

	vector<int> answer;
	answer.push_back(c);

	cout << getMaxType(N, k, sushi, answer);
	return 0;
}