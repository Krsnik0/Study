// https://www.acmicpc.net/problem/11004
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
void qsort(vector<long long>* arr, int left, int right) {
	int l = left, r = right;
	long long pivot = (*arr)[(left * 64 + right * 36) / 100], tmp;

	while (l <= r) {
		while ((*arr)[l] < pivot)
			l++;
		while (pivot < (*arr)[r])
			r--;
		if (l <= r) {
			tmp = (*arr)[l];
			(*arr)[l] = (*arr)[r];
			(*arr)[r] = tmp;
			l++; r--;
		}
	}
	if (left < r)
		qsort(arr, left, r);
	if (l < right)
		qsort(arr, l, right);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<long long> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	qsort(&input, 0, n - 1);
	cout << input[k - 1];

	return 0;
}