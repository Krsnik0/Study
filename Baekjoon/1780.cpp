// https://www.acmicpc.net/problem/1780
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
enum InputType { P_MINUS, P_ZERO, P_PLUS };

//x, y: 시작좌표, input[x][y], size: 변 길이
void  paper(const vector<vector<int>>& input, vector<int>& ans, int x, int y, int size) {
	if (size == 1) {
		++ans[input[x][y] + 1];
		return;
	}
	bool minus = true, zero = true, plus = true;
	for (int i = x; i < x + size; ++i) {
		for (int j = y; j < y + size; ++j) {
			if (input[i][j] == -1) {
				zero = false;
				plus = false;
			}
			if (input[i][j] == 0) {
				minus = false;
				plus = false;
			}
			if (input[i][j] == 1) {
				zero = false;
				minus = false;
			}
		}
	}
	if (minus) {
		++ans[P_MINUS];
		return;
	}
	else if (plus) {
		++ans[P_PLUS];
		return;
	}
	else if (zero) {
		++ans[P_ZERO];
		return;
	}
	else {
		paper(input, ans, x, y, size / 3);
		paper(input, ans, x + size / 3, y, size / 3);
		paper(input, ans, x + (size / 3) * 2, y, size / 3);
		paper(input, ans, x, y + size / 3, size / 3);
		paper(input, ans, x + size / 3, y + size / 3, size / 3);
		paper(input, ans, x + (size / 3) * 2, y + size / 3, size / 3);
		paper(input, ans, x, y + (size / 3) * 2, size / 3);
		paper(input, ans, x + size / 3, y + (size / 3) * 2, size / 3);
		paper(input, ans, x + (size / 3) * 2, y + (size / 3) * 2, size / 3);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	vector<int> ans(3, 0);
	cin >> n;
	vector<vector<int>> input(n);
	for (auto& item : input)
		item.resize(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++ j) {
			cin >> input[i][j];
		}
	}

	paper(input, ans, 0, 0, n);
	for (int i = 0; i < 3; ++i) {
		cout << ans[i] << '\n';
	}
	
	return 0;
}