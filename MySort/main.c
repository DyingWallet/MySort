#include"MySort.h"

#define SORT_TIMES 50
#define ARR_LENGTH 5000000

void checkAvgSortTime(int times) {
	srand((unsigned)time(NULL)); //�õ�ǰϵͳʱ����������

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

		//ѡ������
		//mySelectionSort(arr, ARR_LENGTH);
		//��������
		//myInsertSort(arr, ARR_LENGTH);
		//�Ż���Ĳ�������
		//myOptimizedInsertSort(arr, ARR_LENGTH);
		//ð������
		//myBubbulSort(arr, ARR_LENGTH);
		//�Ż����ð������
		//myOptimizedBubulSort(arr, ARR_LENGTH);
		//ϣ������
		myShellSort(arr, ARR_LENGTH);
		//ʹ��knuth������е�ϣ������
		//myKnuthShellSort(arr, ARR_LENGTH);

		QueryPerformanceCounter(&num);
		end = num.QuadPart;
		single = (end - start) * 1000 / freq;
		sum += single;
		printf("Check %d Finished, Single Sort Time: %lld ms\n", i + 1, single);
	}
	printf("All Check Finished, Avg Sort Time: %lld ms", sum / times);
}

void mySort() {
	srand((unsigned)time(NULL)); //�õ�ǰϵͳʱ����������

	int* arr = (int*)calloc(ARR_LENGTH, sizeof(int));
	if (arr == NULL) exit(-1);

	for (int i = 0; i < ARR_LENGTH; i++)
		arr[i] = rand() % ARR_LENGTH;

	LARGE_INTEGER  num;
	long long start, end, freq;
	QueryPerformanceFrequency(&num);
	freq = num.QuadPart;

	QueryPerformanceCounter(&num);
	start = num.QuadPart;

	//ѡ������
	//mySelectionSort(arr, ARR_LENGTH);
	//��������
	//myInsertSort(arr, ARR_LENGTH);
	//�Ż���Ĳ�������
	//myOptimizedInsertSort(arr, ARR_LENGTH);
	//ð������
	//myBubbulSort(arr, ARR_LENGTH);
	//�Ż����ð������
	//myOptimizedBubulSort(arr, ARR_LENGTH);
	//ϣ������
	//myShellSort(arr, ARR_LENGTH);
	//ʹ��knuth������е�ϣ������
	myKnuthShellSort(arr, ARR_LENGTH);

	QueryPerformanceCounter(&num);
	end = num.QuadPart;

	printf("Sort Finished.\nCheck if the array is in Order...\n");

	char* isSorted = checkOrder(arr, ARR_LENGTH) ? "true" : "fales";

	printf("isSorted:%s", isSorted);

	printf("\n====================\n");
	printf("time=%lld\n", (end - start) * 1000 / freq);
	system("pause");
}

int main(void) {

	//mySort();

	checkAvgSortTime(SORT_TIMES);
	
	return 0;
}