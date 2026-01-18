//Write a program to check if matrix is palindrome or not
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
bool IsPalindromeMatrix(const int arr[3][3], const short Rows, const short Cols) {

	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols/2; j++) {

			if (arr[i][j] != arr[i][Cols - j - 1]) {
				return false;
			}
		}
	 }
	return true;
}
int main() {

	int arr[3][3] = { 1,1,1,2,2,2,3,5,3 };
	PrintArray(arr, 3, 3);
	cout << IsPalindromeMatrix(arr, 3, 3);

	return 0;
}