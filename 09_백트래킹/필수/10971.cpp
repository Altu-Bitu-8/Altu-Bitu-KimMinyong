#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int answer = INT_MAX;

void backtracking(int idx, int n, int cost, int curr, vector<vector<int>>& w, vector<bool>& is_visited) {
	if (idx == n) {
		if (w[curr][0] == 0) return;  // 0번 도시로 돌아오는 간선 없는 경우

		cost += w[curr][0];
		answer = min(answer, cost);
		return;
	}

	for (int next = 0; next < n; next++) {
		if (is_visited[next]) {
			continue;
		}

		if (w[curr][next] == 0) {
			continue;
		}

		// 사용
		int new_cost = cost + w[curr][next];
		if (new_cost >= answer) continue;
		is_visited[next] = true;

		// 연산
		backtracking(idx + 1, n, new_cost, next, w, is_visited);

		// 반납
		is_visited[next] = false;
	}
}

int main() {
	int n;
	// 입력
	cin >> n;

	vector<vector<int>> w(n, vector<int>(n));
	vector<bool> is_visited(n, false);
	int cost = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	// 연산
	is_visited[0] = true;
	backtracking(1, n, cost, 0, w, is_visited);

	// 출력
	cout << answer;

	return 0;
}