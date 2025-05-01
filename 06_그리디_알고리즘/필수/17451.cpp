#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	// 입력
	cin >> n;

	vector<long long> velocity(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> velocity[i];
	}

	// 연산
	reverse(velocity.begin(), velocity.end());

	long long earth = velocity[0];

	for (int i = 1; i < n; i++) {
		// 지금 속도가 행성 i에서 필요한 속도의 정수 배라면 변화x
		if (earth % velocity[i] == 0) {
			continue;
		}

		earth = velocity[i] * (long long)ceil((long double)earth / velocity[i]);
	}

	// 출력
	cout << earth;
	return 0;
}