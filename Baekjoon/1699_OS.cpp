// https://www.acmicpc.net/problem/1699
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#define max(x, y) x > y ? x: y; 
#define min(x, y) x > y ? y: x;
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class lis {
private:
	int n;
	//int* input;
	int* ans;
public:
	lis(int n) {
		this->n = n;
		ans = new int[100001];
		memset(ans, 0, sizeof(int) * 100001);
	}
	void debug() {
	}
	void solve() {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j * j < i + 1; j++) {
				if (ans[i] > ans[i - (j * j)] + 1 || ans[i] == 0)
					ans[i] = ans[i - (j * j)] + 1;
			}
		}
		printf("%d\n", ans[n]);
	}
	~lis() {
		delete[] ans;
	}
};
int main() {
	int n;
	scanf("%d", &n);
	lis aaa(n);
	aaa.solve();

	return 0;
}