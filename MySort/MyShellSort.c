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

//使用knuth间隔序列
void myKnuthShellSort(int* arr, int length) {
	int gap = 1;

	while (gap <= length / 3) {
		gap = gap * 3 + 1;
	}

	while (gap > 0) {
		//对分组进行插入排序
		for (int i = gap,j,temp; i < length; i++) {
			j = i;
			temp = arr[j];
			
			while (j - gap >= 0 && temp < arr[j - gap]) {
				arr[j] = arr[j - gap];
				j = j - gap;
			}
			arr[j] = temp;
		}
		gap = (gap - 1) / 3;
	}
}