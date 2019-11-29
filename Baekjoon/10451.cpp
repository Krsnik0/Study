// https://www.acmicpc.net/problem/10451
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

void dfs(int start, vector<int>* graph, vector<bool>* isVisit) {
	(*isVisit)[start] = true;
	if (!(*isVisit)[(*graph)[start]]) {
		dfs((*graph)[start], graph, isVisit);
	}
}

int cycleChk(vector<int>* graph, vector<bool>* isVisit) {
	int cnt = 0;
	for (int i = 1; i < (*graph).size(); ++i) {
		if (!(*isVisit)[i]) {
			dfs(i, graph, isVisit);
			++cnt;
		}
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n, node, cnt;
	
	cin >> t;
	while (t--) {
		cin >> n;
		cnt = n;
		vector<int> graph(n + 1);
		while (cnt--) {
			cin >> node;
			graph[n - cnt] = node;
		}
		vector<bool> isVisit(n + 1, false);
		cout << cycleChk(&graph, &isVisit) << '\n';
	}

	return 0;
}