//Write a program to read clients file and show them on the screen

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct stClient {
	string name;
	int age;
	float balance;
};

void ReadString(string& line, const string& Message) {
	cout << Message << endl;
	getline(cin, line);
}
void ReadInt(int& i, const string& Message) {
	cout << Message << endl;
	cin >> i;
}
void ReadFloat(float& f, const string& Message) {
	cout << Message << endl;
	cin >> f;
}
void SaveToFile(const string& FileName, const string line) {

	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {

		MyFile << line << endl;
		MyFile.close();
	}

}

void RecordToLine(const stClient& Client, const string& Delim, string& line) {


	line += Client.name + Delim;
	line += to_string(Client.age) + Delim;
	line += to_string(Client.balance);


}
void AddClient(stClient &Client) {

	char Flag = 'Y';
	string line;
	while (Flag == 'y' || Flag == 'Y') {

		ReadString(Client.name, "Please enter client name:");
		ReadInt(Client.age, "Please enter client age:");
		ReadFloat(Client.balance, "Please enter client balance:");

		RecordToLine(Client, "/##/", line);
		SaveToFile("Hamza.txt", line);
		line.clear();
		cout << "Do you want to add another client?(y/n)\n";
		cin >> Flag;
		cin.ignore();

	}

}

void FillClient(const string &word,vector<stClient> &vClients,const short counter, stClient & Client) {
	
	switch (counter) {

	case 0:
		Client.name = word;
		break;
	case 1:
		Client.age = stoi(word);
		break;
	case 2:
		Client.balance = stof(word);
		break;
	}
	if (counter == 2)
	vClients.push_back(Client);
}

void LineToRecord(const string& line, const string & Delim,vector<stClient> & vClients, stClient & Client) {

	
	string word;
	short counter = 0;
	for (short i = 0; i < line.length();) {

		if (line.substr(i, Delim.length()) != Delim) {
			word += line[i];
			i++;
		}
		else {

			if (!word.empty()) {

				FillClient(word, vClients, counter, Client);
				counter++;
				word.clear();

			}

			i += Delim.length();
		}
	}

	if (!word.empty()) {

		FillClient(word, vClients, counter, Client);
		word.clear();

	}
}
void ReadClient(const string &FileName,vector<stClient> & vClients,stClient & Client) {

	fstream MyFile;
	string line;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		while (getline(MyFile, line)) {
			LineToRecord(line,"/##/",vClients,Client);
		}
		MyFile.close();
	}

}
void ReadVectorClients(const vector<stClient>& vClients) {

	cout << "Number of employees " << vClients.size() << endl;

	for (const stClient& Client : vClients) {

		cout << "Employee name: " << Client.name << endl;
		cout << "Employee age: " << Client.age << endl;
		cout << "Employee balance: " << Client.balance << endl;
	}


}
int main() {

	stClient Client;
	vector <stClient> vClients;
	AddClient(Client);
	ReadClient("Hamza.txt", vClients, Client);
	ReadVectorClients(vClients);
	return 0;
}