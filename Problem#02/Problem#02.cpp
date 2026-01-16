//Write a program to sum each row in a matrix

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {

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
			cout << setw(3)<<arr[i][j];
		}
		cout << endl;
	}
}

int RowSum(const int arr[3][3], const short  RowNumber, const short  Cols) {
	int Sum = 0;

	for (short i = 0; i < Cols; i++) {
		Sum += arr[RowNumber][i];
	}
	return Sum;
}

void PrintRowSum(const int arr[3][3], const short  Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		cout << "The sum of row " << i + 1 << "is " <<RowSum(arr, i, Cols) <<endl;
	}
}
int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];
	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintArray(arr,3,3);

	PrintRowSum(arr, 3, 3);


	return 0;
}