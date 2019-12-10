// https://www.acmicpc.net/problem/1966
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

	int t, n, target, weight, max, maxIdx = -1;
	pair<int, int> now;
	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		deque<pair<int, int>> q;
		vector<int> pq;
		cin >> n >> target;
		for (int j = 0; j < n; ++j) {
			cin >> weight;
			q.push_back({ j, weight });
		}
		while (!q.empty()) {
			max = -1;
			for (int k = 0; k < q.size(); ++k) {
				now = q.front();
				if (max < now.second) {
					max = now.second;
					maxIdx = k;
				}
				q.pop_front();
				q.push_back(now);
			}
			for (int k = 0; k < maxIdx; ++k) {
				now = q.front();
				q.pop_front();
				q.push_back(now);
			}
			now = q.front();
			q.pop_front();
			pq.push_back(now.first);
		}
		for (int j = 0; j < pq.size(); ++j) {
			if (pq[j] == target) {
				cout << j + 1 << '\n';
				break;
			}
		}
	}

	return 0;
}