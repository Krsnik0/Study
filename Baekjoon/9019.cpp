// https://www.acmicpc.net/problem/9019
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
enum cmd {D, S, L, R};

int dslr(int n, cmd cmd) {
	//n = ((d1 × 10 + d2) × 10 + d3) × 10 + d4
	int d4 = n % 10, d3 = (n / 10) % 10, d2 = (n / 100) % 10, d1 = (n / 1000);
	if (cmd == D) {
		return n * 2 > 9999 ? n * 2 % 10000 : n * 2;
	}
	else if (cmd == S) {
		return n == 0 ? 9999 : n - 1;
	}
	else if (cmd == L) {
		int tmp = d1;
		d1 = d2;
		d2 = d3;
		d3 = d4;
		d4 = tmp;
		return ((d1 * 10 + d2) * 10 + d3) * 10 + d4;
	}
	else if (cmd == R) {
		int tmp = d4;
		d4 = d3;
		d3 = d2;
		d2 = d1;
		d1 = tmp;
		return ((d1 * 10 + d2) * 10 + d3) * 10 + d4;
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		vector<bool> isVisit(10000, false);
		isVisit[a] = true;
		deque<pair<int, string>> q;
		q.push_back({ a, "" });
		while (!q.empty()) {
			pair<int, string> now = q.front();
			if (now.first == b) {
				cout << now.second << '\n';
				break;
			}
			int next = dslr(now.first, D);
			if (!isVisit[next]) {
				q.push_back({ next, now.second + "D" });
				isVisit[next] = true;
			}
			next = dslr(now.first, S);
			if (!isVisit[next]) {
				q.push_back({ next, now.second + "S" });
				isVisit[next] = true;
			}
			next = dslr(now.first, L);
			if (!isVisit[next]) {
				q.push_back({ next, now.second + "L" });
				isVisit[next] = true;
			}
			next = dslr(now.first, R);
			if (!isVisit[next]) {
				q.push_back({ next, now.second + "R" });
				isVisit[next] = true;
			}
			q.pop_front();
		}
	}
	return 0;
}