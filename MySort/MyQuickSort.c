#include"MySort.h"

#define INS_LIMIT 128

void insertSortInQuickSort(int* arr, int start, int end) {
	for (int i = start, j, temp; i <= end; i++) {
		j = i;
		temp = arr[j];
		//�Ҳ���λ��
		while (j - 1 >= start && temp < arr[j - 1]) j--;

		//�ƶ�Ԫ��
		for (int k = i; k > j; k--) {
			arr[k] = arr[k - 1];
		}

		arr[j] = temp;
	}
}

void shellSortInQuickSort(int* arr, int start, int end) {
	int length = end - start + 1;
	int gap = 1;
	while (gap <= length / 3) gap = gap * 3 + 1;

	while (gap > 0) {
		//�Է�����в�������
		for (int i = gap + start, j, temp; i <= end; i++) {
			j = i;
			temp = arr[j];

			while (j - gap >= start && temp < arr[j - gap]) {
				arr[j] = arr[j - gap];
				j = j - gap;
			}
			arr[j] = temp;
		}
		gap = (gap - 1) / 3;
	}
}

void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int midValOfThreeNum(int* arr, int left, int right) {
	int mid = left + ((right - left) >> 1);

	if (arr[mid] > arr[right])
		swap(arr, mid, right);

	if (arr[left] > arr[right])
		swap(arr, left, right);

	if (arr[left] > arr[mid])
		swap(arr, left, mid);

	//��֤arr[left]<=arr[mid]<=arr[right]
	return arr[mid];
}

//����������������󣬵ݹ���������������ջ���
void myRecursionQuickSort(int* arr, int left, int right) {
	if (left < right) {
		int i = left, j = right, pivot = arr[left + ((right - left) >> 1)];

		while (i < j) {
			//��pivot����������ֵ�����ƶ�ָ��
			while (i < j && arr[i] <= pivot) i++;

			//��i<j����˵��arr[i]����piovt����ʱ����λ��
			if (i < j) arr[j] = arr[i];

			//��pivotС�����Ҳ��ֵ�����ƶ�ָ��
			while (j > i && arr[j] >= pivot) j--;

			//��i<j����˵��arr[j]С��piovt����ʱ����λ��
			if (j > i) arr[i] = arr[j];

		}
		arr[i] = pivot;

		if ((i - 1) > left) {
			if (i - 1 - left > INS_LIMIT) myRecursionQuickSort(arr, left, i - 1);
			else insertSortInQuickSort(arr, left, i - 1);
		}

		if (right > (i + 1)) {
			if (right - i - 1 > INS_LIMIT) myRecursionQuickSort(arr, i + 1, right);
			else insertSortInQuickSort(arr, i + 1, right);
		}
	}
	return;
}

//ʹ������ģ��ջ����������
void myIterationQuickSort(int* arr, int length) {

	int left = 0, right = length - 1;

	int* stack = (int*)calloc(length, sizeof(int));
	int top = -1;

	stack[++top] = right;
	stack[++top] = left;

	while (top>=0) {
		left = stack[top--];
		right = stack[top--];

		int i = left, j = right, pivot = midValOfThreeNum(arr, left, right);

		while (i < j) {
			while (i < j && arr[i] <= pivot) i++;
			if (i < j) arr[j] = arr[i];

			while (i < j && arr[j] >= pivot) j--;
			if (i < j) arr[i] = arr[j];
		}
		arr[i] = pivot;

		//�Ұ���������ջ
		if (right > (i + 1)) {
			if (right - (i + 1) > INS_LIMIT) {
				stack[++top] = right;
				stack[++top] = i + 1;
			} else shellSortInQuickSort(arr, i + 1, right);
		}
		//������κ���ջ
		if ((i - 1) > left) {
			if ((i - 1) - left > INS_LIMIT) {
				stack[++top] = i - 1;
				stack[++top] = left;
			} else shellSortInQuickSort(arr, left, i - 1);
		}
	}
	free(stack);
}