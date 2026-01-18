//Write a program to check if matrix is identity or not
/*
1 0 0
0 1 0
0 0 1
*/

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

bool IsIdentityMatrix(const int arr[3][3], const short Rows, const short Cols) {
	if (Rows != Cols)
		return false;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {

			if ((i == j && arr[i][j] != 1) ||
				(i != j && arr[i][j] != 0))
				return false;


		}
	}
	return true;
}
int main() {
	int arr[3][3] = { 1,0,0,0,1,0,0,0,1 };
	PrintArray(arr, 3, 3);

	if (IsIdentityMatrix(arr, 3, 3)) {
		cout << "Identity!\n";
	}
	else {

		cout << "Not identity!\n";
	}
}