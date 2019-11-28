// https://www.acmicpc.net/problem/1260
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

void dfs(int start, vector<vector<int>>* graph, vector<bool>* check) {
	(*check)[start] = true;
	cout << start << ' ';

	for (int i = 0; i < (*graph)[start].size(); ++i) {
		if (!(*check)[(*graph)[start][i]]) {
			dfs((*graph)[start][i], graph, check);
		}
	}
}

void bfs(int start, vector<vector<int>>* graph, vector<bool>* check) {
	queue<int> next;
	next.push(start);
	(*check)[start] = true;
	int tmp;
	while (!next.empty()) {
		tmp = next.front();
		next.pop();
		cout << tmp << ' ';

		for (int i = 0; i < (*graph)[tmp].size(); ++i) {
			if (!(*check)[(*graph)[tmp][i]]) {
				(*check)[(*graph)[tmp][i]] = true;
				next.push((*graph)[tmp][i]);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int node, line, start;	//n, m, v
	int u, v;
	cin >> node >> line >> start;
	vector<vector<int>> graph(node + 1);
	while (line--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 0; i < graph.size(); ++i) {
		sort(graph[i].begin(), graph[i].end());
	}
	vector<bool> check(node + 1, false);
	dfs(start, &graph, &check);
	cout << '\n';
	vector<bool> check2(node + 1, false);
	bfs(start, &graph, &check2);
	return 0;
}