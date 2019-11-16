// https://www.acmicpc.net/problem/2225
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#define max(x, y) x > y ? x: y; 
#define min(x, y) x > y ? y: x;
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long int comb[400][201] = {};
int main() {
	int n, k, i, j;
	scanf(" %d", &n);
	scanf(" %d", &k);
	for (i = 1; i < 400; i++) {
		if (i < 201) {
			comb[i][i] = 1;
		}
		comb[i][0] = 1;
		comb[i][1] = i;
	}
	for (i = 2; i < n + 1; i++) {
		for (j = i; j < n + k; j++) {
			comb[j][i] = (comb[j - 1][i] + comb[j - 1][i - 1]) % 1000000000;
		}
	}
	printf("%lld\n", comb[n + k - 1][n]);
	return 0;
}