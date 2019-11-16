// https://www.acmicpc.net/problem/2011
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#define max(x, y) x > y ? x: y; 
#define min(x, y) x > y ? y: x;
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char pass[5001];
long int ans[5002] = {};
int main() {
	int tmp = 0;
	scanf("%s", pass);
	string str = pass;
	int len = str.size();
	ans[0] = 1;
	if ('1' <= pass[0] && pass[0] <= '9') {
		ans[1] = 1;
	}

	for (int i = 2; i < len + 1; i++) {
		//i: 문자열 길이 => pass에서 구할땐 -1
		if ('1' <= pass[i - 1] && pass[i - 1] <= '9') {
			ans[i] += ans[i - 1];
			ans[i] %= 1000000;
		}
		tmp = (pass[i - 2] - '0') * 10 + (pass[i - 1] - '0');
		if (10 <= tmp && tmp <= 26) {
			ans[i] += ans[i - 2];
			ans[i] %= 1000000;
		}		
	}
	printf("%ld\n", ans[len]);

	return 0;
}