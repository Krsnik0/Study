// https://www.acmicpc.net/problem/1963
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

bool isConvertPossible(int a, int b) {
	//digit: a1/a2/a3/a4
	int a4 = a % 10, a3 = (a / 10) % 10, a2 = (a / 100) % 10, a1 = a / 1000;
	int b4 = b % 10, b3 = (b / 10) % 10, b2 = (b / 100) % 10, b1 = b / 1000;
	int cnt = 0;
	if (a4 == b4) ++cnt;
	if (a3 == b3) ++cnt;
	if (a2 == b2) ++cnt;
	if (a1 == b1) ++cnt;
	return cnt == 3 ? true : false;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<bool> isPrime(10000, true);
	isPrime[0] = false;
	isPrime[1] = false;
	vector<int> prime;
	for (int i = 2; i < 10000; ++i) {
		if (isPrime[i]) {
			if(i > 1000) prime.push_back(i);
			for (int j = 2; i * j < 10000; ++j) {
				isPrime[i * j] = false;
			}
		}
	}
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a == b) {
			cout << 0 << '\n';
			continue;
		}
		vector<bool> isVisit(10000, false);
		int now = a;
		isVisit[a] = true;
		deque<pair<int, int>> q;
		q.push_back({ now, 0});
		while (!q.empty()) {
			pair<int, int> now = q.front();
			if (now.first == b) {
				cout << now.second << '\n';
				break;
			}
			for (int i = 0; i < prime.size(); ++i) {
				if (!isVisit[prime[i]]) {
					if (isConvertPossible(now.first, prime[i])) {
						q.push_back({ prime[i], now.second + 1 });
						isVisit[prime[i]] = true;
					}
				}
			}
			q.pop_front();
		}
		if (!isVisit[b]) cout << "Impossible\n";
	}

	return 0;
}