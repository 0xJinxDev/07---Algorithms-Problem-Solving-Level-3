//Write a program to sum each col in a matrix then store the sums into an array

#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;

int RandomNumber(const int From, const int To) {

	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {

			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(const int arr[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {

			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int SumCol(const int arr[3][3], const short Rows, const short ColNumber) {
	int Sum = 0;

	for (short i = 0; i < Rows; i++) {
		Sum += arr[i][ColNumber];
	}

	return Sum;
}
void FillArrayWithSum( int Sum[3], const int arr[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		Sum[i] = SumCol(arr, Rows, i);
	}

}
void PrintArray(const int Sum[3], const short Length) {

	for (short i = 0; i < Length; i++) {
		cout << setw(4) << Sum[i];
	}
	cout << endl;
}
int main() {

	int arr[3][3] = {};
	int Sum[3] = {};
	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
	FillArrayWithSum(Sum, arr, 3, 3);
	PrintArray(Sum, 3);


	return 0;
}