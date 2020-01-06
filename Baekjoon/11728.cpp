// https://www.acmicpc.net/problem/11728
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> arrA(n);
	vector<int> arrB(m);
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		cin >> arrA[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> arrB[i];
	}
	int idxA = 0, idxB = 0;
	while ((arrA.size() != idxA) || (arrB.size() != idxB)) {
		if ((arrA.size() != idxA) && (arrB.size() != idxB)) {
			arrA[idxA] > arrB[idxB] ? ans.push_back(arrB[idxB++]) : ans.push_back(arrA[idxA++]);
		}
		else if (arrA.size() == idxA) {
			ans.push_back(arrB[idxB++]);
		}
		else if (arrB.size() == idxB) {
			ans.push_back(arrA[idxA++]);
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << '\n';
	
	return 0;
}