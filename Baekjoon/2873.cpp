// https://www.acmicpc.net/problem/2873
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

bool cmp(vector<int> v1, vector<int> v2) {
	return v1[1] < v2[1];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int min = 1001, minI = -1, minJ = -1;
	vector<vector<int>> v(n);
	for (auto& item : v)
		item.resize(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
			if ((i + j) % 2 != 0) {
				if (min > v[i][j]) {
					min = v[i][j];
					minI = i;
					minJ = j;
				}
			}
		}
	}
	string ans;
	if (n % 2 == 1) {
		for (int i = 1; 2 * i < n; ++i) {
			for (int j = 0; j < m - 1; ++j) {
				ans.append("R");
			}
			ans.append("D");
			for (int j = 0; j < m - 1; ++j) {
				ans.append("L");
			}
			ans.append("D");
		}
		for (int j = 0; j < m - 1; ++j) {
			ans.append("R");
		}
	}
	else if (n % 2 == 0 && m % 2 == 1) {
		for (int i = 1; 2 * i < m; ++i) {
			for (int j = 0; j < n - 1; ++j) {
				ans.append("D");
			}
			ans.append("R");
			for (int j = 0; j < n - 1; ++j) {
				ans.append("U");
			}
			ans.append("R");
		}
		for (int j = 0; j < n - 1; ++j) {
			ans.append("D");
		}
	}
	else if (n % 2 == 0 && m % 2 == 0) {
		bool updown = true; // true: down - up , false: up - down
		for (int j = 0; 2 * j < m; ++j) {
			if (minJ == (2 * j) || minJ == (2 * j + 1)) {
				bool flag = true; //true: ->, false: <-
				for (int i = 0; i < n; ++i) {
					if (i == minI) {
						ans.append("D");
					}
					else {
						if (flag) {
							if (i == n - 1)
								ans.append("RR");
							else
								ans.append("RD");
							flag = flag ? false : true;
						}
						else {
							if (i == n - 1)
								ans.append("LL");
							else
								ans.append("LD");
							flag = flag ? false : true;
						}
					}
				}
				updown = false;
			}
			else {
				if (updown) {
					for (int i = 0; i < n - 1; ++i) {
						ans.append("D");
					}
					ans.append("R");
					for (int i = 0; i < n - 1; ++i) {
						ans.append("U");
					}
					ans.append("R");
				}
				else {
					for (int i = 0; i < n - 1; ++i) {
						ans.append("U");
					}
					ans.append("R");
					for (int i = 0; i < n - 1; ++i) {
						ans.append("D");
					}
					ans.append("R");
				}
			}
		}
		ans = ans.substr(0, ans.size() - 1);
	}

	cout << ans << '\n';

	return 0;
}