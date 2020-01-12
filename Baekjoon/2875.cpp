// https://www.acmicpc.net/problem/2875
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

	int n, m, k;
	cin >> n >> m >> k;
	int team, intern;
	if (n > 2 * m) {
		team = m;
		intern = n + m - team * 3;
	}
	else {
		team = n / 2;
		intern = n + m - team * 3;
	}

	while (intern < k) {
		--team;
		intern += 3;
	}

	cout << team << '\n';

	return 0;
}