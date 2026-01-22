//Write a program to convert line into a record

#include <iostream>
#include <string>

using namespace std;


struct stClient {
	string name;
	short age;
	float salary;
	float balance;
};


void FillClient(short item, stClient& Client, const string& word) {

	switch (item) {

	case 0:
		Client.name = word;
		break;
	case 1:
		Client.age = stoi(word);
		break;
	case 2:
		Client.salary = stof(word);
		break;
	case 3:
		Client.balance = stof(word);
		break;	
	}
}
void LineToRecord(stClient& Client, const string& line, const string& Delim) {
	
	string word;
	int counter = 0;
	for (short i = 0; i < line.length();) {

		if (line.substr(i, Delim.length()) != Delim) {

			word += line[i];
			i++;

		}
		else {
			if (!word.empty()) {
				FillClient(counter, Client, word);
				counter++;
				word.clear();
			}
			i += Delim.length();
		}

	}
	if (!word.empty()) {
		FillClient(counter, Client, word);
	}
}

int main() {
	stClient FirstClient;
	string line = "Hamza/##/25/##/1000/##/5000";
	
	LineToRecord(FirstClient, line, "/##/");

	cout << FirstClient.name << endl;
	cout << FirstClient.age << endl;
	cout << FirstClient.salary << endl;
	cout << FirstClient.balance << endl;

	return 0;
}