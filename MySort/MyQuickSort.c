#include"MySort.h"

#define INS_LIMIT -1
#define SHELL_LIMIT 64

void insertionSortInQuickSort(int* arr, int start, int end) {
	for (int i = start, j, temp; i <= end; i++) {
		j = i;
		temp = arr[j];
		//找插入位置
		while (j - 1 >= start && temp < arr[j - 1]) j--;

		//移动元素
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
		//对分组进行插入排序
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

	//保证arr[left]<=arr[mid]<=arr[right]
	return arr[mid];
}

//递归版 基础快速排序-不能处理大数据量的序列，递归过深会引起堆栈溢出
void myBasicRecursionQuickSort(int* arr, int left, int right) {

	//区间长度为1时，即为有序
	if (right - left <= 1) return;

	//此处默认将left处的元素设置为pivot元素，
	//算法中则对当前数据区段的[left,right]区间进行排序
	int pivot = arr[left];

	//这里的low从序列左端开始，以low表示的区间的值均小于pivot，将该区间记作低值区间
	int low = left;

	//这里的high从序列左端开始，以high表示的区间的值均大于pivot，将该区间记作高值区间
	int high = right;

	while (low < high) {
		//从序列右边寻找第一个小于pivot的值，如果找到这样一个元素，则high停在那儿
		while (high > low && arr[high] >= pivot) --high;

		//上面的循环跳出时，high找到了高值区间中小于pivot的低值，此时low还指向pivot
		//交换两者的位置，以保证高值区间中的值均大于pivot
		swap(arr, low, high);

		//先从序列左边寻找第一个大于pivot的值，如果找到这样一个元素low则停在那里
		while (low < high && arr[low] <= pivot) ++low;

		//同理，此时low指向低值区间中的高值，将其与high指向的值交换
		swap(arr, low, high);
	}


	//low区间，[left,low-2]
	if(left < low - 1)
	myBasicRecursionQuickSort(arr, left, low - 1);

	//high区间，[low,right]
	if(low + 1 < right)
	myBasicRecursionQuickSort(arr, low + 1, right);
}

//迭代版 可以处理大量级的数据
void myBasicIterationQuickSort(int* arr, int length) {

	//左指针和右指针
	int left = 0, right = length - 1;

	//这里不用专门去实现一个栈，转而使用一个数组进行模拟
	int* arrStack = (int*)calloc(length+1, sizeof(int));
	int top = -1;

	//将每次迭代需要进行 分治排序 的左右下标存入栈中，用来模拟递归
	arrStack[++top] = right;
	arrStack[++top] = left;

	while (top > 0) {
		//区间前后界出栈

		left = arrStack[top--];
		right = arrStack[top--];

		int low = left, high = right;

		//取left处的值作为pivot
		int pivot = arr[left];

		while (low < high) {

			while (low < high && arr[high] >= pivot) high--;

			swap(arr, low, high);

			while (low < high && arr[low] <= pivot) low++;

			swap(arr, low, high);
		}

		//保存低值区间的前后界
		if (left < low - 1) {
			arrStack[++top] = low - 1;
			arrStack[++top] = left;
		}

		//保存高值区间的前后界
		if (low + 1 < right) {
			arrStack[++top] = right;
			arrStack[++top] = low + 1;
		}
	}
}


//
//如果排序数据量过大，递归层数过深会引发堆栈溢出
void myRecursionQuickSort(int* arr, int left, int right) {
//	if (left < right) {
//		//pivot的值取中间元素
//		int pivotPos = left + ((right - left) >> 1);
//
//		//开始前，把pivot与第一个值交换，相当于把pivot排除在排序外
//		swap(arr, left, pivotPos);
//
//		int i = left+1, j = right;
//
//		while (i < j) {
//			//若找到arr[i] > pivot，则停住
//			while (i < j && arr[i] <= arr[left]) i++;
//
//			//若找到arr[j] < pivot 则停住
//			while (j > i && arr[j] >= arr[left]) j--;
//
//			//左右指针相遇，则说明已经找到pivot的位置，此时应有 j == i-1
//			if (i > j) break;
//
//			//否则若i<j，则说明arr[j]小于piovt，此时交换位置
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
//使用数组模拟栈来保存数据
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
//		//右半区段先入栈
//		if (right > (i + 1)) {
//			if (right - (i + 1) > SHELL_LIMIT) {
//				stack[++top] = right;
//				stack[++top] = i + 1;
//			} else shellSortInQuickSort(arr, i + 1, right);
//		}
//		//左半区段后入栈
//		if ((i - 1) > left) {
//			if ((i - 1) - left > SHELL_LIMIT) {
//				stack[++top] = i - 1;
//				stack[++top] = left;
//			} else shellSortInQuickSort(arr, left, i - 1);
//		}
//	}
	//free(stack);
}