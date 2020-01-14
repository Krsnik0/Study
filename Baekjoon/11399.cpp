// https://www.acmicpc.net/problem/11399
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
	return v1[1] < v2[1];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (auto& item : v)
		item.resize(2,0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i][1];
		v[i][0] = i + 1;
	}
	sort(v.begin(), v.end(), cmp);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			sum += v[j][1];
		}
	}
	cout << sum << '\n';

	return 0;
}