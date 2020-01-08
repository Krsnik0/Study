// https://www.acmicpc.net/problem/2448
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

void fractal(vector<vector<char>>& ans, int i, int j, int n) {
	//i, j: 삼각형 상단 좌표, n: 삼각형 높이
	if (n == 3) {
		ans[i][j] = '*';
		ans[i + 1][j] = '*';
		ans[i + 1][j + 2] = '*';
		ans[i + 2][j] = '*';
		ans[i + 2][j + 1] = '*';
		ans[i + 2][j + 2] = '*';
		ans[i + 2][j + 3] = '*';
		ans[i + 2][j + 4] = '*';
		return;
	}
	else {
		fractal(ans, i, j, n / 2);
		fractal(ans, i + n / 2, j, n / 2);
		fractal(ans, i + n / 2, j + n, n / 2);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<char>> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i].resize(2 * i + 1, ' ');
	}
	fractal(ans, 0, 0, n);
	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j > i; --j)
			cout << ' ';
		for (int j = 0; j < 2 * i + 1; ++j) {
			cout << ans[i][j];
		}
		for (int j = n - 1; j > i; --j)
			cout << ' ';
		cout << '\n';
	}

	return 0;
}