// https://www.acmicpc.net/problem/14500
// Written by JSH, Krsnik

#define max(a, b) a > b ? a : b;
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int isVisit[501][501] = { false };
int map[501][501];

int dfs(int nn, int mm, int depth) {
	int sum = map[nn][mm];
	if (depth == 3)
		return sum;
	isVisit[nn][mm] = true;
	// nn- mm
	if (0 <= nn - 1 && nn - 1 <= n - 1 && 0 <= mm && mm <= m - 1) {
		if (!isVisit[nn - 1][mm]) {
			sum = max(sum, map[nn][mm] + dfs(nn - 1, mm, depth + 1));
			isVisit[nn - 1][mm] = false;
		}
	}
	// nn+ mm
	if (0 <= nn + 1 && nn + 1 <= n - 1 && 0 <= mm && mm <= m - 1) {
		if (!isVisit[nn + 1][mm]) {
			sum = max(sum, map[nn][mm] + dfs(nn + 1, mm, depth + 1));
			isVisit[nn + 1][mm] = false;
		}			
	}
	// nn mm-
	if (0 <= nn && nn <= n - 1 && 0 <= mm - 1 && mm - 1 <= m - 1) {
		if (!isVisit[nn][mm - 1]) {
			sum = max(sum, map[nn][mm] + dfs(nn, mm - 1, depth + 1));
			isVisit[nn][mm - 1] = false;
		}
	}
	// nn mm+
	if (0 <= nn && nn <= n - 1 && 0 <= mm + 1 && mm + 1 <= m - 1) {
		if (!isVisit[nn][mm + 1]) {
			sum = max(sum, map[nn][mm] + dfs(nn, mm + 1, depth + 1));
			isVisit[nn][mm + 1] = false;
		}
	}
	isVisit[nn][mm] = false;
	return sum;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
	//ㅗ를 제외한 나머지 모양은 dfs로 서치
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans = max(ans, dfs(i, j, 0));
		}
	}
	//ㅗ
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			ans = max(ans, map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 1][j + 1]);
		}
	}
	//ㅜ
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			ans = max(ans, map[i][j] + map[i - 1][j - 1] + map[i - 1][j + 1] + map[i - 1][j]);
		}
	}
	//ㅓ
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			ans = max(ans, map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i + 1][j + 1]);
		}
	}
	//ㅏ
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m; ++j) {
			ans = max(ans, map[i][j] + map[i][j - 1] + map[i - 1][j - 1] + map[i + 1][j - 1]);
		}
	}

	cout << ans << '\n';

	return 0;
}