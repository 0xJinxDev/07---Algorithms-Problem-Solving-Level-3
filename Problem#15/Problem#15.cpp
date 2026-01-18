//Write a program to count a given number in a matrix

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

int RandomNumber(const int From, const int To) {
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintArray(const int arr[3][3], const short Rows, const short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}

	cout << endl;
}

int ReadNumber(string Message) {
	int number = 0;
	cout << Message;
	cin >> number;

	return number;
}

int CountNumber(const int arr[3][3], const short Rows, const short Cols, const int Number) {

	
	int counter = 0;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr[i][j] == Number) {
				counter++;
			}
		}
	}
	return counter;
}
int main() {

	int arr[3][3] = {}, Number;
	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintArray(arr, 3, 3);
	Number = ReadNumber("Please enter the number you want to count:\n");
	cout <<"The number "<<Number <<" repeated "<< CountNumber(arr, 3, 3, Number)<< " times.\n";

	return 0;
}