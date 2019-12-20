// https://www.acmicpc.net/problem/1182
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

void subsequence(const vector<int>& input, int& cnt, int s, int idx, int sum) {
	sum += input[idx];
	if (idx >= input.size()) return;
	if (sum == s) ++cnt;

	subsequence(input, cnt, s, idx + 1, sum - input[idx]);
	subsequence(input, cnt, s, idx + 1, sum);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, s, cnt = 0, sum;
	cin >> n >> s;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	subsequence(input, cnt, s, 0, 0);

	cout << cnt << '\n';

	return 0;
}