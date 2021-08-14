#include"MySort.h"

void myInsertSort(int* arr, int length) {

	for (int i = 1, j, temp; i < length; i++) {
		j = i;
		temp = arr[j];
		//�Ҳ���λ��
		while (j - 1 >= 0 && temp < arr[j - 1]) j--;

		//�ƶ�Ԫ��
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