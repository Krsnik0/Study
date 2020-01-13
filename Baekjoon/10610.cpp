// https://www.acmicpc.net/problem/10610
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string n;
	cin >> n;
	vector<int> v(10, 0);
	int sum = 0;
	for (int i = 0; i < n.length(); ++i) {
		sum += n[i] - '0';
	}
	sort(n.begin(), n.end(), greater<int>());
	bool chk = (sum % 3 == 0) && (n[n.size() - 1] == '0') ? true : false;
	if (chk) {
		cout << n << '\n';
	}
	else {
		cout << "-1\n";
	}	

	return 0;
}