// https://www.acmicpc.net/problem/2309
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	vector<int> dwarf(9);
	int n = 9, sum = 0;
	while (n--) {
		cin >> dwarf[n];
		sum += dwarf[n];
	}
	sort(dwarf.begin(), dwarf.end());
	sum -= 100;
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (dwarf[i] + dwarf[j] == sum) {
				for (int k = 0; k < 9; ++k) {
					if (k != i && k != j)
						cout << dwarf[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}