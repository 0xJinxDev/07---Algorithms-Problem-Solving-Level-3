// Write a program to print the intersected numbers in two given matrices

#include <iostream>
#include <ctime>
#include <iomanip>

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

bool isNumberExistInArray(const int arr[3][3],const short Rows,const  short Cols, const int Number) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr[i][j] == Number)
				return true;
		}
	}
	return false;
}

bool isNumberPrintedBefore(const int arr[3][3],short CurrentRow, short CurrentCol,short Rows, short Cols,int Number) {

	for (short i = 0; i <= CurrentRow; i++) {

		for (short j = 0; j < Cols; j++) {

			if (i == CurrentRow && j == CurrentCol)
				return false;

			if (arr[i][j] == Number)
				return true;
		}
	}
	return false;
}

void PrintIntersectedNumbers(const int Array1[3][3],
	const int Array2[3][3],
	short Rows, short Cols) {

	cout << "Intersected Numbers:\n";

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {

			if (isNumberExistInArray(Array2, Rows, Cols, Array1[i][j]) &&
				!isNumberPrintedBefore(Array1, i, j, Rows, Cols, Array1[i][j])) {

				cout << setw(3) << Array1[i][j];
			}
		}
	}
	cout << endl;
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

	const short Rows = 3;
	const short Cols = 3;

	int Array1[3][3], Array2[3][3];

	FillArrayWithRandomNumbers(Array1, Rows, Cols);
	FillArrayWithRandomNumbers(Array2, Rows, Cols);

	cout << "Matrix 1:\n";
	PrintMatrixArray(Array1, Rows, Cols);

	cout << "Matrix 2:\n";
	PrintMatrixArray(Array2, Rows, Cols);

	PrintIntersectedNumbers(Array1, Array2, Rows, Cols);

	return 0;
}
