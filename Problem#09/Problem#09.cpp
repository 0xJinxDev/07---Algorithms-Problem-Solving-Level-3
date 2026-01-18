//Write a program to print the middle row and the middle col of a matrix
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


int RandomNumber(const int From, const int To) {
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[3][3], const short Rows, const short Col) {

	for (short i = 0; i < Rows; i++) {

		for (short j = 0; j < Col; j++) {
			arr[i][j] = RandomNumber(1, 10);
		}
	}

}

void PrintMatrix(const int arr[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;

	}
	cout << endl;
}

void PrintMiddleRow(const int arr[3][3], const short Rows, const short Cols) {

	short MiddleRow = Rows / 2;

	for (short i = 0; i < Cols; i++) {

		cout << setw(3) << arr[MiddleRow][i];
	}
	cout << endl;
}

void PrintMiddleCol(const int arr[3][3], const short Rows, const short Cols) {
	short MiddleCol = Cols / 2;
	for (short i = 0; i < Rows; i++) {
		cout << setw(3) << arr[i][MiddleCol];
	}
	cout << endl;

}
int main() {

	int arr[3][3];

	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
	PrintMiddleCol(arr, 3, 3);
	PrintMiddleRow(arr, 3, 3);



	return 0;
}