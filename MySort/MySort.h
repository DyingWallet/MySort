#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<Windows.h>

//ѧϰ����д�������㷨
//0����������Ƿ�����
bool checkOrder(int* arr, int length);

//1��ѡ������
void mySelectionSort(int*,int);

//2.1����������
void myInsertSort(int*, int);

//2.2����������-�Ż���
void myOptimizedInsertSort(int*, int);

//3.1��ð������
void myBubbulSort(int*, int);

//3.2��ð������--�Ż���
void myOptimizedBubulSort(int*, int);

//4��ϣ������
void myShellSort(int*, int);

//4.1��ʹ��knuth������е�ϣ������
void myKnuthShellSort(int*, int);