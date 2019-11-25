// https://www.acmicpc.net/problem/10845
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
	int n, push, front = 0, back = -1;
	string cmd;
	cin >> n;
	vector<int> queue(100001, 0);
	while (n-- > 0) {
		cin >> cmd;
		if (cmd.compare("push") == 0) {
			cin >> push;
			queue[++back] = push;
		}
		if (cmd.compare("pop") == 0) {
			if ((back - front) < 0) { 
				cout << -1 << '\n'; 
			}
			else {
				cout << queue[front++] << '\n';
			}			
		}
		if (cmd.compare("size") == 0) {
			if ((back - front) < 0) cout << 0 << '\n';
			else cout << (back - front) + 1 << '\n';
		}
		if (cmd.compare("empty") == 0) {
			if ((back - front) < 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		if (cmd.compare("front") == 0) {
			if ((back - front) < 0) cout << -1 << '\n';
			else cout << queue[front] << '\n';
		}
		if (cmd.compare("back") == 0) {
			if ((back - front) < 0) cout << -1 << '\n';
			else cout << queue[back] << '\n';
		}
	}

	return 0;
}