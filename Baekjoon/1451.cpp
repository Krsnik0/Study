// 
//

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
	
	vector<vector<int>> v(n);
	for (auto& item : v)
		item.resize(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}
	int ans = 0;
	//case: ㅗ ㅜ ㅓ ㅏ = || total 6

	//case1 ㅜ
	if (n > 1) {
		int sum1 = 0, sum2 = 0, sum3 = 0;
		for (int i = 0; i < n - 1; ++i) {
			sum1 = 0;
			for (int j = 0; j < i + 1; ++j) {
				for (int k = 0; k < m; ++k) {
					sum1 += v[j][k];
				}				
			}
			for (int j = i + 1; j < n; ++j) {
				
			}

		}
	}

	
	cout << ans << '\n';

	return 0;
}