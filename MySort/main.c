#include"MySort.h"

#define ARR_LENGTH 50000

int main(void) {

	srand((unsigned)time(NULL)); //�õ�ǰϵͳʱ����������

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