// https://www.acmicpc.net/problem/2003
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

	int n, m, sum, cnt = 0;
	cin >> n >> m;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	for (int i = 0; i < n; ++i) {
		sum = 0;
		for (int j = i; j < n; ++j) {
			sum += input[j];
			if (sum == m) ++cnt;
		}
	}

	cout << cnt << '\n';
	return 0;
}