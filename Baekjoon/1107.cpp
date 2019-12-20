// https://www.acmicpc.net/problem/1107
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

bool isPossible(int& i, const vector<bool>& isBreakDown) {
	if (i == 0) {
		return !isBreakDown[i];
	}
	
	int tmp = i;
	while (tmp != 0) {
		if (isBreakDown[tmp % 10])
			return false;
		tmp /= 10;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m, tmp, digit = 0;
	cin >> n >> m;
	vector<bool> isBreakDown(10, false);
	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		isBreakDown[tmp] = true;
	}
	
	int case1, case2, case3;
	case1 = n > 100 ? n - 100 : 100 - n;
	
	int button = 1000000;
	for (int i = n; i < 1000001; ++i) {
		if (isPossible(i, isBreakDown)) {
			button = i;
			break;
		}
	}
	tmp = button;
	digit = 0;
	do {
		tmp /= 10;
		digit++;
	} while (tmp != 0);
	case2 = button - n + digit;

	button = -1000000;
	for (int i = n; i > -1; --i) {
		if (isPossible(i, isBreakDown)) {
			button = i;
			break;
		}
	}
	tmp = button;
	digit = 0;
	do {
		tmp /= 10;
		digit++;
	} while (tmp != 0);
	case3 = n - button + digit;

	int min = case1 > case2 ? (case2 > case3 ? case3 : case2) : (case1 > case3 ? case3 : case1);
	cout << min << '\n';
	return 0;
}