// https://www.acmicpc.net/problem/1967
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

	int n, node1, node2, len;
	cin >> n;
	vector<vector<pair<int, int>>> tree(n + 1);
	for (int i = 1; i < n; ++i) {
		cin >> node1 >> node2 >> len;
		tree[node1].push_back({ node2, len });
		tree[node2].push_back({ node1, len });
	}
	vector<int> isVisit(n + 1, false), value(n + 1, 0);
	int weight = 0, node_now, node_max, next;
	deque<int> q;
	q.push_back(1);
	while (!q.empty()) {
		node_now = q.front();
		isVisit[node_now] = true;
		q.pop_front();
		for (int i = 0; i < tree[node_now].size(); ++i) {
			next = tree[node_now][i].first;
			if (!isVisit[next]) {
				q.push_back(next);
				value[next] = value[node_now] + tree[node_now][i].second;
				if (value[next] > weight) {
					weight = value[next];
					node_max = next;
				}
			}
		}
	}

	q.push_back(node_max);
	isVisit.assign(n + 1, false);
	value.assign(n + 1, 0);
	weight = 0;

	while (!q.empty()) {
		node_now = q.front();
		isVisit[node_now] = true;
		q.pop_front();
		for (int i = 0; i < tree[node_now].size(); ++i) {
			next = tree[node_now][i].first;
			if (!isVisit[next]) {
				q.push_back(next);
				value[next] = value[node_now] + tree[node_now][i].second;
				if (value[next] > weight) {
					weight = value[next];
					node_max = next;
				}
			}
		}
	}
	cout << weight << '\n';
	
	return 0;
}