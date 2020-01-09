// https://www.acmicpc.net/problem/2261
// Written by JSH, Krsnik
// ref https://www.acmicpc.net/blog/view/25

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

struct Point {
	int x, y;
	Point() {

	}
	Point(int x, int y) : x(x), y(y) {

	}
	bool operator < (const Point& z) const {
		if (y == z.y)
			return x < z.x;
		else
			return y < z.y;
	}
};

int dist(Point p1, Point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool cmp(Point p1, Point p2) {
	return p1.x < p2.x;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<Point> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i].x >> input[i].y;
	}
	sort(input.begin(), input.end(), cmp);

	int ans = dist(input[0], input[1]);
	set<Point> candidate = { input[0], input[1] };
	int start = 0;
	for (int i = 2; i < n; ++i) {
		while (start < i) {
			auto comparer = input[start];
			int dx = input[i].x - comparer.x;
			if (dx*dx > ans) {
				candidate.erase(comparer);
				++start;
			}
			else {
				break;
			}
		}
		int d = (int)sqrt((double)ans) + 1, tmp;
		auto itLow = candidate.lower_bound({ -10001, input[i].y - d });
		auto itUp = candidate.upper_bound({ 10001, input[i].y + d });
		for (auto it = itLow; it != itUp; ++it) {
			tmp = dist(input[i], *it);
			ans = ans < tmp ? ans : tmp;
		}
		candidate.insert(input[i]);
	}

	cout << ans << '\n';

	return 0;
}