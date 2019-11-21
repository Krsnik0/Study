// https://www.acmicpc.net/problem/11650
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int, int>> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i].first >> input[i].second;
	}
	sort(input.begin(), input.end());

	for (int i = 0; i < n; ++i) {
		cout << input[i].first << " " << input[i].second << '\n';
	}

	return 0;
}