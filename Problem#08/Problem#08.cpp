//Write a program to fill two 3x3 matrix with random numbers and then multiply them into 3rd matrix and print it

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

			arr[i][j] = RandomNumber(1, 100);
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

void PrintArray(const int arr[3], const short Length) {

	for (short i = 0; i < Length; i++) {
		cout << setw(4) << arr[i];
	}
	cout << endl;
}
//Wrong 
int MultiplyArraysToArray(const int Array1[3][3], const int Array2[3][3],const short Rows, const short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {

			return Array1[i][j] * Array2[i][j];

		}
	}
}

void AddMultiplicationToArray(const int Array1[3][3], const int Array2[3][3], int Multiply[3], const short Rows, const short Cols,const short Length) {

	for (short i = 0; i < Length; i++) {
		Multiply[i] = MultiplyArraysToArray(Array1, Array2, 3, 3);
	}
}
int main() {


	int Array1[3][3] = {}, Array2[3][3] = {}, Multiply[3] = {};
	FillArrayWithRandomNumbers(Array1, 3, 3);
	FillArrayWithRandomNumbers(Array2, 3, 3);

	PrintMatrix(Array1, 3, 3);
	PrintMatrix(Array2, 3, 3);
	AddMultiplicationToArray(Array1, Array2, Multiply, 3, 3, 3);
	PrintArray(Multiply, 3);


}