// https://www.acmicpc.net/problem/2331
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int pow(int a, int b) {
	int ans = 1;
	for (int i = 0; i < b; ++i)ans *= a;
	return ans;
}

int calcNext(int a, int p) {
	int ans = 0, tmp = a;
	while (tmp) {
		ans += pow(tmp % 10, p);
		tmp /= 10;
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, p, i;
	cin >> a >> p;
	vector<int> repeatArr;
	repeatArr.push_back(a);
	while (1) {
		a = calcNext(a, p);
		for (i = 0; i < repeatArr.size(); ++i) {
			if (repeatArr[i] == a) {
				cout << i << '\n';
			return 0;
			}
		}		
		repeatArr.push_back(a);
	}
	return 0;
}