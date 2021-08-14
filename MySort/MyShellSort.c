#include"MySort.h"

void myShellSort(int* arr, int length) {

	for (int gap = floor(length / 2); gap > 0; gap = floor(gap / 2)) {

		//对分组进行插入排序
		for (int i = gap, j, temp; i < length; i++) {
			j = i;
			temp = arr[j];
			while (j - gap >= 0 && temp < arr[j - gap]) {
				arr[j] = arr[j - gap];
				j = j - gap;
			}
			arr[j] = temp;
		}

	}
}