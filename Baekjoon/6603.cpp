// https://www.acmicpc.net/problem/6603
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

void printLotto(int lottoIdx, int ansIdx, const vector<int>& lotto, vector<int>* ans) {
	//
	if (ansIdx == 6) {
		for (int i = 0; i < 6; ++i) {
			cout << (*ans)[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = lottoIdx; i < lotto.size(); ++i) {
		(*ans)[ansIdx] = lotto[i];
		printLotto(i + 1, ansIdx + 1, lotto, ans);
	}

}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	vector<int> lotto;
	vector<int> ans(6, 0);
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		else {
			lotto.resize(n);
		}
		for (int i = 0; i < n; ++i) {
			cin >> lotto[i];
		}
		printLotto(0, 0, lotto, &ans);
		cout << '\n';
	}
	
	return 0;
}