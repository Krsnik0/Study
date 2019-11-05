//https://www.acmicpc.net/problem/1463
//Written By Krsnik, JSH

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class numToOne {
private:
	int n;
	int* ans;
public:
	numToOne(int n) {
		this->n = n;
        ans = new int[n + 1];
	}
	void solve() {
		ans[1] = 0;
		for (int i = 2; i < n + 1; i++) {
			ans[i] = ans[i - 1] + 1;
			if (i % 2 == 0) {
				ans[i] = min(ans[i / 2] + 1, ans[i]);
			}
			if (i % 3 == 0) {
				ans[i] = min(ans[i / 3] + 1, ans[i]);
			}
		}
		printf("%d\n", ans[n]);
	}
    ~numToOne(){
        delete[] ans;
    }
};

int main() {
	int n;
	scanf("%d", &n);
	numToOne aaa(n);
	aaa.solve();

	return 0;
}