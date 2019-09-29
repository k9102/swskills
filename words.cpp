#include "pch.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int getInput(vector<string>& words) {
	int count = 0;
	string line;
	string token;

	getline(cin, line);
	stringstream ssCount(line);
	ssCount >> token;
	count = atoi(token.c_str());

	getline(cin, line);
	stringstream ss(line);
	for (int i = 0; i < count; i++) {
		ss >> token;
		words.push_back(token);
	}

	return count;
}

void solve() {
	int count = 0;
	int total_len = 0;
	vector<string> words;

	count = getInput(words);

	sort(words.begin(), words.end());

	string str;
	for (int i = 0; i < words.size(); i++)
	{
		if (i % 2 == 0)
			str = words[i] + str;
		else
			str = str + words[i];
	}

	cout <<  str[str.length() / 3];
}

int main() {
	solve();
	return 0;
}

/*
13
it was vacation time i found it lighted same way faintly and evenly

f
*/