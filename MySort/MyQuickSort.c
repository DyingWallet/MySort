#include"MySort.h"

#define INS_LIMIT -1
#define SHELL_LIMIT 64

void insertionSortInQuickSort(int* arr, int start, int end) {
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
				j -= gap;
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

//�ݹ�� ������������-���ܴ���������������У��ݹ����������ջ���
void myBasicRecursionQuickSort(int* arr, int left, int right) {

	//���䳤��Ϊ1ʱ����Ϊ����
	if (right - left <= 1) return;

	//�˴�Ĭ�Ͻ�left����Ԫ������ΪpivotԪ�أ�
	//�㷨����Ե�ǰ�������ε�[left,right]�����������
	int pivot = arr[left];

	//�����low��������˿�ʼ����low��ʾ�������ֵ��С��pivot���������������ֵ����
	int low = left;

	//�����high��������˿�ʼ����high��ʾ�������ֵ������pivot���������������ֵ����
	int high = right;

	while (low < high) {
		//�������ұ�Ѱ�ҵ�һ��С��pivot��ֵ������ҵ�����һ��Ԫ�أ���highͣ���Ƕ�
		while (high > low && arr[high] >= pivot) --high;

		//�����ѭ������ʱ��high�ҵ��˸�ֵ������С��pivot�ĵ�ֵ����ʱlow��ָ��pivot
		//�������ߵ�λ�ã��Ա�֤��ֵ�����е�ֵ������pivot
		swap(arr, low, high);

		//�ȴ��������Ѱ�ҵ�һ������pivot��ֵ������ҵ�����һ��Ԫ��low��ͣ������
		while (low < high && arr[low] <= pivot) ++low;

		//ͬ����ʱlowָ���ֵ�����еĸ�ֵ��������highָ���ֵ����
		swap(arr, low, high);
	}


	//low���䣬[left,low-2]
	if(left < low - 1)
	myBasicRecursionQuickSort(arr, left, low - 1);

	//high���䣬[low,right]
	if(low + 1 < right)
	myBasicRecursionQuickSort(arr, low + 1, right);
}

//������ ���Դ��������������
void myBasicIterationQuickSort(int* arr, int length) {

	//��ָ�����ָ��
	int left = 0, right = length - 1;

	//���ﲻ��ר��ȥʵ��һ��ջ��ת��ʹ��һ���������ģ��
	int* arrStack = (int*)calloc(length+1, sizeof(int));
	int top = -1;

	//��ÿ�ε�����Ҫ���� �������� �������±����ջ�У�����ģ��ݹ�
	arrStack[++top] = right;
	arrStack[++top] = left;

	while (top > 0) {
		//����ǰ����ջ

		left = arrStack[top--];
		right = arrStack[top--];

		int low = left, high = right;

		//ȡleft����ֵ��Ϊpivot
		int pivot = arr[left];

		while (low < high) {

			while (low < high && arr[high] >= pivot) high--;

			swap(arr, low, high);

			while (low < high && arr[low] <= pivot) low++;

			swap(arr, low, high);
		}

		//�����ֵ�����ǰ���
		if (left < low - 1) {
			arrStack[++top] = low - 1;
			arrStack[++top] = left;
		}

		//�����ֵ�����ǰ���
		if (low + 1 < right) {
			arrStack[++top] = right;
			arrStack[++top] = low + 1;
		}
	}
}


//
//����������������󣬵ݹ���������������ջ���
void myRecursionQuickSort(int* arr, int left, int right) {
//	if (left < right) {
//		//pivot��ֵȡ�м�Ԫ��
//		int pivotPos = left + ((right - left) >> 1);
//
//		//��ʼǰ����pivot���һ��ֵ�������൱�ڰ�pivot�ų���������
//		swap(arr, left, pivotPos);
//
//		int i = left+1, j = right;
//
//		while (i < j) {
//			//���ҵ�arr[i] > pivot����ͣס
//			while (i < j && arr[i] <= arr[left]) i++;
//
//			//���ҵ�arr[j] < pivot ��ͣס
//			while (j > i && arr[j] >= arr[left]) j--;
//
//			//����ָ����������˵���Ѿ��ҵ�pivot��λ�ã���ʱӦ�� j == i-1
//			if (i > j) break;
//
//			//������i<j����˵��arr[j]С��piovt����ʱ����λ��
//			arr[i] = arr[j];
//
//		}
//		arr[i] = pivot;
//
//		if ((i - 1) > left) {
//			if (i - 1 - left > INS_LIMIT) myRecursionQuickSort(arr, left, i - 1);
//			else insertionSortInQuickSort(arr, left, i - 1);
//		}
//
//		if (right > (i + 1)) {
//			if (right - i - 1 > INS_LIMIT) myRecursionQuickSort(arr, i + 1, right);
//			else insertionSortInQuickSort(arr, i + 1, right);
//		}
//	}
	return;
}
//
//ʹ������ģ��ջ����������
void myIterationQuickSort(int* arr, int length) {
//
//	int left = 0, right = length - 1;
//
//	int* stack = (int*)calloc(length, sizeof(int));
//	int top = -1;
//
//	stack[++top] = right;
//	stack[++top] = left;
//
//	while (top>=0) {
//		left = stack[top--];
//		right = stack[top--];
//
//		int i = left, j = right, pivot = midValOfThreeNum(arr, left, right);
//
//		while (i < j) {
//			while (i < j && arr[i] <= pivot) i++;
//			if (i < j) arr[j] = arr[i];
//
//			while (i < j && arr[j] >= pivot) j--;
//			if (i < j) arr[i] = arr[j];
//		}
//		arr[i] = pivot;
//
//		//�Ұ���������ջ
//		if (right > (i + 1)) {
//			if (right - (i + 1) > SHELL_LIMIT) {
//				stack[++top] = right;
//				stack[++top] = i + 1;
//			} else shellSortInQuickSort(arr, i + 1, right);
//		}
//		//������κ���ջ
//		if ((i - 1) > left) {
//			if ((i - 1) - left > SHELL_LIMIT) {
//				stack[++top] = i - 1;
//				stack[++top] = left;
//			} else shellSortInQuickSort(arr, left, i - 1);
//		}
//	}
	//free(stack);
}