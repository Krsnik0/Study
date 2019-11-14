// https://www.acmicpc.net/problem/2133
// Written by JSH, Krsnik

#include <stdio.h>
int arr[31] = {1, 0, 3};
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 0) {
		for (int i = 2; i < n / 2 + 1; i++) {
			arr[2 * i] = 4 * arr[2 * i - 2] - arr[2 * i - 4];
		}
	}
	printf("%d\n", arr[n]);

	return 0;
}
