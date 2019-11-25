// https://www.acmicpc.net/problem/11656
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

	string str;
	cin >> str;
	vector<string> misa(str.length());
	for (int i = 0; i < str.length(); ++i) {
		misa[i] = str.substr(str.length() - i - 1, i + 1);
	}
	sort(misa.begin(), misa.end());
	for (int i = 0; i < str.length(); ++i) {
		cout << misa[i] << '\n';
	}
	return 0;
}