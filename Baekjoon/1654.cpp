// https://www.acmicpc.net/problem/1654
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
	
	int k, n;
	cin >> k >> n;
	vector<long long> lan(k);
	for (int i = 0; i < k; ++i) {
		cin >> lan[i];
	}
	long long left = 1, right = UINT32_MAX - 1, middle;
	long long sum = 0, max = 0;
	while (left <= right) {
		sum = 0;
		middle = (left + right) / 2;
		for (int i = 0; i < k; ++i) {
			sum += lan[i] / middle;
		}
		if (sum >= n) {
			left = middle + 1;
			max = max > middle ? max : middle;
		}
		else if (sum < n) {
			right = middle - 1;
		}
	}

	cout << max << '\n';
	return 0;
}