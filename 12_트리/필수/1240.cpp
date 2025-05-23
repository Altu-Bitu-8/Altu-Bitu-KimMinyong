#include <iostream>
#include <vector>

using namespace std;

int findDistance(int u, int v, vector<vector<pair<int, int>>>& tree, vector<bool>& visited) {
	if (u == v) return 0;
	visited[u] = true;

	for (int i = 0; i < tree[u].size(); i++) {
		int next = tree[u][i].first;
		int weight = tree[u][i].second;

		if (visited[next]) continue;
		if (next == v) {
			return weight;
		}

		int d = findDistance(next, v, tree, visited);
		if (d != -1) {
			return weight + d;
		}
	}
	return -1;
}

int main() {
	int n, m;
	int left, right, dist;
	int node1, node2;

	cin >> n >> m;

	vector<vector<pair<int, int>>> tree(n + 1);
	int nodes = n;

	while (--n) {
		cin >> left >> right >> dist;
		tree[left].push_back({ right, dist });
		tree[right].push_back({ left, dist });
	}

	while (m--) {
		cin >> node1 >> node2;
		vector<bool> visited(nodes + 1);
		cout << findDistance(node1, node2, tree, visited) << '\n';
	}

	return 0;
}