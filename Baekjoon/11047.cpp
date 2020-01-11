// https://www.acmicpc.net/problem/11047
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}

	int cnt = 0, idx = n - 1;
	while (k != 0) {
		if (k >= input[idx]) {
			k -= input[idx];
			++cnt;
		}
		else {
			--idx;
		}
	}
	cout << cnt << '\n';	

	return 0;
}