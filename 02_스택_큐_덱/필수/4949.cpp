#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {
	char sentence[100];
	while (cin.getline(sentence, 100, '.')) {  // getline으로 EOF 처리
		if (strlen(sentence) == 0) break;

		stack<char> s;
		string status = "yes";

		for (int i = 0; i < strlen(sentence); i++) {
			if (sentence[i] == '(' || sentence[i] == '[') {
				s.push(sentence[i]);
			}

			if (sentence[i] == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					status = "no";
					break;
				}
			}

			if (sentence[i] == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					status = "no";
					break;
				}
			}
		}

		if (!s.empty()) {
			status = "no";
		}

		cout << status << "\n";
		cin.ignore();
	}

	return 0;
}