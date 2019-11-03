/*
문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.

예제 입력 1 
5
예제 출력 1 
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n, i, j;
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < i + 1; j++) {
			printf("*");
		}
		for (j = n - i - 1; j > 0; j--) {
			printf("  ");
		}
		for (j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = n - 1; i > 0; i--) {
		for (j = i; j > 0; j--) {
			printf("*");
		}
		for (j = 0; j < n - i; j++) {
			printf("  ");
		}
		for (j = i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}