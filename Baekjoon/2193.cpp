// https://www.acmicpc.net/problem/2193
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class pinary {
private:
	int n;
	long long** ans;
public:
	pinary(int n) {
		this->n = n;
		ans = new long long* [n + 1];
		for (int i = 0; i < n + 1; i++) {
			ans[i] = new long long[2];
			memset(ans[i], 0, sizeof(long long) * 2);
		}
	}
	void solve() {
		ans[1][0] = 0;
		ans[1][1] = 1;

		for (int i = 2; i < n + 1; i++) {
			ans[i][0] = ans[i - 1][0] + ans[i - 1][1];
			ans[i][1] = ans[i - 1][0];
		}
		
		printf("%lld\n", ans[n][0] + ans[n][1]);
	}
	~pinary() {
		for (int i = 0; i < n + 1; i++) {
			delete[] ans[i];
		}
		delete[] ans;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	pinary aaa(n);
	aaa.solve();
	return 0;
}