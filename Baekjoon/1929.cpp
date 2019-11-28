// https://www.acmicpc.net/problem/1929
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

	int n, m;
	cin >> n >> m;
	vector<int> prime2(m + 1, 0);
	prime2[1] = 1;
	for (int i = 2; i < m + 1; ++i) {
		if (prime2[i] == 0) {
			for (int j = 2; i*j < m + 1; ++j) {
				prime2[i * j] = 1;
			}
		}
	}
	for (int i = n; i < m + 1; ++i) {
		if (prime2[i] == 0)
			cout << i << '\n';
    }
	return 0;
}