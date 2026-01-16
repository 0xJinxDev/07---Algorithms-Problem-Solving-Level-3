//Write a program to sum each row in a matrix then store the sums into an array

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int RandomNumber(const int From,const int To) {

	return rand() % (To - From + 1) + From;
}



void FillArrayWithRandomNumbers(int arr[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {

			arr[i][j] = RandomNumber(1, 20);
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
}

void PrintArray(int arr[3], short Length) {

	for (short i = 0; i < Length; i++) {

		cout << setw(3) << arr[i];
	}
	cout << endl;
}
int RowSum(int arr[3][3], const short RowNumber, const short Cols) {

	int sum = 0;

	for (short i = 0; i < Cols; i++) {
		sum += arr[RowNumber][i];
	}

	return sum;
}


void AddSumToArray(int arr[3][3], const short Rows, const int Cols, int array[3]) {

	for (int i = 0; i < Rows; i++) {
		array[i] = RowSum(arr, i, Cols);
	}
}



int main() {

	int arr[3][3];
	int sum[3];
	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintMatrixArray(arr, 3, 3);
	AddSumToArray(arr, 3, 3, sum);
	PrintArray(sum, 3);



	return 0;
}