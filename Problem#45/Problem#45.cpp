//Write a program to read a client data record and then convert it into line

#include <iostream>
#include <string>

using namespace std;


struct stClient {
	string name;
	float age;
	float salary;
	float balance;
};

void ConvertDataToLine(string& line, const stClient& Client,const string & Seperator) {

	line.clear();
	line += Client.name + Seperator;
	line += to_string(Client.age) + Seperator;
	line += to_string(Client.salary) + Seperator;
	line += to_string(Client.balance) ;
}
int main() {

	string line;
	stClient FirstClient;
	FirstClient.name = "Hamza";
	FirstClient.age = 25;
	FirstClient.salary = 1000;
	FirstClient.balance = 1000;

	ConvertDataToLine(line, FirstClient, "/##/");
	cout << line;



	return 0;
}