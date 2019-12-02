// https://www.acmicpc.net/problem/9466
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;


void dfs(int now, const vector<int>& student, vector<bool>* isVisit, vector<bool>* fin, int* cnt) {
	int next = student[now];
	(*isVisit)[now] = true;
	if (!(*isVisit)[next]) {
		dfs(next, student, isVisit, fin, cnt);
	}
	else if (!(*fin)[next]) {
		for (int i = next; i != now; i = student[i]) {
			++(*cnt);
		}
		++(*cnt);
	}
	(*fin)[now] = true;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n, cnt;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> student(n + 1, 0);
		for (int i = 1; i < n + 1; ++i) {
			cin >> student[i];
		}
		cnt = 0;
		vector<bool> isVisit(n + 1, false);
		vector<bool> fin(n + 1, false);
		for (int i = 1; i < n + 1; ++i) {
			if (!fin[i]) {
				dfs(i, student, &isVisit, &fin, &cnt);
			}
		}
		cout << n - cnt << '\n';
	}

	return 0;
}