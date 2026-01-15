//Write a program to fill 3x3 array with random numbers

#include<iostream>
#include<ctime>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {

	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[3][3], short Rows, short Cols) {

	for (short i = 0; i < Rows; i++) {

		for (short j = 0; j < Cols; j++) {

			arr[i][j] = RandomNumber(0, 10);
		}
	}

}

void PrintArray(const int arr[3][3], short Rows, short Cols) {

	for (short i = 0; i < Rows; i++) {

		for (short j = 0; j < Cols; j++) {

			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}

}
int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];

	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintArray(arr, 3, 3);

}