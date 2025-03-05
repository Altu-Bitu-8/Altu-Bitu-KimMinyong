#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	int card;

	cin >> n;

	queue<int> deck;

	for (int i = 0; i < n; i++) {
		deck.push(i + 1);
	}

	while (deck.size() > 1) {
		deck.pop();
		if (deck.empty()) {
			break;
		}
		else {
			card = deck.front();
			deck.pop();
			deck.push(card);
		}
	}

	cout << deck.front();

	return 0;
}