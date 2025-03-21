#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
	int n, cnt = 0;
	char word[11], new_word[11];
	vector<int> letters(26, 0);

	// 입력
	cin >> n;
	cin >> word;

	for (int i = 0; i < strlen(word); i++) {  // 벡터에 각 알파벳의 등장 횟수 기록
		int flag = word[i] - 65;
		letters[flag]++;
	}

	// 연산
	n--;
	while (n--) {
		cin >> new_word;

		bool isSame = true;
		bool isSimilar = true;
		vector<int> new_letters(26, 0);

		for (int i = 0; i < strlen(new_word); i++) {  // 벡터에 각 알파벳의 등장 횟수 기록
			int flag = new_word[i] - 65;
			new_letters[flag]++;
		}

		for (int i = 0; i < letters.size(); i++) {
			if (letters[i] != new_letters[i]) {
				isSame = false;
				break;
			}
		}

		if (isSame) {  // 1. 같은 구성을 가지는 경우
			cnt++;
		}
		else {   // 2. 같은 구성이 아닌 경우
			int flag = 0;
			int length = strlen(word);
			int new_length = strlen(new_word);

			if (abs(length - new_length) <= 1) {
				for (int i = 0; i < letters.size(); i++) {
					if (abs(letters[i] - new_letters[i]) > 1) {
						isSimilar = false;
						break;
					}
					else if (abs(letters[i] - new_letters[i]) == 1) {
						flag++;
					}
				}

				// 1. 문자열 길이가 똑같고 2. 한 문자를 바꾸면 같은 구성일 때
				if (isSimilar && length == new_length && flag == 2) {
					cnt++;
				}
				// 1. 문자열 길이의 차가 1이고 2. 한 문자를 더하거나 빼면 같은 구성일 때
				if (isSimilar && abs(length - new_length) == 1 && flag == 1) {
					cnt++;
				}
			}
		}
	}
	// 출력
	cout << cnt << "\n";
	return 0;
}