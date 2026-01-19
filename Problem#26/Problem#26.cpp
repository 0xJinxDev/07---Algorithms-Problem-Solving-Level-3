//Write a program to upper all letters in a string then lower all letters
#include <iostream>
#include <string>
#include <cctype>


using namespace std;

string ReadString(string Message) {
	string line;
	cout << Message << endl;
	getline(cin, line);
	return line;
}


void UpperAllLetters(string& line) {

	for (int i = 0; i < line.length(); i++) {
		line[i] = toupper(line[i]);
	}

}


void LowerAllLetters(string& line) {

	for (int i = 0; i < line.length(); i++) {
		line[i] = tolower(line[i]);
	}

}

int main() {

	string s = ReadString("Please enter your line");
	
	UpperAllLetters(s);
	cout << s<<endl;
	LowerAllLetters(s);
	cout << s << endl;

	return 0;
}