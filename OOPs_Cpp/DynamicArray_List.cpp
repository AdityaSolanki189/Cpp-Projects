#include <iostream>

using namespace std;

int main(void) {

	int x; 

	int *array{ new int[5]{ 10, 7, 15, 3, 11 } };

	cout << "Array elements: " << endl;

	for (x = 0; x < 5; x++) {

		cout << array[x] << endl;
	}

	return 0;
}