/*
문제
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.

출력
입력으로 주어진 숫자 N개의 합을 출력한다.
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int a[101], i, n, sum = 0;
	char ch;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" %c", &ch);
		sum += ch - '0';
	}
	printf("%d\n", sum);

	return 0;
}