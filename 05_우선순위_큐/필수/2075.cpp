#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	priority_queue<int, vector<int>, greater<int>> table;  // 최소 힙

	// 입력
	cin >> n;

	// 연산
	for (int i = 0; i < n * n; i++) {
		cin >> x;
		table.push(x);
		if (table.size() > n && i > 0) {
			table.pop();  // 가장 작은 수 pop
		}
	}

	// 출력
	cout << table.top() << "\n";
	return 0;
}