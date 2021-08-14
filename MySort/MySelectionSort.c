#include"MySort.h"

void mySelectionSort(int* arr, int length) {

	for (int i = 0; i < length - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[minIndex])	minIndex = j;
		}
		int temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}
}