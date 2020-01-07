// https://www.acmicpc.net/problem/11729
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

void hanoi(vector<pair<int, int>>& v, int num, int from, int by, int to) {
	//num개 원판이 from에서 by 거쳐서 to로 이동
	if (num == 1) {
		v.push_back({ from, to });
		return;
	}
	else {
		hanoi(v, num - 1, from, to, by);
		v.push_back({ from, to });
		hanoi(v, num - 1, by, from, to);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	hanoi(v, n, 1, 2, 3);
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
}