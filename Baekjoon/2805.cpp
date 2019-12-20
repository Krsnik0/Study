// https://www.acmicpc.net/problem/2805
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
	
	int n, left = 0, right = 0, mid, max = 0;
	long long m;
	cin >> n >> m;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
		right = right > input[i] ? right : input[i];
	}
	long long sum;
	while (left <= right) {
		sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < n; ++i) {
			sum += input[i] > mid ? input[i] - mid : 0;
		}
		if (sum >= m) {
			left = mid + 1;
			max = max > mid ? max : mid;
		}
		else {
			right = mid - 1;
		}
	}
	cout << max << '\n';
	return 0;
}