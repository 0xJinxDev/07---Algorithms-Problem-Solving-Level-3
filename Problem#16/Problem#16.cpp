//Write a program to check if matrix is a sparse or not
#include <iostream>
#include <iomanip>

using namespace std;

void PrintArray(const int arr[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {

			cout << setw(3) <<arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

}

bool IsSparseArray(const int arr[3][3], const short Rows, const short Cols) {

	short Elements = Rows * Cols;
	int Counter = 0;

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (arr[i][j] == 0) {
				Counter++;
			}
		}
	}
	return Counter > Elements / 2;

}


int main() {


	int arr[3][3] = { 0,0,0,0,4,4,2,3,4, };

	PrintArray(arr, 3, 3);

	cout << (IsSparseArray(arr, 3, 3) ? "Sparse!\n" : "Not Sparse!\n");

	return 0;
}