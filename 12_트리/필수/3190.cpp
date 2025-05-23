#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef pair<int, char> pi;

void changeDir(int direction, int& r, int& c, pi head) {
	switch (direction) {
	case 0:  // 오른쪽
		r = head.first;
		c = head.second + 1;
		break;
	case 1:  // 아래
		r = head.first + 1;
		c = head.second;
		break;
	case 2:  // 왼쪽
		r = head.first;
		c = head.second - 1;
		break;
	case 3:
		r = head.first - 1;
		c = head.second;
		break;
	}
}

int moveSnake(int n, vector<vector<bool>>& board, vector<pi>& snake_direction) {
	deque<pi> snake_location;
	snake_location.push_back({ 1, 1 });

	vector<vector<bool>> snake(n + 1, vector<bool>(n + 1, false));  // 뱀 몸통
	snake[1][1] = true;

	int sec = 0;
	int direction = 0;
	int cnt = 0;

	while (true) {
		sec++;
		pi head = snake_location.front();  // 머리 위치
		int nextRow = 0, nextCol = 0;

		changeDir(direction, nextRow, nextCol, head);

		// 2. 벽이나 자기자신의 몸과 부딪히면 종료
		if (nextRow < 1 || nextRow > n || nextCol < 1 || nextCol > n || snake[nextRow][nextCol]) {
			return sec;
		}

		// 1. 몸길이를 늘려 머리를 다음칸에 위치
		snake_location.push_front({ nextRow, nextCol });
		snake[nextRow][nextCol] = true;

		// 3. 이동한 칸에 사과가 있다면 사과 없어짐
		if (board[nextRow][nextCol]) {
			board[nextRow][nextCol] = false;
		}

		// 4. 이동한 칸에 사과가 없다면 꼬리가 위치한 칸을 비워줌
		else {
			pi tail = snake_location.back();
			snake[tail.first][tail.second] = false;
			snake_location.pop_back();
		}

		// 5. 방향 전환
		if (cnt < snake_direction.size() && snake_direction[cnt].first == sec) {
			char c = snake_direction[cnt].second;
			if (c == 'L') {
				direction = (direction + 3) % 4;
			}
			else {
				direction = (direction + 1) % 4;
			}
			cnt++;
		}
	}
}

int main() {
	int n, k, l;
	cin >> n >> k;

	vector<vector<bool>> board(n + 1, vector<bool>(n + 1, false));

	int row, col;
	while (k--) {
		cin >> row >> col;
		board[row][col] = true;
	}

	cin >> l;
	vector<pi> snake_direction(l);

	for (int i = 0; i < l; i++) {
		cin >> snake_direction[i].first >> snake_direction[i].second;
	}

	cout << moveSnake(n, board, snake_direction);

	return 0;
}