#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

struct cmp {
	bool operator() (tuple<int, int, int>& parent, tuple<int, int, int>& child) {
		if (get<0>(parent) == get<0>(child)) {
			if (get<1>(parent) == get<1>(child)) {
				return get<2>(parent) > get<2>(child);
			}
			else {
				return get<1>(parent) < get<1>(child);
			}
		}
		else {
			return get<0>(parent) < get<0>(child);
		}
	}
};

int main() {
	int n, m, k;
	int d, h;
	int cnt = 0, line;

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;
	vector<tuple<int, int, int>> workers;

	// 입력
	cin >> n >> m >> k;

	// 연산
	for (int i = 0; i < n; i++) {
		cin >> d >> h;
		line = i % m;
		workers.push_back({ d, h, line });  // 사원 정보를 벡터에 추가
	}

	for (int i = 0; i < workers.size(); i++) {
		if (i / m == 0) {
			pq.push(workers[i]);  // 선두들을 우선순위 큐에 추가
		}
	}

	vector<int> next(m, 1);

	while (true) {
		tuple<int, int, int> employee;
		employee = pq.top();
		pq.pop();  // 화장실 이용

		if (employee == workers[k]) {  // pop한 사원이 데카일 경우 break
			break;
		}
		cnt++;

		int employee_line = get<2>(employee);
		int idx = employee_line + next[employee_line] * m;  // 각 line의 다음 사원의 인덱스
		if (idx < n) {
			pq.push(workers[idx]);  // 해당 line의 새로운 선두를 다시 우선순위 큐에 추가
			next[employee_line]++;  // 새로운 선두가 세워진 line에 대해 벡터를 +1로 만들어 표시
		}
	}

	// 출력
	cout << cnt << "\n";
	return 0;
}