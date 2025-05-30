#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e5;

vector<int> dijkstra(int start, int N, const vector<vector<int>>& thiefRupee) {
    int V = N * N;
    vector<int> dist(V, INF);  // 각 정점까지의 최단 경로 저장
    priority_queue<ci, vector<ci>, greater<ci>> pq;

    // 시작 정점 초기화
    int sr = start / N, sc = start % N;
    dist[start] = thiefRupee[sr][sc];
    pq.push({ dist[start], start });

    // 이동 방향
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) {
            continue;
        }

        int r = node / N;
        int c = node % N;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                continue;
            }

            int v = nr * N + nc;
            int nd = weight + thiefRupee[nr][nc];
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({ nd, v });
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, tc = 1;
    while (true) {
        // 입력
        cin >> N;
        if (N == 0) {
            break;
        }

        vector<vector<int>> thiefRupee(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> thiefRupee[i][j];
            }
        }

        // 연산
        vector<int> dist = dijkstra(0, N, thiefRupee);

        // 출력
        cout << "Problem " << tc++ << ": " << dist[N * N - 1] << "\n";
    }

    return 0;
}