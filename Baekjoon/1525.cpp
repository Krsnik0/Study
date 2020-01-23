//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

int changeDigit(int n, int from, int to) {
	// 012345678
	vector<int> v(9, 0);
	v[8] = n % 10;
	v[7] = (n / 10) % 10;
	v[6] = (n / 100) % 10;
	v[5] = (n / 1000) % 10;
	v[4] = (n / 10000) % 10;
	v[3] = (n / 100000) % 10;
	v[2] = (n / 1000000) % 10;
	v[1] = (n / 10000000) % 10;
	v[0] = n / 100000000;
	int tmp = v[from];
	v[from] = v[to];
	v[to] = tmp;
	return v[8] + 10 * (v[7] + 10 * (v[6] + 10 * (v[5] + 10 * (v[4] + 10 * (v[3] + 10 * (v[2] + 10 * (v[1] + 10 * v[0])))))));
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// (x, y)
	int tmp, input = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> tmp;
			(input *= 10) += tmp != 0 ? tmp : 9;
		}
	}
	vector<pair<int, int>> mov = { {1,0},{-1,0},{0,1},{0,-1} };
	vector<bool> isVisit(1000000000, false);
	isVisit[input] = true;
	deque<pair<int, int>> q;
	q.push_back({ input, 0 });
	string str;
	pair<int, int> now;
	int idx, x, y, dx, dy, next;
	while (!q.empty()) {
		now = q.front();
		if (q.front().first == 123456789) {
			cout << q.front().second << '\n';
			return 0;
		}
		str = to_string(now.first);
		idx = str.find('9');
		x = idx / 3;
		y = idx % 3;
		dx = x + mov[0].first;
		dy = y + mov[0].second;
		if (0 <= dx && dx <= 2 && 0 <= dy && dy <= 2) {
			next = changeDigit(now.first, x * 3 + y, dx * 3 + dy);
			if (!isVisit[next]) {
				q.push_back({ next, now.second + 1 });
				isVisit[next] = true;
			}
		}
		dx = x + mov[1].first;
		dy = y + mov[1].second;
		if (0 <= dx && dx <= 2 && 0 <= dy && dy <= 2) {
			next = changeDigit(now.first, x * 3 + y, dx * 3 + dy);
			if (!isVisit[next]) {
				q.push_back({ next, now.second + 1 });
				isVisit[next] = true;
			}
		}
		dx = x + mov[2].first;
		dy = y + mov[2].second;
		if (0 <= dx && dx <= 2 && 0 <= dy && dy <= 2) {
			next = changeDigit(now.first, x * 3 + y, dx * 3 + dy);
			if (!isVisit[next]) {
				q.push_back({ next, now.second + 1 });
				isVisit[next] = true;
			}
		}
		dx = x + mov[3].first;
		dy = y + mov[3].second;
		if (0 <= dx && dx <= 2 && 0 <= dy && dy <= 2) {
			next = changeDigit(now.first, x * 3 + y, dx * 3 + dy);
			if (!isVisit[next]) {
				q.push_back({ next, now.second + 1 });
				isVisit[next] = true;
			}
		}
		q.pop_front();
	}
	if (!isVisit[123456789])
		cout << "-1\n";
	return 0;
}