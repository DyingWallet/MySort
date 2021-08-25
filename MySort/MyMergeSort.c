#include"MySort.h"


//5.1���鲢����-�ݹ��
void myRecursionMergeSort(int* arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		myRecursionMergeSort(arr, left, mid);

		myRecursionMergeSort(arr, mid + 1, right);

		//merge
		myMerge(arr, left, mid, right);

	}
	return arr;
}

void myMerge(int* arr, int left, int mid, int right) {

	//����һ����������ݴ�
	int* tmpArr = (int*)calloc(right - left, sizeof(int));

	//˫ָ�����α�������������
	int i = left, j = mid + 1, k = 0;

	//�������鳤��������1
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) tmpArr[k++] = arr[i++];
		else tmpArr[k++] = arr[j++];
	}

	while (i <= mid) tmpArr[k++] = arr[i++];
	while (j <= right) tmpArr[k++] = arr[j++];
	while (right >= left) arr[right--] = tmpArr[--k];
}

//5.2�鲢����-������
void myIterationMergeSort(int* arr, int length) {
	int left, mid, right;

	for (int subLen = 1; subLen < length; subLen *= 2) {
		left = 0;
		mid = left + subLen - 1;
		right = mid + subLen;

		while (right < length) {
			myMerge(arr, left, mid, right);

			left = right + 1;
			mid = left + subLen - 1;
			right = mid + subLen;
		}

		if (left < length && mid < length) myMerge(arr, left, mid, length - 1);
	}
}