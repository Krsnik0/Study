// https://www.acmicpc.net/problem/1168
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

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, k, i, idx;
	cin >> n >> k;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		input[i] = i + 1;
	}
	cout << '<';
	idx = k - 1;
	for (i = 0; i < n - 1; ++i) {
		cout << input[idx] << ", ";
		input.erase(input.begin() + idx);
		idx = (idx + k - 1) % input.size();
	}
	cout << input.front() << '>';

	return 0;
}