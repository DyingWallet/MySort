#include"MySort.h"

//ѡ������ÿ��ѡ����С/��ģ��������뵱ǰ��������ĵ�һ��Ԫ�ؽ�����

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