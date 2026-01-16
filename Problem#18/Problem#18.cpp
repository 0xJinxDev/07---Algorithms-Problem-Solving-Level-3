//Write a program to print the intersected numbers in two given matrices

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int RandomNumber(const int From, const int To) {

	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);

		}
	}

}

bool isNumberExistInArray(const int arr[3][3], const short Rows, const short Cols, const int  Number) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr[i][j] == Number) {
				return true;
			}
		}
	}
	return false;

}
bool isNumberPrintedBefore(const int arr[3][3], const short Rows, const short Cols, const int number) {

	for (short i = 0; i <= Rows; i++) {

		for (short j = 0; j <= Cols; j++) {

			if (i == Rows && j == Cols) {
				return false;
			}
			if (arr[i][j] == number) {
				return true;
			}
		}
	}
	return false;
}
void PrintIntersectedNumbers(const int Array1[3][3], const int Array2[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (isNumberExistInArray(Array2, Rows, Cols, Array1[i][j])&& !isNumberPrintedBefore(Array1,i,j,Array1[i][j])) {
				cout <<setw(3) << Array1[i][j];
			}
		}
	}
}
void PrintMatrixArray(const int arr[3][3], const short Rows, const short Cols) {

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

	int Array1[3][3], Array2[3][3];

	FillArrayWithRandomNumbers(Array1, 3, 3);
	FillArrayWithRandomNumbers(Array2, 3, 3);
	PrintMatrixArray(Array1, 3, 3);
	PrintMatrixArray(Array2, 3, 3);
	PrintIntersectedNumbers(Array1, Array2, 3, 3);

}