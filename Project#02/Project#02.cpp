//Bank project #2

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const string FileName = "Clients.txt";
const string Delim = "/##/";

void PrintMainMenu();


struct stClient {
	string AccountNumber;
	string Name;
	int age;
	float balance;
	bool Delete = false;
};
enum enAction {
	ToPrintClients = 1, ToAddClient = 2, ToDeleteClient = 3, ToUpdateClient = 4,
	ToFindClient = 5, ToDoTransaction = 6, ToExit = 7
};
enum enTransactinoAction {
	ToDeposit = 1, ToWithdraw = 2, ToShowTotalBalance = 3, ToGoBackToMainMenu = 4
};

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
void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menu...";
	system("pause>0");
	PrintMainMenu();
}
void GoBackToTrasnaction()
{
	cout << "\n\nPress any key to go back to Transactions Menu...";
	system("pause>0");
	
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
	system("cls");
	cout << "=====================================================" << endl;
	cout << "[1] Show Client List." << endl;
	cout << "[2] Add New Client." << endl;
	cout << "[3] Delete Client." << endl;
	cout << "[4] Update Client Info." << endl;
	cout << "[5] Find Client." << endl;
	cout << "[6] Transactions." << endl;
	cout << "[7] Exit." << endl;
	cout << "=====================================================" << endl;
	cout << endl << endl;
}

void PrintClients(const vector <stClient>& vClients) {
	cout << "Total Number of Clients is: " << vClients.size() << endl;
	cout << left << setw(25) << "Account Number" << setw(25) << "Name" << setw(15) << "Age" << setw(15) << "Balance" << endl;
	for (const stClient& Client : vClients) {

		cout << left << setw(25) << Client.AccountNumber << setw(25) << Client.Name << setw(15) << Client.age << setw(15) << Client.balance << endl;
	}
	if (vClients.empty()) {
		cout << "No clients found.\n";
		return;
	}
}
void FindClient(string& ClientNumber, const vector <stClient>& vClients) {
	bool Found = false;
	cout << left << setw(25) << "Account Number" << setw(25) << "Name" << setw(15) << "Age" << setw(15) << "Balance" << endl;
	for (const stClient& Client : vClients) {
		if (ClientNumber == Client.AccountNumber) {
			cout << left << setw(25) << Client.AccountNumber << setw(25) << Client.Name << setw(15) << Client.age << setw(15) << Client.balance << endl;
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
stClient ReadClient(const vector <stClient>& vClients, bool Update = false) {
	stClient tmp;

	tmp.AccountNumber = ReadString("Please enter account number:");
	while (isRegistered(tmp.AccountNumber, vClients) && !Update) {
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
	bool NoRecords = true;
	for (stClient& c : vClients) {

		if (!c.Delete) {
			NoRecords = false;
			line = RecordToLine(c);
			SaveToFile(line, FirstRecord ? true : false);
			FirstRecord = false;
		}
	}
	if (NoRecords) {
		line.clear();
		SaveToFile(line, NoRecords);
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


void VectorToFile(vector <stClient>& vClients, enAction Action) {

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
			c = ReadClient(vClients, true);

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

void SearchForClient(const vector<stClient>& vClients) {
	string AccountNumber = ReadString("Please enter the account number you want to search for");
	FindClient(AccountNumber, vClients);

}

void AddClient(vector<stClient>& vClients) {
	stClient c = ReadClient(vClients);
	vClients.push_back(c);
	string line = RecordToLine(c);
	SaveToFile(line);
}

void ShowTransactionsMenu() {
	system("cls");
	cout << "=====================================================" << endl;
	cout << "[1] Deposit." << endl;
	cout << "[2] Withdraw." << endl;
	cout << "[3] Total Balance." << endl;
	cout << "[4] Go to Main Menu." << endl;
	cout << "=====================================================" << endl;
	cout << endl << endl;
}

void Deposit(vector <stClient>& vClients) {
	PrintClients(vClients);
	string AccountID = ReadString("Please enter account ID:");
	if (isRegistered(AccountID, vClients)) {
	FindClient(AccountID, vClients);
	int Amount = ReadInt("Please enter the amount you want to deposit:");
	
	for (stClient& c : vClients) {

		if (c.AccountNumber == AccountID) {
			c.balance += Amount;
			UpdateFile(vClients);
			cout << "Balance updated successfully!\n";
		}
	}


	}
	else {
		cout << "Client not found!\n";
	}
	GoBackToTrasnaction();
}
void Withdraw(vector <stClient>& vClients) {
	PrintClients(vClients);
	string AccountID = ReadString("Please enter account ID:");
	if (isRegistered(AccountID, vClients)) {
		FindClient(AccountID, vClients);
		int Amount = ReadInt("Please enter the amount you want to withdraw:");

		for (stClient& c : vClients) {

			if (c.AccountNumber == AccountID) {
				c.balance -= Amount;
				UpdateFile(vClients);
				cout << "Balance updated successfully!\n";
			}
		}


	}
	else {
		cout << "Client not found!\n";
	}
	GoBackToTrasnaction();
}
int TotalBalances(vector <stClient>& vClients) {
	PrintClients(vClients);
	
	int TotalBalance;


		for (stClient& c : vClients) {

			
				TotalBalance = c.balance;
				
			
		}


	
	
	return TotalBalance;
}
void ChoiceTransaction(vector <stClient>& vClients, enTransactinoAction Action) {
	switch (Action) {
	case ToDeposit: system("cls"); Deposit(vClients); UpdateVector(vClients);break ;
	case ToWithdraw: system("cls"); Withdraw(vClients); UpdateVector(vClients); break;
	case ToShowTotalBalance: system("cls"); cout <<TotalBalances(vClients)<<endl; GoBackToTrasnaction(); break;
	}
}
void Transactions(vector <stClient>& vClients) {
	enTransactinoAction Action;
	do {
		ShowTransactionsMenu();
		
		Action = (enTransactinoAction)ReadInt("Choose what do you want to do? [1 to 4]?");
		ChoiceTransaction(vClients, Action);
	} while (Action != ToGoBackToMainMenu);
}

void Choice(vector<stClient>& vClients, enAction Action) {
	switch (Action) {
	case ToPrintClients:   system("cls");  PrintClients(vClients); GoBackToMainMenue(); break;
	case ToAddClient:      system("cls"); AddClient(vClients); GoBackToMainMenue(); break;
	case ToDeleteClient:   system("cls"); Deletion(vClients); GoBackToMainMenue(); break;
	case ToUpdateClient:   system("cls"); UpdateClient(vClients); GoBackToMainMenue(); break;
	case ToFindClient:     system("cls"); SearchForClient(vClients); GoBackToMainMenue(); break;
	case ToDoTransaction:  system("cls"); Transactions(vClients); break;
	case ToExit:           break;
	default:               cout << "Please enter from 1 to 7." << endl; break;
	}
}


int main() {

	stClient Client;
	vector <stClient> vClients;
	enAction Action;
	UpdateVector(vClients);
	do {
		PrintMainMenu();
		Action = (enAction)ReadInt("Choose what do you want to do? [1 to 7]?");
		Choice(vClients, Action);

	} while (Action != ToExit);


	return 0;
}