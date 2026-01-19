//Write a program to lower first letter of each word


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



void LowerFirstLetter(string& line) {

	bool flag = true;


	for (int i = 0; i < line.length(); i++) {

		if (flag && line[i] != ' ') {
			line[i] = tolower(line[i]);
		}

		flag = line[i] == ' ' ? true : false;


	}

}
int main() {
	string line = ReadString("Please enter your line:");

	LowerFirstLetter(line);
	cout << line;
	return 0;
}