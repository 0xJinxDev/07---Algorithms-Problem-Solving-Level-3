//Write a program to ask the user to enter clients and save them into a file
#include <iostream>
#include <string>
#include <fstream>

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
void AddClient() {

	stClient Client;
	char Flag = 'Y';
	string line;
	while (Flag == 'y' || Flag == 'Y') {

		ReadString(Client.name, "Please enter client name:");
		ReadInt(Client.age, "Please enter client age:");
		ReadFloat(Client.balance, "Please enter client balance:");

		RecordToLine(Client,"/##/",line);
		SaveToFile("Hamza.txt", line);
		line.clear();
		cout << "Do you want to add another client?(y/n)\n";
		cin >> Flag;
		cin.ignore();

	}

}

int main() {

	AddClient();

	return 0;
}