// https://www.acmicpc.net/problem/2089
// Written by JSH, Krsnik

//#define max(x, y) x > y ? x: y; 
//#define min(x, y) x > y ? y: x;
#define N 1000000
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

void minusbinary(int n) {
	if (n == 0)return;
	if (n % 2 == 0) {
		minusbinary(n / -2);
		cout << 0;
	}
	else {
		minusbinary((n - 1) / -2);
		cout << 1;
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	if (n == 0)
		cout << 0;
	else
		minusbinary(n);

	return 0;
}