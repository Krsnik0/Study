//https://www.acmicpc.net/problem/11722
// Written by JSH, Krsnik

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class lis {
private:
	int n;
	int* input;
	int* lisList;
public:
	lis(int n) {
		this->n = n;
		input = new int[n];
		lisList = new int[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", input + i);
		}
		memset(lisList, 0, sizeof(int) * n);

	}
	void debug() {
		for (int i = 0; i < n; i++) {
			printf("%d\n", input[i]);
		}
	}
	void solve() {
		int max = 1;
		lisList[n - 1] = 1;
		int tmp;
		for (int i = n - 2; i >= 0; i--) {
			tmp = 0;
			for (int j = n - 1; j > i; j--) {
				if (input[j] < input[i]) {
					if (tmp < lisList[j])
						tmp = lisList[j];
				}
			}
			lisList[i] = tmp + 1;
			if (tmp + 1 > max)
				max = tmp + 1;
		}
		printf("%d\n", max);
	}
	~lis() {
		delete[] input;
		delete[] lisList;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	lis aaa(n);
	aaa.solve();

	return 0;
}
