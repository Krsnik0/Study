// https://www.acmicpc.net/problem/10819
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

// use next_permutation to solve easily

void dfs(const vector<int>& input, vector<bool>& isVisit, int len, int n, int& ans, vector<int>& tmp) {
	if (len >= n) {
		int sum = 0;
		for (int i = 0; i < n - 1; ++i) {
			sum += tmp[i] > tmp[i + 1] ? tmp[i] - tmp[i + 1] : tmp[i + 1] - tmp[i];
		}
		ans = ans > sum ? ans : sum;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!isVisit[i]) {
			tmp.push_back(input[i]);
			isVisit[i] = true;
			dfs(input, isVisit, len + 1, n, ans, tmp);
			isVisit[i] = false;
			tmp.pop_back();
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, ans = 0;
	cin >> n;
	vector<int> input(n);
	vector<bool> isVisit(n, false);
	vector<vector<int>> v;
	vector<int> tmp;
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}

	dfs(input, isVisit, 0, n, ans, tmp);

	cout << ans << '\n';

	return 0;
}