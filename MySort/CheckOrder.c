#include"MySort.h"

bool checkOrder(int* arr, int length) {

	for (int i = 0; i < length - 1; i++) {
		if (arr[i] > arr[i + 1]) return false;
	}
	return true;
}