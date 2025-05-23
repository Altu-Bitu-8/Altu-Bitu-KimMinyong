#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

pair<int, int> goBack(int d, int i, int j) {
	if (d == 0) {
		i++;
	}
	else if (d == 1) {
		j--;
	}
	else if (d == 2) {
		i--;
	}
	else {
		j++;
	}
	return { i,j };
}

pair<int, int> goFront(int d, int i, int j) {
	if (d == 0) {
		i--;
	}
	else if (d == 1) {
		j++;
	}
	else if (d == 2) {
		i++;
	}
	else {
		j--;
	}
	return { i,j };
}

void clean(vector<vector<int>>& status, int i, int j, int d) {
	// 1. 현재 칸이 아직 청소되지 않은 경우
	if (status[i][j] == 0) {
		status[i][j] = 2;
		cnt++;
	}

	// 3. 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
	if (status[i + 1][j] == 0 || status[i][j + 1] == 0 || status[i - 1][j] == 0 || status[i][j - 1] == 0) {
		// 3-1. 반시계 방향으로 90도 회전
			// 3->2, 2->1, 1->0, 0->3
		d = (d + 3) % 4;
		// 3-2. 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진
		if (status[goFront(d, i, j).first][goFront(d, i, j).second] == 0) {
			i = goFront(d, i, j).first;
			j = goFront(d, i, j).second;
		}
		// 3-3. 1번으로 돌아감
		clean(status, i, j, d);
	}

	// 2. 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
	else {
		// 2-1. 방향 유지한 채로 한 칸 후진 + 1번으로 돌아감
		if (status[goBack(d, i, j).first][goBack(d, i, j).second] != 1) {
			i = goBack(d, i, j).first;
			j = goBack(d, i, j).second;
			clean(status, i, j, d);
		}
		// 2-2. 후진할 수 없는 경우 작동 중지
		else {
			return;
		}
	}
}

int main() {
	int n, m, r, c, d;

	// 입력
	cin >> n >> m;
	cin >> r >> c >> d;

	vector<vector<int>> status(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> status[i][j];
		}
	}

	// 연산
	clean(status, r, c, d);

	// 출력
	cout << cnt;
	return 0;
}