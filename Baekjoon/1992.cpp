// https://www.acmicpc.net/problem/1992
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

void quadtree(const vector<vector<char>>& input, vector<char>& ans, int i, int j, int n) {
	if (n == 1) {
		input[i][j] == '1' ? ans.push_back('1') : ans.push_back('0');
		return;
	}
	bool isZero = true, isOne = true;
	for (int ii = i; ii < i + n; ++ii) {
		for (int jj = j; jj < j + n; ++jj) {
			if (input[ii][jj] == '0')
				isOne = false;
			if (input[ii][jj] == '1')
				isZero = false;
		}
	}
	if (isZero) {
		ans.push_back('0');
		return;
	}
	else if (isOne) {
		ans.push_back('1');
		return;
	}
	else {
		ans.push_back('(');
		quadtree(input, ans, i, j, n / 2);
		quadtree(input, ans, i, j + n / 2, n / 2);
		quadtree(input, ans, i + n / 2, j, n / 2);
		quadtree(input, ans, i + n / 2, j + n / 2, n / 2);
		ans.push_back(')');
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<char>> input(n);
	for (auto& item : input)
		item.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> input[i][j];
		}
	}
	vector<char> ans;
	quadtree(input, ans, 0, 0, n);
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i];
	cout << '\n';


	return 0;
}