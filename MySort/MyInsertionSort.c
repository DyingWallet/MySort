#include"MySort.h"

//������Ԫ�����β������������еĺ���λ��
void myInsertionSort(int* arr, int length) {
	for (int i = 1, j, tmp; i < length; i++) {
		j = i;
		tmp = arr[j];

		while (j - 1 >= 0 && tmp < arr[j - 1]) arr[j--] = arr[j - 1];

		arr[j] = tmp;
	}
}