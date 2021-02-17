#include <bits/stdc++.h>
using namespace std;

int main (void) {
	string input; char c[75];
	while (cin >> input) {
		if (input == "#") break;
		strcpy (c, input.c_str());
		if (next_permutation(c, c + input.size()))
			cout << c << endl;
		else
			cout << "No Successor" << endl;
	}
	return 0;
}