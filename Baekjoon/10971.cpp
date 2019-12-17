// https://www.acmicpc.net/problem/10971
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

void pathFinder(int end, const vector<vector<int>>& input, vector<bool>* isVisit, vector<int>* route, int sum, int* min) {
	int n = isVisit->size();
	if (route->size() == n - 1) {
		if (input[route->back()][route->front()] == 0) {
			return;
		}
		else {
			sum += input[route->back()][route->front()];
			(*min) = (*min) < sum ? (*min) : sum;
			return;
		}
	}

	for (int i = 1; i < n; ++i) {
		if (!(*isVisit)[i] && input[end][i] != 0) {
			if (sum + input[end][i] < (*min)) {
				(*isVisit)[i] = true;
				route->push_back(i);
				pathFinder(i, input, isVisit, route, sum + input[end][i], min);
				route->pop_back();
				(*isVisit)[i] = false;
			}
		}
	}

}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, sum, min = 10000000;
	cin >> n;
	vector<vector<int>> input(n + 1);
	for (auto& item : input)
		item.resize(n + 1);
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			cin >> input[i][j];
		}
	}
	vector<bool> isVisit(n + 1, false);
	vector<int> route;
	vector<int> ans;
	for (int i = 1; i < n + 1; ++i) {
		route.push_back(i);
		isVisit[i] = true;
		pathFinder(i, input, &isVisit, &route, 0, &min);
		route.pop_back();
		isVisit[i] = false;
	}
	
	
	cout << min << '\n';
	return 0;
}