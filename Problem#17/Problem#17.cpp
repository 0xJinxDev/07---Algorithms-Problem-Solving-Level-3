//Write a program to check if number exists in a matrix
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

int RandomNumber(const int From,const int To) {
	return rand() % (To - From + 1) + From;
}


int ReadNumber(string Message) {
	int Number = 0;

	cout << Message;
	cin >> Number;
	return Number;
}
void FillArrayWithRandomNumbers(int arr[3][3], const short Rows,const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

bool isNumberExistInArray(const int arr[3][3],const short Rows, const short Cols,const int Number) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr[i][j] == Number)
				return true;
		}
	}
	return false;
}


void PrintMatrixArray(const int arr[3][3], short Rows, short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}


int main() {
	srand((unsigned)time(NULL));
	int arr[3][3] = {},Number;
	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintMatrixArray(arr, 3, 3);
	Number = ReadNumber("Please enter the number to check:\n");
	cout << (isNumberExistInArray(arr, 3, 3, Number) ? "Exists!\n" : "Does not exist!\n");

	return 0;
}