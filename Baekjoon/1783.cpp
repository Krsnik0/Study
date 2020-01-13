// https://www.acmicpc.net/problem/1783
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


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int cnt;
	if (n == 1) {
		cnt = 1;
	}
	else if (n == 2) {
		cnt = m > 7 ? 4 : (m + 1) / 2;
	}
	else {
		cnt = m > 6 ? m - 2 : (m >= 4 ? 4 : m);
	}

	cout << cnt << '\n';

	return 0;
}