//Write a program to read string then reverse its words
#include <iostream>
#include <string>

using namespace std;

void ReadString(string & line, const string& Message) {

	cout << Message << endl;
	getline(cin, line);
}
void ReverseWords(string& line, const string & Delim) {
	string temp;
	string word;
	for (int i = line.length() - 1; i >= 0; i--) {
		temp += line[i];
	}
	line.clear();
	for (int i = 0; i < temp.length();) {
		if (temp.substr(i, Delim.length()) != Delim) {

			word += temp[i];
			i++;
		}
		else {
			if (!word.empty()) {
				for (int j = word.length()-1; j >= 0; j--) {
					line += word[j];
				}
				line += Delim;
				word.clear();
			}
			i += Delim.length();
		}	
	}
	if (!word.empty()) {
		for (int i = word.length() - 1; i >= 0; i--) {
			line += word[i];
		}
	}
}
int main() {
	string line;
	ReadString(line, "Please enter your line:");
	ReverseWords(line, " ");
	cout << line;
	return 0;
}