//Write a program to check if two matrices are typicall or not

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
	cout << endl;
}

bool AreTypicalMatrices(const int arr1[3][3], const int arr2[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr1[i][j] != arr2[i][j]) {
				cout << "Difference at (" << i << ", " << j << ")\n";
				return false;
			}
		}
	}
	return true;
}

int main() {
	srand((unsigned)time(NULL));
	int arr1[3][3] = {}, arr2[3][3] = {};
	FillArrayWithRandomNumbers(arr1, 3, 3);
	FillArrayWithRandomNumbers(arr2, 3, 3);
	PrintArray(arr1, 3, 3);
	PrintArray(arr2, 3, 3);

	if (AreTypicalMatrices(arr1, arr2, 3, 3)) {
		cout << "Matrices are typical!\n";
	}
	else {
		cout << "Matrices are not typical!\n";
	}


	return 0;
}