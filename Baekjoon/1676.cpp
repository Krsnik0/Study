// https://www.acmicpc.net/problem/1676
// Written by JSH, Krsnik

//#define max(x, y) x > y ? x: y; 
//#define min(x, y) x > y ? y: x;
#define N 1000000
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <ctime>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int cnt = 0;
	cin >> n;
	
	while (1) {
		n /= 5;
		if (n > 0)
			cnt += n;
		else
			break;
	}
	cout << cnt;

	return 0;
}