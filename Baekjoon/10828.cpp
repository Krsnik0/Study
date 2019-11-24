// https://www.acmicpc.net/problem/10828
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
	int n, idx = -1, push;
	string cmd;
	cin >> n;
	vector<int> stack(100001, 0);
	while (n-- > 0) {
		cin >> cmd;
		if (cmd.compare("push") == 0) {
			cin >> push;
			stack[++idx] = push;
		}
		if (cmd.compare("pop") == 0) {
			if (idx == -1) { 
				cout << -1 << '\n'; 
			}
			else {
				cout << stack[idx--] << '\n';
			}			
		}
		if (cmd.compare("size") == 0) {
			cout << (idx + 1) << '\n';
		}
		if (cmd.compare("empty") == 0) {
			if (idx == -1) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		if (cmd.compare("top") == 0) {
			if (idx == -1) cout << -1 << '\n';
			else cout << stack[idx] << '\n';
		}

	}

	return 0;
}