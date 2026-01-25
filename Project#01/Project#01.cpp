//Bank project #1

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const string FileName = "Clients.txt";
const string Delim = "/##/";


struct stClient {
	string AccountNumber;
	string Name;
	int age;
	float balance;
	bool Delete = false; 
};
enum enAction { ToPrintClients = 1, ToAddClient = 2, ToDeleteClient = 3, ToUpdateClient = 4, ToFindClient = 5, ToExit = 6 };

string ReadString(const string& Message) {
	cout << Message << endl;
	string line;
	getline(cin, line);
	return line;
}
int ReadInt(const string& Message) {
	cout << Message << endl;
	int num;
	cin >> num;
	cin.ignore();
	return num;
}
float ReadFloat(const string& Message) {
	cout << Message << endl;
	float f;
	cin >> f;
	cin.ignore();
	return f;
}
string RecordToLine(stClient& c) {
	string line;
	line += c.AccountNumber + Delim;
	line += c.Name + Delim;
	line += to_string(c.age) + Delim;
	line += to_string(c.balance);
	return line;
}
void SaveToFile(const string& line, bool overwrite = false) {
	fstream MyFile;
	MyFile.open(FileName, overwrite ? ios::out : ios::out | ios::app);
	if (MyFile.is_open()) {

		MyFile << line << endl;
		MyFile.close();
	}
	else {
		cout << "Error opening the file." << endl;
		return;
	}
}

void PrintMainMenu() {
	
	cout << "=====================================================" << endl;
	cout << "[1] Show Client List." << endl;
	cout << "[2] Add New Client." << endl;
	cout << "[3] Delete Client." << endl;
	cout << "[4] Update Client Info." << endl;
	cout << "[5] Find Client." << endl;
	cout << "[6] Exit." << endl;
	cout << "=====================================================" << endl;
	cout << endl << endl;
}

void PrintClients(const vector <stClient>& vClients) {
	cout << "Total Number of Clients is: " << vClients.size()<<endl;
	cout <<left<< setw(15) << "|Account Number|" << setw(15) << "|Name|" << setw(10) << "|Age|" << setw(15) << "|Balance|" << endl;
	for (const stClient& Client : vClients) {

		cout <<left<< setw(15) << Client.AccountNumber << setw(15) << Client.Name << setw(10) << Client.age << setw(15) << Client.balance << endl;
	}
	if (vClients.empty()) {
		cout << "No clients found.\n";
		return;
	}
}
void FindClient(string &ClientNumber, const vector <stClient> &vClients) {
	bool Found = false;
	cout << left << setw(4) << "|Account Number|" << setw(7) << "|Name|" << setw(3) << "|Age|" << setw(5) << "|Balance|" << endl;
	for (const stClient& Client : vClients) {
		if (ClientNumber == Client.AccountNumber) {
			cout << left << setw(4) << Client.AccountNumber << setw(7) << Client.Name << setw(3) << Client.age << setw(5) << Client.balance << endl;
			Found = true;
		}
	}

	if (!Found) {
		cout << "Client not found!\n";
	}
}
bool isRegistered(const string& AccountNumber, const vector<stClient>& vClients) {
	for (const stClient& c : vClients) {
		if (AccountNumber == c.AccountNumber)
			return true;
	}
	return false;
}
stClient ReadClient(const vector <stClient> & vClients,bool Update = false) {
	stClient tmp;

	tmp.AccountNumber = ReadString("Please enter account number:");
	while (isRegistered(tmp.AccountNumber, vClients)&&!Update) {
		cout << "The account already exists.\n";
		tmp.AccountNumber = ReadString("Please enter account number:");
	}
	tmp.Name = ReadString("Please enter client's name:");
	tmp.age = ReadInt("Please enter client's age:");
	tmp.balance = ReadFloat("Please enter client's balance:");
	return tmp;
}


void DeleteClient(vector <stClient>& vClients) {
	string line;
	bool FirstRecord = true;
	for (stClient& c : vClients) {

		if (!c.Delete) {
			line = RecordToLine(c);
			SaveToFile(line, FirstRecord ?true: false);
			FirstRecord = false;
		}
	}
}
void UpdateFile(vector<stClient>& vClients) {
	string line;
	bool FirstRecord = true;
	for (stClient& c : vClients) {
		line = RecordToLine(c);
		SaveToFile(line, FirstRecord ? true : false);
		FirstRecord = false;
	}
}
void MarkToBeDeleted(string& AccountNumber, vector <stClient>& vClients) {

	for (stClient& c : vClients) {
		if (AccountNumber == c.AccountNumber) {
			c.Delete = true;
		}
	}
}

