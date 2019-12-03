// https://www.acmicpc.net/problem/2667
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

void dfs(int i, int j, const vector<string>& input, vector<vector<bool>>* isVisit, int* aptNum) {
	++(*aptNum);
	int n = input.size();
	(*isVisit)[i][j] = true;
	if (0 <= j - 1) {
		if (!(*isVisit)[i][j - 1] && input[i][j - 1] == '1') {
			dfs(i, j - 1, input, isVisit, aptNum);
		}
	}
	if (i + 1 < n) {
		if (!(*isVisit)[i + 1][j] && input[i + 1][j] == '1') {
			dfs(i + 1, j, input, isVisit, aptNum);
		}
	}
	if (0 <= i - 1) {
		if (!(*isVisit)[i - 1][j] && input[i - 1][j] == '1') {
			dfs(i - 1, j, input, isVisit, aptNum);
		}
	}
	if (j + 1 < n) {
		if (!(*isVisit)[i][j + 1] && input[i][j + 1] == '1') {
			dfs(i, j + 1, input, isVisit, aptNum);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> input(n);
	vector<vector<bool>> isVisit(n);
	vector<int> apart;
	for (auto& item : isVisit) {
		item.resize(n, false);
	}
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	int cnt;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!isVisit[i][j] && input[i][j] == '1') {
				cnt = 0;
				dfs(i, j, input, &isVisit, &cnt);
				apart.push_back(cnt);
			}
		}
	}
	sort(apart.begin(), apart.end());
	cout << apart.size() << '\n';
	for (int i = 0; i < apart.size(); ++i) {
		cout << apart[i] << '\n';
	}
	return 0;
}