// https://www.acmicpc.net/problem/11652
// Written by JSH, Krsnik

//#define max(x, y) x > y ? x: y; 
//#define min(x, y) x > y ? y: x;
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n = 0, cnt = 1, max = 1;
	cin >> n;
	vector<long long> input(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	sort(input.begin(), input.end());
	long long ans = input[0];
	for (int i = 1; i < n; ++i) {
		if (input[i - 1] == input[i]) {
			++cnt;
			if (max < cnt) {
				max = cnt;
				ans = input[i - 1];
			}
		}
		else {					
			cnt = 1;
		}
	}
	cout << ans;
	return 0;
}