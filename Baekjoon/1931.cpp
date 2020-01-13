// https://www.acmicpc.net/problem/1931
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

bool cmp(vector<int> v1, vector<int> v2) {
	return v1[1] == v2[1] ? v1[0] < v2[0] : v1[1] < v2[1];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (auto& item : v)
		item.resize(2, 0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i][0] >> v[i][1];
	}
	sort(v.begin(), v.end(), cmp);
	int cnt = 1, now = 0, endTime = v[0][1];
	for (int i = 1; i < n; ++i) {
		if (v[i][0] >= endTime) {
			now = i;
			endTime = v[i][1];
			++cnt;
		}
	}

	cout << cnt << '\n';

	return 0;
}