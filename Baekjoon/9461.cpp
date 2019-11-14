// https://www.acmicpc.net/problem/9461
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long int arr[101] = {0, 1, 1, 1, 2, 2};
int main() {
	int t, n;
	scanf("%d", &t);
	for (int i = 6; i < 101; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	while (t-- > 0) {
		scanf(" %d", &n);
		printf("%lld\n", arr[n]);
	}
	return 0;
}