// https://www.acmicpc.net/problem/9095
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class fibo {
private:
	int n;
	int* ans;
public:
	fibo() {
		
		ans = new int[11];
		memset(ans, 0, sizeof(int) * (11));
	}
	void solve(int n) {
		ans[1] = 1;
		ans[2] = 2;
		ans[3] = 4;
		for (int i = 4; i < n + 1; i++) {
			ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
		}
		printf("%d\n", ans[n]);
	}
	~fibo() {
		delete[] ans;
	}
};

int main() {
	int n, m;
	scanf("%d", &n);
	fibo aaa;
	while (n-- > 0) {
		scanf("%d", &m);
		aaa.solve(m);
	}
	return 0;
}