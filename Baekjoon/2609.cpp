// https://www.acmicpc.net/problem/2609
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

int euclid(int a, int b) {
	int big = a > b ? a : b, small = a > b ? b : a;
	while (big > small) big -= small;
	if (small % big == 0)
		return big;
	else
		return euclid(big, small);	
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int gcd = euclid(n, m);
	cout << gcd << '\n';
	cout << n * m / gcd;
	return 0;
}