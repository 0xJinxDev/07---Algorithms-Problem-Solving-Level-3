//Write a program to read char then print it
#include<iostream>
#include<cctype>
#include<string>
using namespace std;

char ReadChar(string Message) {
	cout << Message << endl;
	char c; 
	cin >> c;
	return c;
}

void InvertChar(char &c) {

	c = isupper(c) ? tolower(c) : toupper(c);
}

int main() {
	char c = ReadChar("Please enter a char to invert:");
	InvertChar(c);
	cout << c << endl;
	return 0;
}