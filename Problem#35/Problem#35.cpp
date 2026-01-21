//Write a program to read string then print each word of this string
#include <iostream>
#include <string>

using namespace std;

void ReadString(string& s, const string& Message) {

	cout << Message << endl;
	getline(cin, s);

}


void PrintWords(const string& line, const string & Delim) {
	
	string word; 

	for (short i = 0; i < line.length();)
	{
		if (line.substr(i, Delim.length()) != Delim) {
			word += line[i];
			i++;
		}
		else {
			if (!word.empty()){
				cout << word << endl;
				word.clear();
			}
			i += Delim.length();

		}

	}
	if (!word.empty()) {
		cout << word <<endl;
	}
}

int main() {

	string s;
	ReadString(s, "Please enter line:");
	PrintWords(s," - ");

	return 0;
}