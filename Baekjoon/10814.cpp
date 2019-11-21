// https://www.acmicpc.net/problem/10814
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, string> p1, pair<int, string> p2) {
	return p1.first < p2.first;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int, string>> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i].first >> input[i].second;
	}
	stable_sort(input.begin(), input.end(), cmp);

	for (int i = 0; i < n; ++i) {
		cout << input[i].first << " " << input[i].second << '\n';
	}

	return 0;
}