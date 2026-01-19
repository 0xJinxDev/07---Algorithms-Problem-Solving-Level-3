//Write a program to upper first letter of each word


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



void UpperFirstLetter(string &line) {

	bool flag = true;


	for (int i = 0; i < line.length(); i++) {

		if (flag && line[i] != ' ') {
			line[i] = toupper(line[i]);
		}

		flag = line[i] == ' ' ? true : false;


	}

}
int main() {
	string line = ReadString("Please enter your line:");

	UpperFirstLetter(line);
	cout << line;
	return 0;
}