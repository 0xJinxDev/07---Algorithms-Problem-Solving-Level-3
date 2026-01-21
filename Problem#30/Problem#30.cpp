//Write a program to read string then count a specified char

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

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

short CountLetter(string& line, char c) {

	short counter = 0;
	
	for (short i = 0; i < line.length(); i++) {
		if (line[i] == c)
			counter++;
	}
	return counter;
}

int main() {
	string s;
	ReadString(s, "Please enter your line:");
	char c = ReadChar("Please enter the char you want to count");
	cout << "The character " << c << " repeated " << CountLetter(s,c)<<" times" << endl;

	return 0;
}