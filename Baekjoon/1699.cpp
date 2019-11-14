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
		memset(ans, -1, sizeof(int)*(100001));
	}
	void debug() {
	}
	void solve() {
		int tmp;
		ans[1] = 1;
		for (int i = 2; i < n + 1; i++) {
			tmp = 100001;
			for (int j = 1; j < i + 1; j++) {
				if (i - (j * j) < 0)
					break;
				if (i == j * j) {
					tmp = 1;
					break;
				}
				if (tmp > ans[i - (j * j)] + 1)
					tmp = ans[i - (j * j)] + 1;
			}
			ans[i] = tmp;
			//printf("%d: %d\n", i, ans[i]);
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