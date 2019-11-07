// https://www.acmicpc.net/problem/10844
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class stairwayToHeaven {
private:
	long ans[101][10];
public:
	void solve(int n) {
		ans[1][0] = 0;
		ans[1][1] = 1;
		ans[1][2] = 1;
		ans[1][3] = 1;
		ans[1][4] = 1;
		ans[1][5] = 1;
		ans[1][6] = 1;
		ans[1][7] = 1;
		ans[1][8] = 1;
		ans[1][9] = 1;

		for (int i = 2; i < n + 1; i++) {
			ans[i][0] = ans[i - 1][1] % 1000000000;
			for (int j = 1; j < 9; j++) {
				ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j + 1]) % 1000000000;
			}
			ans[i][9] = ans[i - 1][8] % 1000000000;
		}
		long sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += ans[n][i];
		}
		printf("%ld\n", sum % 1000000000);
	}
};

int main() {
	int n;
	scanf("%d", &n);
	stairwayToHeaven aaa;
	aaa.solve(n);
	return 0;
}