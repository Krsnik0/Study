// https://www.acmicpc.net/problem/2004
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

	int n, m;
	int cnt1_5 = 0, cnt2_5 = 0, cnt3_5 = 0;
	int cnt1_2 = 0, cnt2_2 = 0, cnt3_2 = 0;
	cin >> n >> m;
	int tmp1 = n, tmp2 = m, tmp3 = n - m;
	while (1) {
		tmp1 /= 5;
		if (tmp1 > 0)
			cnt1_5 += tmp1;
		else
			break;
	}	
	while (1) {
		tmp2 /= 5;
		if (tmp2 > 0)
			cnt2_5 += tmp2;
		else
			break;
	}
	while (1) {
		tmp3 /= 5;
		if (tmp3 > 0)
			cnt3_5 += tmp3;
		else
			break;
	}

	tmp1 = n, tmp2 = m, tmp3 = n - m;
	while (1) {
		tmp1 /= 2;
		if (tmp1 > 0)
			cnt1_2 += tmp1;
		else
			break;
	}
	while (1) {
		tmp2 /= 2;
		if (tmp2 > 0)
			cnt2_2 += tmp2;
		else
			break;
	}
	while (1) {
		tmp3 /= 2;
		if (tmp3 > 0)
			cnt3_2 += tmp3;
		else
			break;
	}
	int result2 = cnt1_2 - cnt2_2 - cnt3_2;
	int result5 = cnt1_5 - cnt2_5 - cnt3_5;
	cout << min(result2, result5);
	return 0;
}