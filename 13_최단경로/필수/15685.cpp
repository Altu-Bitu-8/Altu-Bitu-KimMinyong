#include <iostream>
#include <vector>

using namespace std;

int grid[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dragonCurve(int x, int y, int d, int g) {
    vector<int> dirs;
    dirs.push_back(d);

    for (int gen = 1; gen <= g; gen++) {  // 세대별 방향
        int size = dirs.size();
        for (int i = size - 1; i >= 0; i--) {
            dirs.push_back((dirs[i] + 1) % 4);
        }
    }

    grid[y][x] = 1;
    for (int dir : dirs) {
        x += dx[dir];
        y += dy[dir];
        if (0 <= x && x <= 100 && 0 <= y && y <= 100)
            grid[y][x] = 1;
    }
}

int countSquares() {
    int cnt = 0;  // 정사각형 개수
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (grid[i][j] && grid[i][j + 1] && grid[i + 1][j] && grid[i + 1][j + 1])
                cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // 입력
    cin >> N;
    while (N--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        // 연산
        dragonCurve(x, y, d, g);
    }

    // 출력
    cout << countSquares() << "\n";
    return 0;
}
