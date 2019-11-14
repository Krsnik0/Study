// https://www.acmicpc.net/problem/2579
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class lis {
private:
	int n;
	int* input;
	int* ans;
public:
	lis(int n) {
		this->n = n;
		input = new int[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", input + i);
		}
		ans = new int[n];
		memset(ans, 0, sizeof(int) * n);
		
	}
	void debug() {
	}
	void solve() {
		ans[0] = input[0];
		ans[1] = input[0] + input[1];
		ans[2] = max(input[0] + input[2], input[1] + input[2]);
		for (int i = 3; i < n; i++) {
			ans[i] = max(ans[i - 2], ans[i - 3] + input[i - 1]) + input[i];
		}

		printf("%d\n", ans[n-1]);
	}
	~lis() {
		delete[] input;
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