#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<Windows.h>

//学习所编写的排序算法
//0、检查数组是否有序
bool checkOrder(int* arr, int length);

//1、选择排序
void mySelectionSort(int*,int);

//2.1、插入排序
void myInsertSort(int*, int);

//2.2、插入排序-优化版
void myOptimizedInsertSort(int*, int);

//3.1、冒泡排序
void myBubbulSort(int*, int);

//3.2、冒泡排序--优化版
void myOptimizedBubulSort(int*, int);

//4、希尔排序
void myShellSort(int*, int);

//4.1、使用knuth间隔序列的希尔排序
void myKnuthShellSort(int*, int);