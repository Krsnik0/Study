// https://www.acmicpc.net/problem/9012
// Written by JSH, Krsnik


//#define max(x, y) x > y ? x: y; 
//#define min(x, y) x > y ? y: x;
#define N 1000000
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   string str;
   int idx = 0, n, i;
   cin >> n;
   while (n-- > 0) {
	   cin >> str;
	   idx = 0;
	   for (i = 0; i < str.length(); ++i) {
		   if (str[i] == '(') {
			   if (idx == -1)
				   break;
			   else
				   ++idx;
		   }
		   else {
			   if (idx == -1)
				   break;
			   else
				   --idx;
		   }
	   }
	   if (idx == 0)
		   cout << "YES\n";
	   else
		   cout << "NO\n";
   }

   return 0;
}