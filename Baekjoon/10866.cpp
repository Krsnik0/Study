// https://www.acmicpc.net/problem/10866
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
	int n, push, front = 9999, back = 9999;
	string cmd;
	cin >> n;
	vector<int> deque(200001, 0);
	while (n-- > 0) {
		cin >> cmd;
		if (cmd.compare("push_front") == 0) {
			cin >> push;
			deque[--front] = push;
		}
		if (cmd.compare("push_back") == 0) {
			cin >> push;
			deque[back++] = push;
		}
		if (cmd.compare("pop_front") == 0) {
			if ((back - front) <= 0) { 
				cout << -1 << '\n'; 
			}
			else {
				cout << deque[front++] << '\n';
			}
		}
		if (cmd.compare("pop_back") == 0) {
			if ((back - front) <= 0) {
				cout << -1 << '\n';
			}
			else {
				cout << deque[--back] << '\n';
			}
		}
		if (cmd.compare("size") == 0) {
			cout << (back - front) << '\n';
		}
		if (cmd.compare("empty") == 0) {
			if ((back - front) <= 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		if (cmd.compare("front") == 0) {
			if ((back - front) <= 0) cout << -1 << '\n';
			else cout << deque[front] << '\n';
		}
		if (cmd.compare("back") == 0) {
			if ((back - front) <= 0) cout << -1 << '\n';
			else cout << deque[back - 1] << '\n';
		}
	}

	return 0;
}