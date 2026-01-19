//Write a program to read string then print first letter of each word

#include <iostream>
#include <string>


using namespace std;

string ReadString(string Message) {
	string line;
	cout << Message << endl;
	getline(cin, line);
	return line;
}

void PrintFirstLetter(string line) {

	bool flag = true;


	for (int i = 0; i < line.length(); i++) {

		if (flag && line[i] != ' ') {
			cout << line[i] << " ";
		}

		flag = line[i] == ' ' ? true : false;


	}

}
int main() {
	string line = ReadString("Please enter your line:");

	PrintFirstLetter(line);
	return 0;
}