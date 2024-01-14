#include<iostream>

using namespace std;

int main() {

	int arr[3][4] = {{10, 15, 20, 25}, {30, 35, 40, 45}, {50, 55, 60, 65}};

	cout << arr[0] << " " << &arr[0][0] << " " << arr << endl;
	cout << arr[1] << " " << &arr[1][0] << " " << arr + 1 << " " << *(*(arr + 1)) << endl;
	cout << arr[2] << " " << &arr[2][0] << " " << arr + 2 << endl;

	return 0;
}