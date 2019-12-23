// https://www.acmicpc.net/problem/10816
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	cin >> m;
	vector<int> card(m);
	for (int i = 0; i < m; ++i) {
		cin >> card[i];
	}

	sort(input.begin(), input.end());
	for (int i = 0; i < m; ++i) {
		cout << upper_bound(input.begin(), input.end(), card[i]) - lower_bound(input.begin(), input.end(), card[i]) << " ";
	}
	cout << '\n';

	return 0;
}