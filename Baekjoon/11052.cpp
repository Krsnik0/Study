// https://www.acmicpc.net/problem/11052
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#define max(x, y) x > y ? x: y; 
#define min(x, y) x > y ? y: x;
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int p[1001] = {};
int ans[1001] = {};
int main() {
	int n, tmp = 0;
	scanf("%d", &n);
	tmp = n;
	while (tmp-- > 0) {
		scanf(" %d", p + (n - tmp));
	}
	ans[1] += p[1];
	for (int i = 2; i < n + 1; i++) {
		tmp = 0;
		for (int j = 1; j < i + 1; j++) {
			tmp = max(tmp, p[j] + ans[i - j]);
		}
		ans[i] = tmp;
	}
	printf("%d\n", ans[n]);

	return 0;
}