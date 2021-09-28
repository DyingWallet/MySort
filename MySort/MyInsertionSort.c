#include"MySort.h"

//将无序元素依次插入有序区间中的合适位置
void myInsertionSort(int* arr, int length) {
	for (int i = 1, j, tmp; i < length; i++) {
		j = i;
		tmp = arr[j];

		while (j - 1 >= 0 && tmp < arr[j - 1]) arr[j--] = arr[j - 1];

		arr[j] = tmp;
	}
}

void myInsertionSortWithBinarySearch(int* arr, int length) {
	int left, right, mid, tmp;

	for (int i = 1, j; i < length; i++) {
		j = i;
		left = 0;
		right = i - 1;//0~(i-1)为有序区间
		tmp = arr[j];
		//使用二分法查找插入位置
		while (left <= right) {
			mid = left + (right - left) / 2;

			//插入位置在mid之前(tmp小于arr[mid])
			if (tmp < arr[mid]) right = mid - 1;
			//插入位置在mid之后(tmp大等于arr[mid])
			else left = mid + 1;
		}
		//将插入位置其后元素后移
		while (j - 1 >= left) arr[j--] = arr[j - 1];
		
		//进行插入
		arr[left] = tmp;
	}
}