// https://www.acmicpc.net/problem/6588
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

	vector<int> prime;
	vector<int> prime2(1000001, 0);
	prime2[1] = 1;
	for (int i = 2; i < 1000001; ++i) {
		if (prime2[i] == 0) {
			for (int j = 2; i * j < 1000001; ++j) {
				prime2[i * j] = 1;
			}
			prime.push_back(i);
		}
	}

	int n = 1, flag;
	cin >> n;
	while (n != 0) {		
		flag = 0;
		for (int i = 0; prime[i] < n ; ++i) {
			if (prime2[n - prime[i]] == 0) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				flag = 1;
				break;
			}
		}
		if (flag == 0)cout << "Goldbach's conjecture is wrong.\n";
		cin >> n;
	}

	return 0;
}