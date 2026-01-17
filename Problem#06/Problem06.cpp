//Write a program to fill a 3x3 array with ordered numbers

#include<iostream>
#include<iomanip>


using namespace std;



void FillArrayWithOrderedNumbers(int arr[3][3], const short Rows, const short Cols) {

	short Counter = 0;

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



int main() {
	int arr[3][3];

	FillArrayWithOrderedNumbers(arr, 3, 3);
	PrintMatrix(arr, 3, 3);

	return 0;
}