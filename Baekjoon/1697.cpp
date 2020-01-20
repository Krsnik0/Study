// https://www.acmicpc.net/problem/1697
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

	int n, k;
	cin >> n >> k;
	deque<pair<int, int>> q;
	vector<bool> isVisit(100001, false);
	q.push_back({n, 0});
	while (1) {
		pair<int, int> now = q.front();
		if (now.first == k) {
			cout << now.second << '\n';
			return 0;
		}
		if (now.first - 1 >= 0 && !isVisit[now.first - 1]) {
			q.push_back({ now.first - 1, now.second + 1 });
			isVisit[now.first - 1] = true;
		}
		if (now.first + 1 <= 100001 && !isVisit[now.first + 1]) {
			q.push_back({ now.first + 1, now.second + 1 });
			isVisit[now.first + 1] = true;
		}
		if (now.first * 2 <= 100001 && !isVisit[now.first * 2]) {
			q.push_back({ now.first * 2, now.second + 1 });
			isVisit[now.first * 2] = true;
		}
		q.pop_front();
	}

	return 0;
}