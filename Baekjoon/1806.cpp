// https://www.acmicpc.net/problem/1806
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, s, sum;
	cin >> n >> s;
	vector<int> input(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	int min = 100003, start = 0, end = 0;
	sum = input[0];

	while (start <= end && end < n) {
		if (sum > s) {
			min = min < end - start + 1 ? min : end - start + 1;
			sum -= input[start++];			
		}
		else if (sum == s) {
			min = min < end - start + 1 ? min : end - start + 1;
			sum += input[++end];
		}
		else {
			sum += input[++end];
		}
	}

	if (min == 100003) min = 0;
	cout << min << '\n';

	return 0;
}