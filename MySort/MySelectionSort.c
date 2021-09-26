#include"MySort.h"

//选择排序，每次选择最小/大的，并将其与当前无序区间的第一个元素交换。

void mySelectionSort(int* arr, int length) {
	int min, tmp;
	for (int i = 0, j; i < length - 1; i++) {
		min = i;
		for (j = i + 1; j < length; j++) {
			if (arr[min] > arr[j]) min = j;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}