#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	char a[101];
	while (fgets(a, 101, stdin))
		printf("%s", a);
	
	return 0;
}