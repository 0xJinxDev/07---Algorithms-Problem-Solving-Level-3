// Wite a program to check if two matrices are equal

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

void PrintArray(const int arr[3][3], const short Rows, const short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {

			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
}

int SumMatrix(const int arr[3][3], const short Rows, const short Cols) {

	int Sum = 0;

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			Sum += arr[i][j];
		}
	}

	return Sum;
}

bool AreEqualMatrcies(const int arr1[3][3],  const int arr2[3][3], const short Rows, const short Cols) {

	return SumMatrix(arr1, Rows, Cols) == SumMatrix(arr2, Rows, Cols);
}

int main() {
	srand((unsigned)time(NULL));
	int arr[3][3] = {}, arr2[3][3] = {};
	FillArrayWithRandomNumbers(arr, 3, 3);
	FillArrayWithRandomNumbers(arr2, 3, 3);
	PrintArray(arr, 3, 3);
	PrintArray(arr2, 3, 3);

	if (AreEqualMatrcies(arr, arr2, 3, 3)) {
		cout << "Equal\n";
	}
	else {
		cout << "Not equal\n";
	}
	cout << "The sum of the matrix 1 is " << SumMatrix(arr, 3, 3) << endl;
	cout << "The sum of the matrix 2 is " << SumMatrix(arr2, 3, 3) << endl;
	return 0;
}