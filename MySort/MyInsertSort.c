#include"MySort.h"

void myInsertSort(int* arr, int length) {

	for (int i = 1; i < length; i++) {
		int temp = arr[i];
		int j = i - 1;
		//找插入位置
		while (j >= 0 && temp < arr[j]) j--;

		//移动元素
		for (int k = i; k > j + 1; k--) {
			arr[k] = arr[k - 1];
		}
		arr[j + 1] = temp;
	}
}