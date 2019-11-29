// https://www.acmicpc.net/problem/11724
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
	//cout << start << ' ';

	for (int i = 0; i < (*graph)[start].size(); ++i) {
		if (!(*check)[(*graph)[start][i]]) {
			dfs((*graph)[start][i], graph, check);
		}
	}
}

int countCC(vector<vector<int>>* graph, vector<bool>* check) {
	int cnt = 0;
	for (int i = 1; i < (*graph).size(); ++i) {
		if (!(*check)[i]) {
			++cnt;
			dfs(i, graph, check);
		}
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int node, line;	//n, m
	int u, v;
	cin >> node >> line;
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
	cout << countCC(&graph, &check) << '\n';
	

	return 0;
}