// https://www.acmicpc.net/problem/10989
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, tmp;
	cin >> n;
	vector<int> input(10001, 0);
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		++input[tmp];
	}

	for (int i = 1; i < 10001; ++i) {
		for (int j = 0; j < input[i]; ++j) {
			cout << i << '\n';
		}
	}

	return 0;
}