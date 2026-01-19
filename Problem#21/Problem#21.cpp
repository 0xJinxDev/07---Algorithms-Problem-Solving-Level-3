//Write a program to print Fibonacci series till n
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int ReadNumber(string Message) {
	cout << Message << endl;
	int number = 0;
	cin >> number;
	return number;

}


int * FillFibonacci(int number) {
    int* arr = new int[number];

    if (number >= 1) arr[0] = 0;
    if (number >= 2) arr[1] = 1;

    for (int i = 2; i < number; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }


    return arr;
}

void PrintArray(int* arr, int number) {
    for (int i = 0; i < number; i++) {
        cout << setw(3) << arr[i];
    }
}

void PrintFibWithoutArray(const int number) {

    int prev1 = 0, prev2 = 1, current;

    for (int i = 0; i < number; i++) {
        cout << setw(3) << prev1;
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;

    }
}

int main() {

	int number = ReadNumber("Please enter the n:");
	int *Fib = FillFibonacci(number);
    PrintArray(Fib, number);
    delete [] Fib;

    PrintFibWithoutArray(number);
	return 0;

}