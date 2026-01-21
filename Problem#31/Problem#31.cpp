//Write a program to count letters regardless the case

#include <iostream>
#include <string>
#include <cctype>


using namespace std;
enum enWhatToCount { SameCase = 0, All = 1 };


void ReadString(string& s, const string& Message) {

	cout << Message << endl;
	getline(cin, s);

}

char ReadChar(const string& Message) {

	char c;
	cout << Message << endl;
	cin >> c;
	return c;
}


char InvertChar(char c) {
	return isupper(c) ? tolower(c) : toupper(c);
}

short Count(const string& s, enWhatToCount WhatToCount,char c) {

	short counter = 0;

	for (short i = 0; i < s.length(); i++) {

		if (WhatToCount == enWhatToCount::All) {
			if (tolower(s[i]) == tolower(c)) {
				counter ++;
			}
		}
		if (WhatToCount == enWhatToCount::SameCase) {
			if (s[i] == c) {
				counter++;
			}
		}
	}

	return counter;

}
int main() {

	string s;
	ReadString(s, "Please enter your line:");
	char c = ReadChar("Please enter the letter you want to count:");
	cout << "The letter " << c << " or " << InvertChar(c) << " repeated " << Count(s,enWhatToCount::All,c)<<" times."<< endl;
	cout << "The letter " << c << " repeated " << Count(s, enWhatToCount::SameCase, c) << " times." << endl;
	return 0;
}

