// https://www.acmicpc.net/problem/1912
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
			lis[i] = input[i];
		}
		
	}
	void debug() {
		for (int i = 0; i < n; i++) {
			printf("%d\n", input[i]);
		}
	}
	void solve() {
		int max = input[0];
		
		for (int i = 1; i < n; i++) {
			if (lis[i - 1] + lis[i] > lis[i])
				lis[i] += lis[i - 1];
			if (lis[i] > max)
				max = lis[i];
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