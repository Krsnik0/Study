// https://www.acmicpc.net/problem/1167
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, node, nnode = 0, b;
	
	cin >> n;
	vector<vector<pair<int, int>>> tree(n + 1);
	vector<int> isVisit(n + 1, false);
	for (int i = 0; i < n; ++i) {
		cin >> node;
		while (true) {
			cin >> nnode;
			if (nnode == -1) break;
			cin >> b;
			
			tree[node].push_back({ nnode, b });
		}
	}
	// find furthest node from 1, and find node from 'that node'
	deque<int> q;
	vector<int> cost(n + 1, 0);
	q.push_back(1);
	int now, next, weight, ansNode, max_weight = 0;
	while (!q.empty()) {
		now = q.front();
		q.pop_front();
		isVisit[now] = true;
		for (int i = 0; i < tree[now].size(); ++i) {
			next = tree[now][i].first;
			if (!isVisit[next]) {
				weight = tree[now][i].second;
				cost[next] = cost[now] + weight;
				if (cost[next] > max_weight) {
					max_weight = cost[next];
					ansNode = next;
				}
				q.push_back(next);
			}
		}
	}

	q.push_back(ansNode);
	isVisit.assign(n + 1, false);
	cost.assign(n + 1, 0);
	max_weight = 0;

	while (!q.empty()) {
		now = q.front();
		q.pop_front();
		isVisit[now] = true;
		for (int i = 0; i < tree[now].size(); ++i) {
			next = tree[now][i].first;
			if (!isVisit[next]) {
				weight = tree[now][i].second;
				cost[next] = cost[now] + weight;
				if (cost[next] > max_weight) {
					max_weight = cost[next];
					ansNode = next;
				}
				q.push_back(next);
			}
		}
	}
	cout << max_weight << '\n';

	return 0;
}