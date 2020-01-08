// https://www.acmicpc.net/problem/2447
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
	if (n == 1) {
		ans[i][j] = '*';
		return;
	}
	else {
		fractal(ans, i, j, n / 3);
		fractal(ans, i, j + n / 3, n / 3);
		fractal(ans, i, j + n * 2 / 3, n / 3);
		fractal(ans, i + n / 3, j, n / 3);
		fractal(ans, i + n / 3, j + n * 2 / 3, n / 3);
		fractal(ans, i + n * 2 / 3, j, n / 3);
		fractal(ans, i + n * 2 / 3, j + n / 3, n / 3);
		fractal(ans, i + n * 2 / 3, j + n * 2 / 3, n / 3);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<char>> ans(n);
	for (auto& item : ans)
		item.resize(n, ' ');
	fractal(ans, 0, 0, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j];
		}
		cout << '\n';
	}

	return 0;
}