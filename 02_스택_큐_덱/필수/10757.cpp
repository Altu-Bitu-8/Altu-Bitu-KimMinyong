#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string a;
	string b;
	cin >> a >> b;

	stack<int> s;

	int length = a.length() > b.length() ? a.length() : b.length();
	int a_num, b_num;
	int sum;
	int carry = 0;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for (int i = 0; i < length; i++) {
		a_num = (a.length() > i) ? a[i] - '0' : 0;  // a.length()는 size_t 타입. int형인 i가 size_t로 변환되어 값 오류나는 경우 피하기
		b_num = (b.length() > i) ? b[i] - '0' : 0;
		sum = a_num + b_num + carry;
		s.push(sum % 10);
		carry = sum / 10;
	}

	if (carry == 1) {
		s.push(carry);
	}

	// 출력
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}