#include"MySort.h"

/*
����˼·��
	ð�������Ǿ��������㷨�нϼ򵥵�һ�֣�
	����ÿ�α����ж�������Ԫ�ؽ��бȽϣ�
	�ж���˳���Ƿ����Ŀ��˳��
	�粻���������λ�ý�����
	��ÿһ�������ı��������У�
	����ʹ���С��Ԫ���������ϸ�����������ˡ�
	�����ظ��������ֱ���������������У�
	����ɶ��������е�����ʹ������������
*/

//ð������
void myBubbulSort(int* arr, int length) {

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length -1; j++) {
			if (arr[j+1] < arr[j]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//�Ż����ð������
void myOptimizedBubulSort(int* arr, int length) {

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j + 1] < arr[j]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}