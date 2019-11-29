// https://www.acmicpc.net/problem/1707
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

void dfs(int start, vector<vector<int>>* graph, vector<bool>* check, vector<int>* chkbin) {
	(*check)[start] = true;
	//cout << start << ' ';

	for (int i = 0; i < (*graph)[start].size(); ++i) {
		if (!(*check)[(*graph)[start][i]]) {
			if ((*chkbin)[(*graph)[start][i]] == 0) {
				(*chkbin)[(*graph)[start][i]] = 3 - (*chkbin)[start];
				dfs((*graph)[start][i], graph, check, chkbin);
			}
		}
	}
}

bool bipartite(vector<vector<int>>* graph, vector<bool>* check, vector<int>* chkbin) {
	for (int i = 1; i < (*graph).size(); ++i) {
		if ((*chkbin)[i] == 0) {
			(*chkbin)[i] = 1;
			dfs(i, graph, check, chkbin);
		}
	}
	for (int i = 1; i < (*graph).size(); ++i) {
		for (int j = 0; j < (*graph)[i].size(); ++j) {
			if ((*chkbin)[i] == (*chkbin)[(*graph)[i][j]]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, node, line;	//n, m
	int u, v;
	cin >> k;
	while (k--) {
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
		vector<int> chkbin(node + 1, 0);
		
		if (bipartite(&graph, &check, &chkbin)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}