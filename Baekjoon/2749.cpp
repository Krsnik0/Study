// https://www.acmicpc.net/problem/2749
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

unsigned long long fastFibo(unsigned long long n) {
	unsigned long long a = 0;
	unsigned long long b = 1;
	for (int i = 63; i >= 0; --i) {
		long long chk = 2 * b - a;
		chk = chk >= 0 ? chk : chk + 1000000;
		unsigned long long d = (a * (unsigned long long)chk) % 1000000;
		unsigned long long e = (a * a) % 1000000 + (b * b) % 1000000;
		a = d % 1000000;
		b = e % 1000000;
		if (((n >> i) & 1) != 0) {
			unsigned long long c = (a + b) % 1000000;
			a = b;
			b = c;
		}
	}
	return a;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	
	cin >> n;
	cout << fastFibo(n) << "\n";
	
	return 0;
}