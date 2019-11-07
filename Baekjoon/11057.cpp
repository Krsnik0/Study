// https://www.acmicpc.net/problem/11057
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class stairwayToHeaven {
private:
	int** ans;
public:
	stairwayToHeaven() {
		ans = new int*[1001];
		for (int i = 0; i < 1001; i++) {
			ans[i] = new int[10];
			memset(ans[i], 0, sizeof(int) * 10);
		}
	}
	void solve(int n) {
		ans[1][0] = 1;
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
			for (int j = 0; j < 10; j++) {
				for (int k = j; k < 10; k++) {
					ans[i][j] = (ans[i][j] + ans[i - 1][k]) % 10007;
				}
			}		
		}
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += ans[n][i];
		}
		printf("%d\n", sum % 10007);
	}
	~stairwayToHeaven() {
		for (int i = 0; i < 1001; i++) {
			delete[] ans[i];
		}
		delete[] ans;
	}	
};

int main() {
	int n;
	scanf("%d", &n);
	stairwayToHeaven aaa;
	aaa.solve(n);
	return 0;
}