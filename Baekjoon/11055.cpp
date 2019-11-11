// https://www.acmicpc.net/problem/11055
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class lisSum {
private:
	int n;
	int* input;
	int* lis;
public:
	lisSum(int n) {
		this->n = n;
		input = new int[n];
		lis = new int[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", input + i);
		}
		memset(lis, 0, sizeof(int) * n);

	}
	void debug() {
		for (int i = 0; i < n; i++) {
			printf("%d\n", input[i]);
		}
	}
	void solve() {
		int max = input[0];
		lis[0] = input[0];
		int tmp;
		for (int i = 1; i < n; i++) {
			tmp = input[i];
			for (int j = 0; j < i; j++) {
				if (input[j] < input[i]) {
					if (tmp < lis[j] + input[i])
						tmp = lis[j] + input[i];
				}
			}
			lis[i] = tmp;
			if (tmp > max)
				max = tmp;
		}
		printf("%d\n", max);
	}
	~lisSum() {
		delete[] input;
        delete[] lis;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	lisSum aaa(n);
	aaa.solve();

	return 0;
}