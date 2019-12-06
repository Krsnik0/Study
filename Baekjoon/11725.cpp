// https://www.acmicpc.net/problem/11725
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

	int n, a, b;
	cin >> n;
	vector<vector<int>> graph(n + 1);
	vector<bool> isVisit(n + 1, false);
	vector<int> parent(n + 1);
	deque<int> q;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	isVisit[1] = true;
	for (int i = 0; i < graph[1].size(); ++i) {
		q.push_back(graph[1][i]);
		parent[graph[1][i]] = 1;
		isVisit[graph[1][i]] = true;
	}
	int x;
	while (!q.empty()) {
		x = q.front();
		for (int i = 0; i < graph[x].size(); ++i) {
			if (!isVisit[graph[x][i]]) {
				q.push_back(graph[x][i]);
				parent[graph[x][i]] = x;
				isVisit[graph[x][i]] = true;
			}
		}
		q.pop_front();
	}
	for (int i = 2; i < n + 1; ++i) {
		cout << parent[i] << '\n';
	}

	return 0;
}