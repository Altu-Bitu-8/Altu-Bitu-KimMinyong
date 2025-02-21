#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int weight, i_before, t;
	cin >> weight >> i_before >> t;
	int day, i, a;
	cin >> day >> i >> a;

	int expected_weight = weight;
	int expected_weight_bmr = weight;
	string state, state_bmr;
	int bmr = i_before;  // 일일 기초 대사량
	int energy_consumption;

	int divide_and_floor(int a, int b) {
		return (a < 0 && a % b != 0) ? (a / b - 1) : (a / b);
	}

	while (day--) {
		// 기초대사량 고려x
		expected_weight += (i - (i_before + a));
		if (expected_weight <= 0) {
			state = "DANGER DIET";
		}

		// 기초대사량 고려o
		energy_consumption = bmr + a;
		expected_weight_bmr += (i - energy_consumption);
		if (expected_weight_bmr <= 0 || bmr <= 0) {
			state_bmr = "DANGER DIET";
		}
		if (abs(i - energy_consumption) > t) {
			bmr += divide_and_floor(i - energy_consumption, 2.0);
		}
	}

	// 출력 기초대사량 고려x
	if (state == "DANGER DIET") {
		cout << state << '\n';
	}
	else {
		cout << expected_weight << ' ' << i_before << '\n';
	}

	// 출력 기초대사량 고려o
	if (state_bmr == "DANGER DIET") {
		cout << state_bmr << '\n';
	}
	else {
		if (i_before - (bmr + 0) > 0) state_bmr = "YOYO";
		else state_bmr = "NO";
		cout << expected_weight_bmr << ' ' << bmr << ' ' << state_bmr;
	}

	return 0;
}