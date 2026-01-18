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

			cout << setw(6) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

}

void PrintArray(const int arr[9], const short Length) {

	for (short i = 0; i < Length; i++) {
		cout << setw(6) << arr[i];
	}
	cout << endl;
}

void AddElementToArray(int Multiply[9], const int number, const int pos) {

	Multiply[pos] = number;

}

void  MultiplyArraysToArray(const int Array1[3][3], const int Array2[3][3],int Multiply[9],const short Rows, const short Cols) {
	int counter = 0;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {

			AddElementToArray(Multiply, (Array1[i][j] * Array2[i][j]), counter);
			counter++;

		}
	}
}

void MultiplyArraysToMatrix(const int Array1[3][3], const int Array2[3][3], int Result[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			Result[i][j] = Array1[i][j] * Array2[i][j];
		}
	}
}

int main() {

	srand((unsigned)time(NULL));
	int Array1[3][3] = {}, Array2[3][3] = {}, Multiply[9] = {}, MatrixResult[3][3] = {};
	FillArrayWithRandomNumbers(Array1, 3, 3);
	FillArrayWithRandomNumbers(Array2, 3, 3);

	PrintMatrix(Array1, 3, 3);
	PrintMatrix(Array2, 3, 3);
	MultiplyArraysToArray(Array1, Array2, Multiply, 3, 3);
	PrintArray(Multiply, 9);
	MultiplyArraysToMatrix(Array1, Array2, MatrixResult, 3, 3);
	PrintMatrix(MatrixResult, 3, 3);


}