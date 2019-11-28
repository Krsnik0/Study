// https://www.acmicpc.net/problem/1158
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

	int n, k, i, j;
	cin >> n >> k;
	queue<int> input;
	for (int i = 0; i < n; ++i) {
		input.push(i + 1);
	}
	cout << '<';
	
	for (i = 0; i < n - 1; ++i) {
		for (j = 0; j < k - 1; ++j) {
			input.push(input.front());
			input.pop();
		}		
		cout << input.front() << ", ";
		input.pop();
	}
	cout << input.front() << '>';

	return 0;
}