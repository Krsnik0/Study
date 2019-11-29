// https://www.acmicpc.net/problem/1476
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int e, s, m;
	cin >> e >> s >> m;
	while (e != s || s != m) {
		if (e >= m && s >= m)
			m += 19;
		else if (s >= e && m >= e)
			e += 15;
		else if (m >= s && e >= s)
			s += 28;
	}
	cout << e << '\n';

	return 0;
}