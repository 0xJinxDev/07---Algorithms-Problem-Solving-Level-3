//Write a program to sum a matrix

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


int main() {
	srand((unsigned)time(NULL));
	int arr[3][3] = {};
	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintArray(arr, 3, 3);
	
	cout << "The sum of the matrix is " << SumMatrix(arr, 3, 3) << endl;
	return 0;
}