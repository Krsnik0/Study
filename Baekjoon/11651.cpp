// https://www.acmicpc.net/problem/11651
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
	return p1.second == p2.second ? p1.first < p2.first: p1.second < p2.second;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int, int>> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i].first >> input[i].second;
	}
	sort(input.begin(), input.end(), cmp);

	for (int i = 0; i < n; ++i) {
		cout << input[i].first << " " << input[i].second << '\n';
	}

	return 0;
}