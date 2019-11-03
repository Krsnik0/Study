/*
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A, 둘째 줄에 B가 주어진다. (0 < A, B < 10)

출력
첫째 줄에 A+B를 출력한다.
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int a, b;
	scanf("%d\n%d", &a, &b);
	printf("%d", a + b);
	
	return 0;
}