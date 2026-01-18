//Write a program to find the min/max element of a matrix
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


int RandomNumber(const int From, const int To) {

	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[3][3],const short Rows,const short Cols) {

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

int MaxNumberInMatrix(const int arr[3][3], const short Rows, const short Cols) {
	int maxNumber = arr[0][0];

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			maxNumber = (arr[i][j] > maxNumber) ? arr[i][j] : maxNumber;
		}
	}
	return maxNumber;
}

int MinNumberInMatrix(const int arr[3][3], const short Rows, const short Cols) {
	int minNumber = arr[0][0];

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			minNumber = (arr[i][j] < minNumber) ? arr[i][j] : minNumber;
		}
	}
	return minNumber;
}

int main() {
	srand((unsigned)time(NULL));
	int arr[3][3] = {};
	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintArray(arr, 3, 3);

	cout << MaxNumberInMatrix(arr,3,3) << endl;
	cout << MinNumberInMatrix(arr, 3, 3) << endl;

}