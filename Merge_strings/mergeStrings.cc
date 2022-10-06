
#include <iostream>
#include <string>
#include <cstring>
using std::string;
string mergeStrings(const string &a , const string &b){
	int c = a.length();
	int d = b.length();
	string x;
	int remain = 0;
	bool inLoop = false;
	/* Checking for the length of the string is equal */
	if (c == d) {
		for (int i = 0 ; i < c ; i++) {
			x += a.at(i);
			x += b.at(i);
		}
	}
	/* Checking if the length of the string a is greater than string b */
	else if (c > d) {
		for (int i = 0; i < d; i++) {
			x += a.at(i);
			x += b.at(i);
			remain = i;
			inLoop = true;

		}
		if (!inLoop) {
			x = x + a;
		} else {
			x = x + a.substr(remain + 1, c);
		}

	}
	/* Checking if the length of the string b is greater than string a */
	else {
		for (int i = 0; i < c; i++){
			x += a.at(i);
			x += b.at(i);
			remain = i;
			inLoop = true;
		}
		if (!inLoop) {
			x = x + b;
		} else {
			x = x + b.substr(remain + 1, d);
		}
	}
	return x;
}
