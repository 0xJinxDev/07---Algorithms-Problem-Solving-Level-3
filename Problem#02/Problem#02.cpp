//Write a program to sum each row in a matrix

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


int RowSum(const int arr[3][3], const short RowNumber, const short Cols) {

	int sum = 0;

	for (short j = 0; j < Cols; j++) {
		sum += arr[RowNumber][j];
	}

	return sum;

}

void PrintSum(const int arr[3][3],const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {

		cout << "The sum of row R " << i + 1 << " is " << RowSum(arr, i, Cols)<<endl;
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

int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];

	FillArrayWithRandomNumbers(arr, 3, 3);
	PrintArray(arr, 3, 3);
	PrintSum(arr,3,3);
	return 0;
}