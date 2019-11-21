// https://www.acmicpc.net/problem/2751
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

void qsort(vector<int>* arr, int left, int right) {
	int l = left, r = right, tmp;
	int pivot = (*arr)[(left + right) / 2];

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

	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	
	qsort(&input, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << input[i] << '\n';
	}

	return 0;
}