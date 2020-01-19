// https://www.acmicpc.net/problem/1451
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
using ll = long long int;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	char a;
	vector<vector<int>> v(n);
	for (auto& item : v)
		item.resize(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a;
			v[i][j] = a - '0';
		}
	}
	ll ans = 0, tmp = 0;
	int sum1 = 0, sum2 = 0, sum3 = 0;
	//case: ㅗ ㅜ ㅓ ㅏ = || total 6

	//case1 ㅜ
	if (n > 1) {
		for (int i = 0; i < n - 1; ++i) {
			sum1 = 0;
			for (int j = 0; j < i + 1; ++j) {
				for (int k = 0; k < m; ++k) {
					sum1 += v[j][k];
				}
			}
			for (int k = 0; k < m - 1; ++k) {
				sum2 = 0, sum3 = 0;
				for (int l = 0; l < k + 1; ++l) {
					for (int j = i + 1; j < n; ++j) {
						sum2 += v[j][l];
					}
				}
				for (int l = k + 1; l < m; ++l) {
					for (int j = i + 1; j < n; ++j) {
						sum3 += v[j][l];
					}
				}
				tmp = (ll)sum1 * (ll)sum2 * (ll)sum3;
				ans = ans > tmp ? ans : tmp;
			}
		}
	}
	//case2 ㅗ
	if (n > 1) {
		for (int i = 0; i < n - 1; ++i) {
			sum3 = 0;
			for (int j = i + 1; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					sum3 += v[j][k];
				}
			}
			for (int k = 0; k < m - 1; ++k) {
				sum1 = 0, sum2 = 0;
				for (int l = 0; l < k + 1; ++l) {
					for (int j = 0; j < i + 1; ++j) {
						sum1 += v[j][l];
					}
				}
				for (int l = k + 1; l < m; ++l) {
					for (int j = 0; j < i + 1; ++j) {
						sum2 += v[j][l];
					}
				}
				tmp = (ll)sum1 * (ll)sum2 * (ll)sum3;
				ans = ans > tmp ? ans : tmp;
			}
		}
	}
	//case3,4
	if (m > 1) {
		for (int i = 0; i < m - 1; ++i) {
			sum1 = 0;
			for (int j = 0; j < i + 1; ++j) {
				for (int k = 0; k < n; ++k) {
					sum1 += v[k][j];
				}
			}
			for (int k = 0; k < n - 1; ++k) {
				sum2 = 0, sum3 = 0;
				for (int l = 0; l < k + 1; ++l) {
					for (int j = i + 1; j < m; ++j) {
						sum2 += v[l][j];
					}
				}
				for (int l = k + 1; l < n; ++l) {
					for (int j = i + 1; j < m; ++j) {
						sum3 += v[l][j];
					}
				}
				tmp = (ll)sum1 * (ll)sum2 * (ll)sum3;
				ans = ans > tmp ? ans : tmp;
			}
		}
	}
	if (m > 1) {
		for (int i = 0; i < m - 1; ++i) {
			sum3 = 0;
			for (int j = i + 1; j < m; ++j) {
				for (int k = 0; k < n; ++k) {
					sum3 += v[k][j];
				}
			}
			for (int k = 0; k < n - 1; ++k) {
				sum1 = 0, sum2 = 0;
				for (int l = 0; l < k + 1; ++l) {
					for (int j = 0; j < i + 1; ++j) {
						sum1 += v[l][j];
					}
				}
				for (int l = k + 1; l < n; ++l) {
					for (int j = 0; j < i + 1; ++j) {
						sum2 += v[l][j];
					}
				}
				tmp = (ll)sum1 * (ll)sum2 * (ll)sum3;
				ans = ans > tmp ? ans : tmp;
			}
		}
	}
	//case5 =
	if (n > 2) {
		for (int i = 0; i < n - 2; ++i) {
			sum1 = 0;
			for (int h = 0; h < m; ++h) {
				for (int w = 0; w < i + 1; ++w) {
					sum1 += v[w][h];
				}
			}
			for (int j = i + 1; j < n - 1; ++j) {
				sum2 = 0;
				for (int h = 0; h < m; ++h) {
					for (int w = i + 1; w < j + 1; ++w) {
						sum2 += v[w][h];
					}
				}
				sum3 = 0;
				for (int k = j + 1; k < n; ++k) {
					for (int h = 0; h < m; ++h) {
						sum3 += v[k][h];						
					}
					tmp = (ll)sum1 * (ll)sum2 * (ll)sum3;
					ans = ans > tmp ? ans : tmp;
				}
			}
		}
	}
	//case6 ||
	if (m > 2) {
		for (int i = 0; i < m - 2; ++i) {
			sum1 = 0;
			for (int h = 0; h < n; ++h) {
				for (int w = 0; w < i + 1; ++w) {
					sum1 += v[h][w];
				}
			}
			for (int j = i + 1; j < m - 1; ++j) {
				sum2 = 0;
				for (int h = 0; h < n; ++h) {
					for (int w = i + 1; w < j + 1; ++w) {
						sum2 += v[h][w];
					}
				}
				sum3 = 0;
				for (int k = j + 1; k < m; ++k) {
					for (int h = 0; h < n; ++h) {
						sum3 += v[h][k];
						
					}
				}
				tmp = (ll)sum1 * (ll)sum2 * (ll)sum3;
				ans = ans > tmp ? ans : tmp;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}