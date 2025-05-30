#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e7;

void floydWarshall(int n, vector<vector<int>>& d) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (d[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int countStudents(int n, const vector<vector<int>>& d) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (d[i][j] < INF || d[j][i] < INF)
                cnt++;
        }
        if (cnt == n - 1)
            answer++;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    // 입력
    cin >> n >> m;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
    }

    // 연산
    floydWarshall(n, d);

    // 출력
    cout << countStudents(n, d) << "\n";
    return 0;
}