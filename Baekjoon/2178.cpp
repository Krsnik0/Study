// https://www.acmicpc.net/problem/2178
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<string> input(n);
	vector<vector<int>> minRoute(n);
	deque<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	for (auto& item : minRoute) {
		item.resize(m, 0);
	}
	minRoute[0][0] = 1;
	q.push_back({ 0, 0 });
	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		if (0 < x) {
			if (input[x - 1][y] == '1' && minRoute[x - 1][y] == 0) {
				minRoute[x - 1][y] = minRoute[x][y] + 1;
				if (x - 1 == n - 1 && y == m - 1)break;
				q.push_back({ x - 1, y });
			}
		}
		if (0 < y) {
			if (input[x][y - 1] == '1' && minRoute[x][y - 1] == 0) {
				minRoute[x][y - 1] = minRoute[x][y] + 1;
				if (x == n - 1 && y - 1 == m - 1)break;
				q.push_back({ x, y - 1 });
			}
		}
		if (x < n - 1) {
			if (input[x + 1][y] == '1' && minRoute[x + 1][y] == 0) {
				minRoute[x + 1][y] = minRoute[x][y] + 1;
				if (x + 1 == n - 1 && y == m - 1)break;
				q.push_back({ x + 1, y });
			}
		}
		if (y < m - 1) {
			if (input[x][y + 1] == '1' && minRoute[x][y + 1] == 0) {
				minRoute[x][y + 1] = minRoute[x][y] + 1;
				if (x == n - 1 && y + 1 == m - 1)break;
				q.push_back({ x, y + 1 });
			}
		}
		q.pop_front();
	}
	cout << minRoute[n - 1][m - 1];
	return 0;
}