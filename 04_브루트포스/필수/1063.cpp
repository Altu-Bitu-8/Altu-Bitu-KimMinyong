#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

void moveChess(string move, char& alp, int& num) {
	if (move == "R") {
		if (alp < 'H') {
			alp++;
		}
	}
	else if (move == "L") {
		if (alp > 'A') {
			alp--;
		}
	}
	else if (move == "B") {
		if (num > 1) {
			num--;
		}
	}
	else if (move == "T") {
		if (num < 8) {
			num++;
		}
	}
	else if (move == "RT") {
		if (alp < 'H' && num < 8) {
			alp++;
			num++;
		}
	}
	else if (move == "LT") {
		if (alp > 'A' && num < 8) {
			alp--;
			num++;
		}
	}
	else if (move == "RB") {
		if (alp < 'H' && num > 1) {
			alp++;
			num--;
		}
	}
	else if (move == "LB") {
		if (alp > 'A' && num > 1) {
			alp--;
			num--;
		}
	}
}

int main() {
	int n;
	char king_alp, stone_alp;
	int king_num, stone_num;
	string move;

	// 입력
	scanf("%c%d", &king_alp, &king_num);
	scanf(" %c%d", &stone_alp, &stone_num);
	cin >> n;

	// 연산
	while (n--) {
		cin >> move;
		moveChess(move, king_alp, king_num);
		if (king_alp == stone_alp && king_num == stone_num) {
			moveChess(move, stone_alp, stone_num);
			if (king_alp == stone_alp && king_num == stone_num) {
				if (move == "R") {
					move = "L";
				}
				else if (move == "L") {
					move = "R";
				}
				else if (move == "B") {
					move = "T";
				}
				else if (move == "T") {
					move = "B";
				}
				else if (move == "RT") {
					move = "LB";
				}
				else if (move == "LT") {
					move = "RB";
				}
				else if (move == "RB") {
					move = "LT";
				}
				else if (move == "LB") {
					move = "RT";
				}
				moveChess(move, king_alp, king_num);
			}
		}
	}

	// 출력
	cout << king_alp << king_num << "\n";
	cout << stone_alp << stone_num << "\n";
	return 0;
}