// https://www.acmicpc.net/problem/1406
// Written by JSH, Krsnik

//#define max(x, y) x > y ? x: y; 
//#define min(x, y) x > y ? y: x;
#define N 1000000
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str, cmd;
	char ch;
	stack<char> ori, ans;
	int n, tmp;
	cin >> str >> n;
	for (int i = 0; i < str.length(); ++i) {
		ori.push(str[i]);
	}
	while (n--) {
		cin >> cmd;
		if (cmd == "L") {
			if (!ori.empty()) {
				ans.push(ori.top());
				ori.pop();
			}
		}
		if (cmd == "D") {
			if (!ans.empty()) {
				ori.push(ans.top());
				ans.pop();
			}
		}
		if (cmd == "B")
			if (!ori.empty()) {
				ori.pop();
			}
		if (cmd == "P") {
			cin >> ch;
			ori.push(ch);
		}
	}
	tmp = ori.size();
	for (int i = 0; i < tmp; ++i) {
		ans.push(ori.top());
		ori.pop();
	}
	tmp = ans.size();
	for (int i = 0; i < tmp; ++i) {
		cout << ans.top();
		ans.pop();
	}

	return 0;
}