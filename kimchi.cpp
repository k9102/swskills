#include "pch.h"
#include <iostream>
#include <map>

using namespace std;

map<int, long long> c;
long long int kimchi(int n) {
	if (c.find(n) != end(c))
	{
		return c[n];
	}
	
	long long ret;
	if (n <= 3)	ret = 1;
	else if (n % 3 == 0) ret =  3 * kimchi(n - 1) - 2 * kimchi(n - 2) - kimchi(n - 3);
	else if (n % 3 == 1) ret =  3 * kimchi(n - 1) - 2 * kimchi(n - 2) + kimchi(n - 3);
	else ret = 2 * kimchi(n - 1) - 2 * kimchi(n - 2) + kimchi(n - 3);

	c[n] = ret;
	return ret;
}

int main(void) {
	int T;
	cin >> T;
	cout << kimchi(T);
	return 0;
}