void FillClient(const string& word, vector<stClient>& vClients, const short counter, stClient& c) {
	switch (counter) {
	case 0: c.AccountNumber = word; break;
	case 1: c.Name = word; break;
	case 2: c.age = stoi(word); break;
	case 3: c.balance = stof(word); break;
	}
	if (counter == 3)
		vClients.push_back(c);
}

void LineToRecord(const string& line, vector<stClient>& vClients) {
	string word;
	short counter = 0;
	stClient tmp;

	for (int i = 0; i < line.length();) {
		if (line.substr(i, Delim.length()) != Delim) {
			word += line[i];
			i++;
		}
		else {
			if (!word.empty()) {
				FillClient(word, vClients, counter, tmp);
				counter++; 
				word.clear();
			}
			i += Delim.length();
		}
	}

	if (!word.empty()) {
		FillClient(word, vClients, counter, tmp);
	}
}


void UpdateVector(vector <stClient>& vClients) {
	vClients.clear();
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	string line;
	if (MyFile.is_open()) {

		while (getline(MyFile, line)) {

			LineToRecord(line, vClients);
		}

		MyFile.close();
	}

}


void VectorToFile(vector <stClient>& vClients,enAction Action) {

	switch (Action) {

	case ToDeleteClient: DeleteClient(vClients); cout << "Client Deleted successfully!\n"; UpdateVector(vClients); break;
	case ToUpdateClient: UpdateFile(vClients); cout << "Client Updated Successfully~\n"; UpdateVector(vClients); break;
	}


}

void Deletion(vector <stClient>& vClients) {
	PrintClients(vClients);
	char Flag;
	string AccountNumber;
	cout << "Please enter the account number you want to delete:" << endl;
	getline(cin, AccountNumber);
	FindClient(AccountNumber, vClients);
	if (isRegistered(AccountNumber, vClients)) {
		cout << "Are you sure you want to delete this account?(y/n)" << endl;
		cin >> Flag;
		cin.ignore();
		if (Flag == 'Y' || Flag == 'y') {
			MarkToBeDeleted(AccountNumber, vClients);
			VectorToFile(vClients, ToDeleteClient);
		}
	}
	else {
		cout << "Client not found!\n";
	}

	PrintClients(vClients);

}
void UpdateClientInfo(const string& AccountNumber, vector<stClient>& vClients) {

	for (stClient& c : vClients) {

		if (c.AccountNumber == AccountNumber) {
			c = ReadClient(vClients,true);

		}
	}
}
void UpdateClient(vector <stClient>& vClients) {
	PrintClients(vClients);
	char Flag;
	string AccountNumber;
	cout << "Please enter the account number you want to update:" << endl;
	getline(cin, AccountNumber);
	FindClient(AccountNumber, vClients);
	if (isRegistered(AccountNumber, vClients)) {
		cout << "Are you sure you want to update this account?(y/n)" << endl;
		cin >> Flag;
		cin.ignore();
		if (Flag == 'Y' || Flag == 'y') {
			UpdateClientInfo(AccountNumber, vClients);

			VectorToFile(vClients, ToUpdateClient);
		}
	}
	PrintClients(vClients);

}

void SearchForClient(const vector<stClient> &vClients) {
	string AccountNumber = ReadString("Please enter the account number you want to search for");
	FindClient(AccountNumber, vClients);

}

void AddClient(vector<stClient>& vClients) {
	stClient c = ReadClient(vClients);
	vClients.push_back(c);
	string line = RecordToLine(c);
	SaveToFile(line);
}


void Choice(vector<stClient>& vClients, enAction Action) {
	switch (Action) {
	case ToPrintClients:   PrintClients(vClients); break;
	case ToAddClient:      AddClient(vClients); break;
	case ToDeleteClient:   Deletion(vClients); break;
	case ToUpdateClient:   UpdateClient(vClients); break;
	case ToFindClient:     SearchForClient(vClients); break;
	case ToExit:           break;
	default:               cout << "Please enter from 1 to 6." << endl; break;
	}
}


int main() {
	stClient Client;
	vector <stClient> vClients;
	enAction Action;
	UpdateVector(vClients);
	do {
		PrintMainMenu();
		Action = (enAction)ReadInt("Choose what do you want to do? [1 to 6]?");
		Choice(vClients, Action);
	
	} while (Action != ToExit);

	return 0;
}