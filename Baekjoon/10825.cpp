// https://www.acmicpc.net/problem/10825
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef struct _grade {
	string name;
	int kor;
	int eng;
	int mat;
}Grade;

bool cmp(Grade p1, Grade p2) {
	return p1.kor == p2.kor ? (p1.eng == p2.eng ? (p1.mat == p2.mat ? p1.name < p2.name : p1.mat > p2.mat) : p1.eng < p2.eng) : p1.kor > p2.kor;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<Grade> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i].name >> input[i].kor >> input[i].eng >> input[i].mat;
	}
	stable_sort(input.begin(), input.end(), cmp);

	for (int i = 0; i < n; ++i) {
		cout << input[i].name << '\n';
	}

	return 0;
}