//Write a program to remove punctuations from a stirng

#include <iostream>
#include <string>
#include <cctype>


using namespace std;

void ReadString(string& line, const string& Message) {
	cout << Message << endl;
	getline(cin, line);
}


void RemovePunctuations(string& line) {

	for (short i = 0; i < line.length(); i++) {

		if (ispunct(line[i])) {
			line.erase(i,1);
			i--;
		}
	}
}

int main() {
	string line;
	ReadString(line, "Please enter your line to remove punctuations:");
	RemovePunctuations(line);
	cout << line << endl;



	return 0;
}