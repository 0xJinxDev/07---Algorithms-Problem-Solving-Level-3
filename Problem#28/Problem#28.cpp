//Wtie a prgoram to invert all string letters' case

#include<iostream>
#include<cctype>
#include<string>
using namespace std;

string ReadString(string Message) {
	cout << Message << endl;
	string s;
	getline(cin, s);
	return s;
}

void InvertChar(char& c) {

	c = isupper(c) ? tolower(c) : toupper(c);
}

void InvertString(string& s) {

	for (int i = 0; i < s.length(); i++) {
		InvertChar(s[i]);
	}

}
int main() {
	string s = ReadString("Please enter a string to invert:");
	InvertString(s);
	cout << s << endl;
	return 0;
}