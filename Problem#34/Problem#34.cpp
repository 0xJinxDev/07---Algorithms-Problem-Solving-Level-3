//Write a programt to read string then print al vowels

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
void PrintVowels(const string& s) {
	for (short i = 0; i < s.length(); i++) {
		if (isVowel(s[i]))
			cout << s[i] << " ";
	}
	cout << endl;

}
int main() {

	string s;
	ReadString(s, "Please enter your line to count vowels:");
	cout << "the vowles are: "<< endl;
	PrintVowels(s);
	return 0;
}