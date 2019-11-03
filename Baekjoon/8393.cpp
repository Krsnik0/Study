/*
문제
n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n (1 ≤ n ≤ 10,000)이 주어진다.

출력
1부터 n까지 합을 출력한다.
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int i, x, y, sum = 0;
	scanf("%d", &x);
	for (i = 0; i < x; i++)
		sum += i + 1;
	printf("%d\n", sum);
	
	return 0;
}