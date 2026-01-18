// Write a progrma to check if a matrix is a scalar matrix or not
#include <iostream>
#include <iomanip>

using namespace std;

void PrintArray(const int arr[3][3], const short Rows, const short Cols) {


	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool IsScalarMatrix(const int arr[3][3], const short Rows, const short Cols) {
	if (Rows != Cols)
		return false;
	const int FirstElement = arr[0][0];

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {

			if ((i == j && arr[i][j] != FirstElement) || (i != j && arr[i][j] != 0)) {
				return false;
			}

		}
	}
	return true;
}
int main() {
	
	int arr[3][3] = { 5,0,0,0,5,0,0,0,5 };

	if (IsScalarMatrix(arr, 3, 3)) {
		cout << "Scalar!\n";
	}
	else
	{
		cout << "Not scalar!\n";
	}


	return 0;
}