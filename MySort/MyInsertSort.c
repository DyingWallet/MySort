#include"MySort.h"

void myInsertSort(int* arr, int length) {

	for (int i = 1, j, temp; i < length; i++) {
		j = i;
		temp = arr[j];
		//找插入位置
		while (j - 1 >= 0 && temp < arr[j - 1]) j--;

		//移动元素
		for (int k = i; k > j; k--) {
			arr[k] = arr[k - 1];
		}

		arr[j] = temp;
	}
}

void myOptimizedInsertSort(int* arr, int length) {
	for (int i = 1, j, temp; i < length; i++) {
		j = i;
		temp = arr[j];

		while (j - 1 >= 0 && temp < arr[j - 1]) {
			arr[j] = arr[j - 1];
			j = j - 1;
		}
		arr[j] = temp;
	}
}