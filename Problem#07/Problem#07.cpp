//Write a program to fill a 3x3 matrix with ordered numbers and print it, then transpose matrix and print it

#include <iostream>
#include <iomanip>

using namespace std;
void FillArrayWithOrderedNumbers(int arr[3][3], const short Rows, const short Cols) {

	int Counter = 0;

	for (short i = 0; i < Rows; i++) {

		for (short j = 0; j < Cols; j++) {

			Counter++;
			arr[i][j] = Counter;
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

void transposeMatrix(const int arr1[3][3], int arr2[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {

		for (short j = 0; j < Cols; j++) {

			arr2[i][j] = arr1[j][i];
		}
	}
}
int main() {
	int arr1[3][3], arr2[3][3];

	FillArrayWithOrderedNumbers(arr1, 3, 3);
	transposeMatrix(arr1, arr2, 3, 3);
	PrintMatrix(arr1, 3, 3);
	PrintMatrix(arr2, 3, 3);

	return 0;
}