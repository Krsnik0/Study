// https://www.acmicpc.net/problem/10815
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

	int n, m;
	cin >> n;
	vector<int> sangeun(n);
	for (int i = 0; i < n; ++i) {
		cin >> sangeun[i];
	}
	cin >> m;
	vector<int> card(m);
	for (int i = 0; i < m; ++i) {
		cin >> card[i];
	}
	sort(sangeun.begin(), sangeun.end());

	bool isFind;
	int left, right, mid;
	for (int i = 0; i < m; ++i) {
		left = 0, right = n - 1;
		isFind = false;
		while (left <= right) {
			mid = (left + right) / 2;
			if (card[i] > sangeun[mid]) {
				left = mid + 1;
			}
			else if (card[i] < sangeun[mid]) {
				right = mid - 1;
			}
			else {
				isFind = true;
				break;
			}
		}
		cout << (isFind ? "1" : "0") << ' ';
	}
	cout << '\n';

	return 0;
}