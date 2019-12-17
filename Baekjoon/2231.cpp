// https://www.acmicpc.net/problem/2231
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

	int n, sum, tmp;
	cin >> n;
	vector<vector<int>> v(1000001);

	for (int i = 1; i < n + 1; ++i) {
		sum = i;
		tmp = i;
		while (tmp != 0) {
			sum += (tmp % 10);
			tmp /= 10;
		}
		v[sum].push_back(i);
	}
	if (v[n].size() == 0) {
		cout << "0\n";
	}
	else {
		cout << v[n][0] << '\n';
	}
	
	return 0;
}