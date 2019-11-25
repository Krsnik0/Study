// https://www.acmicpc.net/problem/11655
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
	getline(cin, str);
	for (int i = 0; i < str.length(); ++i) {
		if ('a' <= str[i] && str[i] <= 'm') {
			str[i] += 13;
		}
		else if ('n' <= str[i] && str[i] <= 'z') {
			str[i] -= 13;
		}
		if ('A' <= str[i] && str[i] <= 'M') {
			str[i] += 13;
		}
		else if ('N' <= str[i] && str[i] <= 'Z') {
			str[i] -= 13;
		}
	}
	cout << str;

	return 0;
}