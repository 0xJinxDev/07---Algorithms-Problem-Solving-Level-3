//Write a program to sum each col in a matrix

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

			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintArray(const int arr[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(4) << arr[i][j];
		}
		cout << endl;

	}
	cout << endl;
}


int ColSum(const int arr[3][3], const short Rows, const short ColNumber) {
	int Sum = 0;
	for (short i = 0; i < Rows; i++) {
		Sum += arr[i][ColNumber];
	}
	return Sum;
}
void PrintColSum(const int arr[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Cols; i++) {

		cout << "The sum of col " << i + 1 << " is: " << ColSum(arr, Rows, i) << endl;
	}

}
int main() {

	srand((unsigned)time(NULL));
	int arr[3][3] = {};
	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintArray(arr, 3, 3);
	PrintColSum(arr,3,3);

	return 0;
}