//Write a program to read string then split the string into vector
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ReadString(string& line, const string& Message) {
	cout << Message << endl;
	getline(cin, line);
	
}


void FillVectorWithWords(const string& line, vector <string>& vWords, const string& delim) {
	string word;
	for (short i = 0; i < line.length();) {

		if (line.substr(i, delim.length()) != delim) {

			word += line[i];
			i++;
		}
		else {
			if (!word.empty()) {

				vWords.push_back(word);
				word.clear();
			}
			i += delim.length();
		}


	}

	if (!word.empty()) {
		vWords.push_back(word);
	}

}

void PrintVector(const vector <string> &vWords) {

	for (const string& word : vWords) {
		cout << word << endl;
	}
}
int main() {
	string line;
	ReadString(line, "Please enter your line:");
	vector <string> vWords;
	FillVectorWithWords(line, vWords, " ");
	PrintVector(vWords);

	return 0;
}