#include"MySort.h"

/*
排序思路：
	冒泡排序是经典排序算法中较简单的一种，
	其在每次遍历中都对相邻元素进行比较，
	判断其顺序是否符合目标顺序，
	如不符合则进行位置交换，
	在每一次这样的遍历过程中，
	都会使最大（小）元素慢慢“上浮”到序列最顶端。
	不断重复这个操作直到遍历完整个序列，
	则完成对整个序列的排序，使整个序列有序。
*/

//冒泡排序
void myBubbulSort(int* arr, int length) {

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length -1; j++) {
			if (arr[j+1] < arr[j]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//优化后的冒泡排序
void myOptimizedBubulSort(int* arr, int length) {

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j + 1] < arr[j]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}