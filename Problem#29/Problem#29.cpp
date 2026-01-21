//Write a program to count all letters, capital letters and small letters

#include <iostream>
#include <string>


using namespace std;

void ReadString(string& S, const string& Message) {
	cout << Message << endl;
	getline(cin, S);
}

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3};

short Count(string& S, enWhatToCount WhatToCount =  enWhatToCount::All) {

	short counter = 0;

	if (WhatToCount == enWhatToCount::All) {
		return S.length();
	}

	if (WhatToCount == enWhatToCount::SmallLetters) {
		for (short i = 0; i < S.length(); i++) {
			if (islower(S[i])) {
				counter++;
			}
		}
	}

	if (WhatToCount == enWhatToCount::CapitalLetters) {
		for (short i = 0; i < S.length(); i++) {
			if (isupper(S[i])) {
				counter++;
			}
		}
	}
	return counter;
}

int main() {
	string S;
	ReadString(S, "Please enter your line:");

	cout << "String Length = " << Count(S) << endl;
	cout << "Capital Letters = " << Count(S, enWhatToCount::CapitalLetters) << endl;
	cout << "Small Letters = " << Count(S, enWhatToCount::SmallLetters) << endl;
	return 0;
}