// Write a program to count each word in a string
#include <iostream>
#include <string>

using namespace std;

void ReadString(string& line, const string& Message) {
	cout << Message << endl;
	getline(cin, line);

}

short CountWords(const string& line, const string& delim) {

	short counter = 0;
	bool inWord = false;
	for (short i = 0; i < line.length();) {

		if (line.substr(i, delim.length()) != delim) {
			if (!inWord) {
				counter++;
				inWord = true;
			}
			i++;
		}
		else {
			inWord = false;
			i += delim.length();
		}

	}
	return counter;

}
int main() {
	string line;
	ReadString(line, "Please enter a line to count its words:");
	cout << "Words count is " << CountWords(line, " ");

}