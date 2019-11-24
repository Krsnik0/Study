// https://www.acmicpc.net/problem/10799
// Written by JSH, Krsnik

//#define max(x, y) x > y ? x: y; 
//#define min(x, y) x > y ? y: x;
#define N 1000000
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;


int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   string str;
   stack<int> stack;
   int cnt = 0, n, i;
   cin >> str;
   for (i = 0; i < str.length(); ++i) {
	   if (str[i] == '(')
		   stack.push(1);
	   else {
		   if (i > 0 && str[i - 1] == '(') {
			   stack.pop();
			   cnt += stack.size();
		   }
		   else {
			   cnt += 1;
			   stack.pop();
		   }
	   }
   }
   cout << cnt << '\n';

   return 0;
}