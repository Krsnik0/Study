// https://www.acmicpc.net/problem/1525
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

constexpr int exp(int i) {
	int result = 1;
	while (i--) result *= 10;
	return result;
}

constexpr int facto(int n) {
	int result = 1;
	while (n) result *= n--;
	return result;
}

constexpr int exp9[9] = {
	exp(8),exp(7),exp(6),exp(5),exp(4),exp(3),exp(2),exp(1),exp(0)
};

constexpr int fact9[] = {
	facto(1), facto(2), facto(3), facto(4), facto(5), facto(6), facto(7), facto(8), facto(9)
};

int factToNum(int n) {
	int i = 0, result = 0, tmp;
	while (i < 9) {
		tmp = n % 10;
		n /= 10;
		result += tmp * fact9[i++];
	}
	return result;
}

int changeDigit(int n, int from, int to) {
	// 012345678
	int f = (n / exp9[from]) % 10;
	int t = (n / exp9[to]) % 10;
	return n + exp9[from] * (t - f) + exp9[to] * (f - t);
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
	deque<int> q;
	vector<int> isVisit(3628800, -1);
	isVisit[factToNum(input)] = 0;
	q.push_back(input);
	string str;
	int idx, x, y, dx, dy, next, now, cnt, nextt;
	while (!q.empty()) {
		now = q.front();
		cnt = isVisit[factToNum(now)];
		if (now == 123456789) {
			cout << cnt << '\n';
			return 0;
		}
		str = to_string(now);
		idx = str.find('9');
		x = idx / 3;
		y = idx % 3;
		dx = x + mov[0].first;
		dy = y + mov[0].second;
		if (0 <= dx && dx <= 2 && 0 <= dy && dy <= 2) {
			next = changeDigit(now, x * 3 + y, dx * 3 + dy);
			nextt = factToNum(next);
			if (isVisit[nextt] == -1) {
				q.push_back(next);
				isVisit[nextt] = cnt + 1;
			}
		}
		dx = x + mov[1].first;
		dy = y + mov[1].second;
		if (0 <= dx && dx <= 2 && 0 <= dy && dy <= 2) {
			next = changeDigit(now, x * 3 + y, dx * 3 + dy);
			nextt = factToNum(next);
			if (isVisit[nextt] == -1) {
				q.push_back(next);
				isVisit[nextt] = cnt + 1;
			}
		}
		dx = x + mov[2].first;
		dy = y + mov[2].second;
		if (0 <= dx && dx <= 2 && 0 <= dy && dy <= 2) {
			next = changeDigit(now, x * 3 + y, dx * 3 + dy);
			nextt = factToNum(next);
			if (isVisit[nextt] == -1) {
				q.push_back(next);
				isVisit[nextt] = cnt + 1;
			}
		}
		dx = x + mov[3].first;
		dy = y + mov[3].second;
		if (0 <= dx && dx <= 2 && 0 <= dy && dy <= 2) {
			next = changeDigit(now, x * 3 + y, dx * 3 + dy);
			nextt = factToNum(next);
			if (isVisit[nextt] == -1) {
				q.push_back(next);
				isVisit[nextt] = cnt + 1;
			}
		}
		q.pop_front();
	}
	cout << "-1\n";
	return 0;
}