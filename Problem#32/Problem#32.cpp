//Write a program to check if a letter is vowel or not
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

char ReadChar(const string& Message) {

	char c;
	cout << Message << endl;
	cin >> c;
	return c;
}

bool isVowel(char c) {
	c  = tolower(c);
	return ((c == 'a') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'e'));
}

int main() {

	char c = ReadChar("Please enter the letter:");
	cout << (isVowel(c) ? "Vowel!\n" : "Not vowel!\n");
	return 0; 
}