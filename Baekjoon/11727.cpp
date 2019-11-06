// https://www.acmicpc.net/problem/11727
//  Written by Krsnik, JSH

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
	fibo(int n) {
		this->n = n;
		ans = new int[n + 1];
		memset(ans, 0, sizeof(int) * (n + 1));
	}
	void solve() {
		ans[1] = 1;
		ans[2] = 3;
		for (int i = 3; i < n + 1; i++) {
			ans[i] = (ans[i - 1] + 2 * ans[i - 2]) % 10007;
		}
		printf("%d\n", ans[n]);
	}
	~fibo() {
		delete[] ans;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	fibo aaa(n);
	aaa.solve();
	return 0;
}