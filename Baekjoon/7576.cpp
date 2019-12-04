// https://www.acmicpc.net/problem/7576
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> input;
	vector<vector<bool>> isVisit;
	queue<pair<int, int>> q;
	input.resize(m);
	isVisit.resize(m);
	for (auto& item : input)
		item.resize(n);
	for (auto& item : isVisit) {
		item.resize(n, false);
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> input[i][j];
			if (input[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}
	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		isVisit[x][y] = true;
		if (0 <= y - 1) {
			if (!isVisit[x][y - 1] && input[x][y - 1] == 0) {
				input[x][y - 1] = input[x][y] + 1;
				q.push({ x, y - 1 });
			}
		}
		if (x + 1 < m) {
			if (!isVisit[x + 1][y] && input[x + 1][y] == 0) {
				input[x + 1][y] = input[x][y] + 1;
				q.push({ x + 1, y });
			}
		}
		if (0 <= x - 1) {
			if (!isVisit[x - 1][y] && input[x - 1][y] == 0) {
				input[x - 1][y] = input[x][y] + 1;
				q.push({ x - 1, y });
			}
		}
		if (y + 1 < n) {
			if (!isVisit[x][y + 1] && input[x][y + 1] == 0) {
				input[x][y + 1] = input[x][y] + 1;
				q.push({ x, y + 1 });
			}
		}
		q.pop();
	}
	int ans = -1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			ans = max(ans, input[i][j]);
		}
	}
	--ans;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (input[i][j] == 0) {
				ans = -1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}