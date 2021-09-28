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

void myInsertionSortWithBinarySearch(int* arr, int length) {
	int left, right, mid, tmp;

	for (int i = 1, j; i < length; i++) {
		j = i;
		left = 0;
		right = i - 1;//0~(i-1)Ϊ��������
		tmp = arr[j];
		//ʹ�ö��ַ����Ҳ���λ��
		while (left <= right) {
			mid = left + (right - left) / 2;

			//����λ����mid֮ǰ(tmpС��arr[mid])
			if (tmp < arr[mid]) right = mid - 1;
			//����λ����mid֮��(tmp�����arr[mid])
			else left = mid + 1;
		}
		//������λ�����Ԫ�غ���
		while (j - 1 >= left) arr[j--] = arr[j - 1];
		
		//���в���
		arr[left] = tmp;
	}
}