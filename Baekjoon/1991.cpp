// https://www.acmicpc.net/problem/1991
// Written by JSH, Krsnik

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

void preorder(vector<pair<int, int>> tree) {
	deque<int> stack;
	int x;
	stack.push_back(0);
	while (!stack.empty()) {
		x = stack.back();
		stack.pop_back();
		cout << (char)(x + 'A');
		if (tree[x].second != -1)
			stack.push_back(tree[x].second);
		if (tree[x].first != -1)
			stack.push_back(tree[x].first);
	}
	cout << '\n';
}

void inorder(vector<pair<int, int>> tree) {
	deque<int> stack;
	vector<bool> isVisit(tree.size(), false);
	int x;
	stack.push_back(0);
	isVisit[0] = true;
	while (!stack.empty()) {
		x = stack.back();
		if (tree[x].first != -1) {
			if (!isVisit[tree[x].first]) {
				stack.push_back(tree[x].first);
				isVisit[tree[x].first] = true;
				continue;
			}
		}
		cout << (char)(x + 'A');
		stack.pop_back();
		if (tree[x].second != -1) {
			if (!isVisit[tree[x].second]) {
				stack.push_back(tree[x].second);
				isVisit[tree[x].second] = true;
			}
		}
	}
	cout << '\n';
}

void postorder(vector<pair<int, int>> tree) {
	deque<int> stack;
	vector<bool> isVisit(tree.size(), false);
	int x;
	stack.push_back(0);
	isVisit[0] = true;
	while (!stack.empty()) {
		x = stack.back();
		if (tree[x].first != -1) {
			if (!isVisit[tree[x].first]) {
				stack.push_back(tree[x].first);
				isVisit[tree[x].first] = true;
				continue;
			}
		}
		if (tree[x].second != -1) {
			if (!isVisit[tree[x].second]) {
				stack.push_back(tree[x].second);
				isVisit[tree[x].second] = true;
				continue;
			}
		}
		cout << (char)(x + 'A');
		stack.pop_back();
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	char node, left, right;
	cin >> n;
	vector<pair<int, int>> tree(n);
	while (n--) {
		cin >> node >> left >> right;
		pair<int, int> p;
		p.first = (left != '.' ? left - 'A' : -1);
		p.second = (right != '.' ? right - 'A' : -1);
		tree[node - 'A'] = p;
	}
	preorder(tree);	
	inorder(tree);
	postorder(tree);

	return 0;
}