#include"MySort.h"

#define ARR_LENGTH 50000

int main(void) {

	srand((unsigned)time(NULL)); //用当前系统时间设置种子

	int* arr = (int*)calloc(ARR_LENGTH, sizeof(int));

	//printf("Before Sort:\n");
	for (int i = 0; i < ARR_LENGTH; i++) {
		arr[i] = rand() % ARR_LENGTH;
		//printf("%d ", arr[i]);
	}

	LARGE_INTEGER  num;
	long long start, end, freq;
	QueryPerformanceFrequency(&num);
	freq = num.QuadPart;

	QueryPerformanceCounter(&num);
	start = num.QuadPart;

	//选择排序
	//mySelectionSort(arr, ARR_LENGTH);
	//插入排序
	//myInsertSort(arr, ARR_LENGTH);
	//优化后的插入排序
	//myOptimizedInsertSort(arr, ARR_LENGTH);
	//冒泡排序
	//myBubbulSort(arr, ARR_LENGTH);
	//优化后的冒泡排序
	//myOptimizedBubulSort(arr, ARR_LENGTH);
	//希尔排序
	//myShellSort(arr, ARR_LENGTH);


	QueryPerformanceCounter(&num);
	end = num.QuadPart;

	//printf("\n====================\n");
	//printf("\nAfter Sort:\n");
	//for (int i = 0; i < ARR_LENGTH; i++) {
	//	printf("%d ", arr[i]);
	//}
	bool flag = checkOrder(arr, ARR_LENGTH);
	char* isOrder = flag ? "true" : "fales";

	printf("%d\n%s", flag, isOrder);

	printf("\n====================\n");
	printf("time=%lld\n", (end - start) * 1000 / freq);
	system("pause");
	return 0;
}