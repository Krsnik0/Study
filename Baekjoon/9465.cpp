// https://www.acmicpc.net/problem/9465
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class sommelier {
private:
	int n;
	int* input;
	int** ans;
public:
	sommelier(int n) {
		this->n = n;
		input = new int[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", input + i);
		}

		ans = new int* [2];
		for (int i = 0; i < 2; i++) {
			ans[i] = new int[n];
			memset(ans[i], 0, sizeof(int) * n);
		}
	}
	void solve() {
		ans[1][0] = input[0];
		ans[0][1] = input[0];
		ans[1][1] = input[0] + input[1];
		for (int i = 2; i < n; i++) {
			ans[0][i] = max(ans[0][i - 1], ans[1][i - 1]);
			ans[1][i] = max(max(ans[0][i - 2], ans[1][i - 2]), ans[0][i - 2] + input[i - 1]) + input[i];
		}

		printf("%d\n", max(ans[0][n - 1], ans[1][n - 1]));
	}
	~sommelier() {

		delete[] input;
		for (int i = 0; i < 2; i++) {
			delete[] ans[i];
		}
		delete[] ans;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	sommelier aaa(n);
	aaa.solve();

	return 0;
}