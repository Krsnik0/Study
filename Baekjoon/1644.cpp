// https://www.acmicpc.net/problem/1644
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
	
	int n;
	cin >> n;
	vector<bool> isPrime(n + 1, true);
	vector<int> prime;
	for (int i = 2; i < n + 1; ++i) {
		if (isPrime[i]) {
			for (int j = 2; i * j < n + 1; ++j) {
				isPrime[i * j] = false;
			}
		}
	}
	for (int i = 2; i < n + 1; ++i) {
		if (isPrime[i]) prime.push_back(i);
	}
	int start = 0, end = 0, sum, len = prime.size(), cnt = 0;
	prime.push_back(0);
	sum = prime[0];
	while (start <= end && end < len) {
		if (sum > n) {
			sum -= prime[start++];
			if (start > end && start < len) {
				sum = prime[start];
				end = start;
			}
		}
		else if (sum == n) {
			++cnt;
			sum += prime[++end];
		}
		else {
			sum += prime[++end];
		}
	}
	cout << cnt << '\n';
	return 0;
}