// https://www.acmicpc.net/problem/11005
// Written by JSH, Krsnik

//#define max(x, y) x > y ? x: y; 
//#define min(x, y) x > y ? y: x;
#define N 1000000
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int pow(int a, int b) {
	int sum = 1;
	for (int i = 0; i < b; ++i) {
		sum *= a;
	}
	return sum;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	/*
	int n, b, tmp, cnt = 0;
	cin >> n >> b;
	tmp = b;
	while (tmp <= n) {
		tmp *= b;
		++cnt;
	}
	int maxPower = cnt, sub;
	vector<char> sys(maxPower + 1, 0);
	tmp = n;
	for (int i = maxPower; i >= 0; --i) {
		sub = tmp / pow(b, i);
		if (sub > 9)
			sys[i] = sub - 10 + 'A';
		else
			sys[i] = sub + '0';
		tmp %= pow(b, i);
	}
	for (int i = maxPower; i >= 0; --i)
		cout << sys[i];*/

	int n, b;
	cin >> n >> b;
	vector<int> ans;
	while (n != 0) {
		ans.push_back(n%b);
		n /= b;
	}
	for (int i = ans.size(); i > 0; --i) {
		if (ans[i-1] > 9)
			cout << (char)(ans[i-1] - 10 + 'A');
		else
			cout << ans[i-1];
	}

	return 0;
}