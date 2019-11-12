// https://www.acmicpc.net/problem/11054
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
	int* lisAsc; //from 0
	int* lisDsc; //from n-1
public:
	lis(int n) {
		this->n = n;
		input = new int[n];
		lisAsc = new int[n];
		lisDsc = new int[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", input + i);
		}
		memset(lisAsc, 0, sizeof(int) * n);
		memset(lisDsc, 0, sizeof(int) * n);

	}
	void debug() {
		for (int i = 0; i < n; i++) {
			printf("%d\n", input[i]);
		}
	}
	void solve() {
		int max = 1, i, j;
		lisAsc[0] = 1;
		lisDsc[n - 1] = 1;
		int tmp;
		for (i = 1; i < n; i++) {
			tmp = 1;
			for (j = 0; j < i; j++) {
				if (input[j] < input[i] && lisAsc[j] + 1 >tmp)
					tmp = lisAsc[j] + 1;
			}
			lisAsc[i] = tmp;
		}
		for (i = n - 2; i >= 0; i--) {
			tmp = 1;
			for (j = n - 1; j >= i; j--) {
				if (input[j] < input[i] && lisDsc[j] + 1 > tmp) {
					tmp = lisDsc[j] + 1;
				}
			}
			lisDsc[i] = tmp;
		}
		max = 1;
		for (i = 0; i < n; i++) {
			if (lisAsc[i] + lisDsc[i] - 1 > max) {
				max = lisAsc[i] + lisDsc[i] - 1;
			}
		}
		printf("%d\n", max);
	}
	~lis() {
		delete[] input;
		delete[] lisAsc;
		delete[] lisDsc;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	lis aaa(n);
	aaa.solve();

	return 0;
}
