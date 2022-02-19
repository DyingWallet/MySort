#include"MySort.h"

#define SORT_TIMES 5
#define ARR_LENGTH 10

static bool isPrint = true;
static int mode = 1;

void checkAvgSortTime(int);

void mySort(bool);

void mySelectMethod(int* arr) {

	//选择排序
	//mySelectionSort(arr, ARR_LENGTH);

	//插入排序
	//myInsertionSort(arr, ARR_LENGTH);

	//使用二分查找法的插入排序
	//myInsertionSortWithBinarySearch(arr, ARR_LENGTH);

	//冒泡排序
	//myBubbulSort(arr, ARR_LENGTH);

	//优化后的冒泡排序
	//myOptimizedBubulSort(arr, ARR_LENGTH);

	//希尔排序
	//myShellSort(arr, ARR_LENGTH);

	//使用knuth间隔序列的希尔排序
	//myKnuthShellSort(arr, ARR_LENGTH);

	//递归法归并排序
	//myRecursionMergeSort(arr, 0, ARR_LENGTH - 1);

	//迭代法归并排序
	//myIterationMergeSort(arr, ARR_LENGTH);

	//基本快速排序-递归版-未经过任何优化的版本
	//myBasicRecursionQuickSort(arr, 0, ARR_LENGTH - 1);

	//基本快速排序-递归版-未经过任何优化的版本
	myBasicIterationQuickSort(arr, ARR_LENGTH);

	//快速排序-递归版-有bug，后期有空再进行修改
	//myRecursionQuickSort(arr, 0, ARR_LENGTH - 1);

	//快速排序-迭代版-有bug，后期有空再进行修改
	//myIterationQuickSort(arr, ARR_LENGTH);
}

int main(void) {

	switch (mode) {
	case 1:
		mySort(isPrint); 
		break;
	case 2:
		checkAvgSortTime(SORT_TIMES); 
		break;
	default:
		break;
	}
	return 0;
}

void checkAvgSortTime(int times) {
	srand((unsigned)time(NULL)); //用当前系统时间设置种子

	int* arr = (int*)calloc(ARR_LENGTH, sizeof(int));
	if (arr == NULL) exit(-1);

	LARGE_INTEGER  num;
	long long start, end, freq, sum = 0, single;

	for (int i = 0; i < times; i++) {

		for (int i = 0; i < ARR_LENGTH; i++)
			arr[i] = rand() % ARR_LENGTH;

		QueryPerformanceFrequency(&num);
		freq = num.QuadPart;

		QueryPerformanceCounter(&num);
		start = num.QuadPart;

		mySelectMethod(arr);

		QueryPerformanceCounter(&num);
		end = num.QuadPart;
		single = (end - start) * 1000 / freq;
		sum += single;

		char* isSorted = checkOrder(arr, ARR_LENGTH) ? "true" : "fales";

		printf("Arr:%d Sort Finished, is Sorted:%s, Sort Time: %lld ms\n", i + 1, isSorted,  single);
		//char* isSorted = checkOrder(arr, ARR_LENGTH) ? "true" : "fales";

		//printf("Sort %d Finished, Arr:%d isSorted:%s, Sort Time: %lld ms\n", i + 1, i + 1, isSorted, single);
	}
	printf("All Check Finished, Avg Sort Time: %lld ms", sum / times);
}

void mySort(bool isPrint) {
	srand((unsigned)time(NULL)); //用当前系统时间设置种子

	int* arr = (int*)calloc(ARR_LENGTH, sizeof(int));
	if (arr == NULL) exit(-1);

	for (int i = 0; i < ARR_LENGTH; i++)
		arr[i] = rand() % ARR_LENGTH;
	if (isPrint) {
		printf("\n====================\n");
		for (int i = 0; i < ARR_LENGTH; i++) {
			printf("%d,", arr[i]);
		}
		printf("\n====================\n");
	}
	LARGE_INTEGER  num;
	long long start, end, freq;
	QueryPerformanceFrequency(&num);
	freq = num.QuadPart;

	QueryPerformanceCounter(&num);
	start = num.QuadPart;

	mySelectMethod(arr);

	QueryPerformanceCounter(&num);
	end = num.QuadPart;

	printf("Sort Finished.\nCheck if the array is in Order...\n");

	char* isSorted = checkOrder(arr, ARR_LENGTH) ? "true" : "fales";

	printf("isSorted:%s", isSorted);

	printf("\n====================\n");
	printf("time=%lld\n", (end - start) * 1000 / freq);

	if (isPrint) {
		printf("\n====================\n");
		for (int i = 0; i < ARR_LENGTH; i++) {
			printf("%d,", arr[i]);
		}
		printf("\n====================\n");
	}
	system("pause");
}
