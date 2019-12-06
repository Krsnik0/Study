// https://www.acmicpc.net/problem/2146
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;
int dist(int a, int b) {
	return a > b ? a - b : b - a;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> input(n);
	vector<vector<bool>> isVisit(n);
	deque<pair<int, int>> q;
	for (auto& item : isVisit) {
		item.resize(n, false);
	}
	for (auto& item : input) {
		item.resize(n);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> input[i][j];
		}
	}
	
	int x, y, island = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (input[i][j] == 1 && !isVisit[i][j]) {
				q.push_back({ i, j });
				isVisit[i][j] = true;
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					input[x][y] = island;
					if (0 < x) {
						if (input[x - 1][y] == 1 && !isVisit[x - 1][y]) {
							isVisit[x - 1][y] = true;
							q.push_back({ x - 1, y });
						}
					}
					if (0 < y) {
						if (input[x][y - 1] == 1 && !isVisit[x][y - 1]) {
							isVisit[x][y - 1] = true;
							q.push_back({ x, y - 1 });
						}
					}
					if (x < n - 1) {
						if (input[x + 1][y] == 1 && !isVisit[x + 1][y]) {
							isVisit[x + 1][y] = true;
							q.push_back({ x + 1, y });
						}
					}
					if (y < n - 1) {
						if (input[x][y + 1] == 1 && !isVisit[x][y + 1]) {
							isVisit[x][y + 1] = true;
							q.push_back({ x, y + 1 });
						}
					}
					q.pop_front();
				}
				++island;
			}
		}
	}
	int distance = 2 * n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (input[i][j] != 0) {
				for (int ii = 0; ii < n; ++ii) {
					for (int jj = 0; jj < n; ++jj) {
						if (input[ii][jj] != 0) {
							if (input[i][j] != input[ii][jj]) {
								distance = min(distance, (dist(i, ii) + dist(j, jj) - 1));
							}
						}
					}
				}
			}
		}
	}

	cout << distance << '\n';
	return 0;
}