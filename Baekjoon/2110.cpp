// https://www.acmicpc.net/problem/2110
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

bool isPossible(const vector<int>& input, int len, int c) {
	int prev = input[0], n = input.size(), cnt = 1;

	for (int i = 1; i < n; ++i) {
		if (input[i] - prev >= len) {
			++cnt;
			prev = input[i];
		}
	}

	if (cnt >= c) return true;
	else return false;	
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;
	vector<int> input(n);
	vector<int> wifi(c);
	wifi[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	sort(input.begin(), input.end());

	int left = 1, right = input[n - 1] - input[0], max = 0;
	int len;
	while (left <= right) {
		len = (left + right) / 2;
		if (isPossible(input, len, c)) {
			max = len > max ? len : max;
			left = len + 1;
		}
		else
			right = len - 1;
	}
	cout << max;
	return 0;
}