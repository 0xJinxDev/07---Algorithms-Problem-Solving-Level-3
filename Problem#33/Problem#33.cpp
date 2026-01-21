//Write a program to count all vowels in a string

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void ReadString(string& s, const string& Message) {

	cout << Message << endl;

	getline(cin, s);
}

bool isVowel(char c) {
	c = tolower(c);
	return ((c == 'a') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'e'));
}
short CountVowels(const string& s) {
	short counter = 0;
	for (short i = 0; i < s.length(); i++) {
		if (isVowel(s[i]))
			counter++;
	}

	return counter;
}
int main() {

	string s;
	ReadString(s, "Please enter your line to count vowels:");
	cout << "The count of vowels is: " << CountVowels(s) << endl;
	return 0;
}