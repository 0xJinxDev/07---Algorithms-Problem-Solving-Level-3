//Write a program to update client by his age

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct stClient {

	string name;
	int age;
	float balance;

};

void ReadString(string& line, const string Message) {
	cout << Message << endl;
	getline(cin, line);
}
void ReadInt(int& num, const string& Message) {
	cout << Message << endl;
	cin >> num;
}
void ReadFloat(float& f, const string& Message) {
	cout << Message << endl;
	cin >> f;
}
void WriteLinesToFiles(const string& FileName, const string& line, bool override = false) {

	fstream MyFile;

	MyFile.open(FileName, (override) ? (ios::out) : (ios::out | ios::app));

	if (MyFile.is_open()) {

		MyFile << line << endl;


		MyFile.close();
	}
}
void RecordToLine(stClient& Client, string& line) {
	line += Client.name + "/##/";
	line += to_string(Client.age) + "/##/";
	line += to_string(Client.balance);
}

void AddClient(stClient& Client) {
	char Flag = 'Y';
	string line;
	while (Flag == 'y' || Flag == 'Y') {
		ReadString(Client.name, "Please enter client name:");
		ReadInt(Client.age, "Please enter client age:");
		ReadFloat(Client.balance, "Please enter client balance:");
		RecordToLine(Client, line);
		//cout << line << endl;
		WriteLinesToFiles("Hamza.txt", line);
		cout << "Do you want to add another client? (y/n)";
		line.clear();
		cin >> Flag;
		cin.ignore();
	}
}

void FillStruct(short counter, stClient& Client, string& word, vector <stClient>& vClient) {
	switch (counter) {

	case 0:
		Client.name = word;
		break;
	case 1:
		Client.age = stoi(word);
		break;
	case 2:
		Client.balance = stof(word);
	}

	if (counter == 2) {
		vClient.push_back(Client);
	}
}
void LineToRecord(stClient& Client, const string& line, const string& Delim, vector <stClient>& vClients) {
	short counter = 0;
	string word;
	for (int i = 0; i < line.length();) {

		if (line.substr(i, Delim.length()) != Delim) {
			word += line[i];
			i++;
		}
		else {
			if (!word.empty()) {
				FillStruct(counter, Client, word, vClients);
				counter++;
				word.clear();
			}
			i += Delim.length();
		}
	}
	if (!word.empty()) {
		FillStruct(counter, Client, word, vClients);
	}
}
void ReadLines(const string& FileName, stClient& Client, vector <stClient>& vClients) {

	fstream MyFile;
	MyFile.open(FileName, ios::in);
	string line;
	if (MyFile.is_open()) {

		while (getline(MyFile, line)) {

			LineToRecord(Client, line, "/##/", vClients);
		}
	}
}


void ReadVector(const vector <stClient>& vClients) {

	for (const stClient& Client : vClients) {
		cout << Client.name << endl;
		cout << Client.age << endl;
		cout << Client.balance << endl;

	}

}
void ReadVector(const vector <stClient>& vClients, int age) {

	for (const stClient& Client : vClients) {

		if (Client.age == age) {
			cout << Client.name << endl;
			cout << Client.age << endl;
			cout << Client.balance << endl;
		}


	}

}
void ModifyVector(vector <stClient>& vClients, int age) {

	for (stClient& Client : vClients) {

		if (Client.age == age) {

			ReadString(Client.name, "Please enter client name:");
			ReadInt(Client.age, "Please enter client age:");
			ReadFloat(Client.balance, "Please enter client balance:");
		}


	}

}

void VectorToLine(const string& FileName, vector<stClient>& vClients) {
	string line;
	bool override = true;
	for (stClient& client : vClients) {
		
			RecordToLine(client, line);
			WriteLinesToFiles(FileName, line, override);
			line.clear();
			override = false;
			

	}

}

int main() {
	stClient Client;
	vector <stClient> vClients;

	int age;

	AddClient(Client);
	ReadLines("Hamza.txt", Client, vClients);


	ReadInt(age, "Please enter the age you want to update");
	cin.ignore();
	ModifyVector(vClients, age);
	VectorToLine("Hamza.txt", vClients);
	return 0;
}