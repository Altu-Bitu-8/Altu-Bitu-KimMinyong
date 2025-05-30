#include <iostream>
#include <vector>

using namespace std;

void preToPost(const vector<int>& preorder, int start, int end) {
	if (start > end) return;

	int root = preorder[start];
	int split = start + 1;
	// 자식 노드가 root보다 커지는 경계 찾기
	while (split <= end && preorder[split] < root) {
		++split;
	}
	// 왼쪽 서브트리
	preToPost(preorder, start + 1, split - 1);
	// 오른쪽 서브트리
	preToPost(preorder, split, end);
	cout << root << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> preorder;
	int x;

	// 입력
	while (cin >> x) {
		preorder.push_back(x);
	}

	// 연산 & 출력
	preToPost(preorder, 0, preorder.size() - 1);
	return 0;
}