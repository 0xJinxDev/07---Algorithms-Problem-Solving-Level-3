//Write a program to join a array of string of strings then put it into a single string with separators
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ReadString(string& line, const string& Message) {
	cout << Message << endl;
	getline(cin, line);
}
void FillVector(vector <string>& vWords) {

	char Flag = 'y';
	string word;

	while (Flag == 'Y' || Flag == 'y') {

		ReadString(word, "Please enter your word:");
		vWords.push_back(word);
		cout << "Do you want to add another word ?(y/n) \n";
		cin >> Flag;
		cin.ignore();
	}
}

void PrintVector(const vector <string>& vWords) {

	for (const string& word : vWords) {
		cout << word << endl;
	}

}

void JoinString(string& line, const string& Delim, const vector <string>& vWords) {

	line.clear();
	bool isFirst = true;
	for (const string& word : vWords) {
		if (!isFirst)
			line += Delim;
		line += word;
		isFirst = false;
	}
}

void JoinString(string& line, const string& Delim, const string arr[], const short Length) {

	line.clear();
	bool isFirst = true;
	for (short i = 0; i < Length; i++) {

		if (!isFirst)
			line += Delim;
		line += arr[i];
		isFirst = false;

	}
}

int main() {
	vector <string> vWords;
	string line;
	FillVector(vWords);
	string arr[3] = { "Hamza","Hamza","Hamza" };
	PrintVector(vWords);
	JoinString(line, "-", vWords);

	cout << "The vector after joining:" <<endl <<line << endl;
	JoinString(line, "-", arr,3);
	cout << "The array after joining:" << endl << line << endl;

	return 0;
}