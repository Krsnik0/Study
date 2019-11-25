// https://www.acmicpc.net/problem/10808
// Written by JSH, Krsnik

//#define max(x, y) x > y ? x: y; 
//#define min(x, y) x > y ? y: x;
#define N 1000000
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <ctime>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string str;
	cin >> str;
	vector<int> counter(26, 0);
	for (int i = 0; i < str.length(); ++i) {
		counter[str[i] - 'a'] += 1;
	}
	for (int i = 0; i < 26; ++i) {
		cout << counter[i] << ' ';
	}

	return 0;
}