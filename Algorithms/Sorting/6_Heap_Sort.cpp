#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest]) {
		largest = l;
	}
	if (r < n && arr[r] > arr[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

/* 	Time Complexity :
	Worst case performance: Θ(nlogn)
	Best case performance: Θ(nlogn)
	Average case performance: Θ(nlogn)
	Worst case space complexity: Θ(n) total, Θ(1) auxiliary
*/

int main() {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, n);
	cout << "Sorted array:" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
	return 0;
}

/* Theory:
Heapsort is a comparison-based sorting algorithm and is part of the selection sort family.
Although somewhat slower in practice on most machines than a good implementation of Quick
sort, it has the advantage of a more favorable worst-case Θ(nlogn) runtime. Heapsort is an in-place algorithm but is not a stable sort.
Using Priority Queues
*/