#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print_swap.h"
#include "sort.h"

/*
	数据量          10,000	100,000		1000,000	10,000,000	100,000,000

	冒泡            0.757	78.56
	选择            0.110	10.90
	插入            0.068	7.199

	归并（递归）		0.371	22.90
	堆排序			0.004	0.055		0.689		10.12		140.2
	快速排序			0.003	0.031		0.373		5.884		栈溢出
	希尔排序			0.001	0.018		0.243		3.389		43.15
	归并（非递归）	0.001	0.017		0.180		2.039		23.81

*/

#define LEN 100000000

void main(){
	int i;
	int *a = (int *)malloc(sizeof(int)*LEN);
	double st, ft;
	//time_t tms;
	//srand((unsigned int)time(&tms));
	
	/*
	for (i = 0; i < LEN; i++) a[i] = rand();
	st = clock();
	SelectSort(a, LEN);
	ft = clock();
	printf("选择排序用时%lf秒\n", (ft - st) / CLOCKS_PER_SEC);

	for (i = 0; i < LEN; i++) a[i] = rand();
	st = clock();
	InsertSort(a, LEN);
	ft = clock();
	printf("插入排序用时%lf秒\n", (ft - st) / CLOCKS_PER_SEC);

	for (i = 0; i < LEN; i++) a[i] = rand();
	st = clock();
	BubbleSort(a, LEN);
	ft = clock();
	printf("冒泡排序用时%lf秒\n", (ft - st) / CLOCKS_PER_SEC);
	*/
	for (i = 0; i < LEN; i++) a[i] = rand();
	st = clock();
	ShellSort(a, LEN);
	ft = clock();
	printf("希尔排序用时%lf秒\n", (ft - st) / CLOCKS_PER_SEC);
	/*
	for (i = 0; i < LEN; i++) a[i] = rand();
	st = clock();
	QuickSort(a, LEN);
	ft = clock();
	printf("快速排序用时%lf秒\n", (ft - st) / CLOCKS_PER_SEC);
	
	for (i = 0; i < LEN; i++) a[i] = rand();
	st = clock();
	MergeSort(a, LEN);
	ft = clock();
	printf("归并排（递归）序用时%lf秒\n", (ft - st) / CLOCKS_PER_SEC);
	*/
	for (i = 0; i < LEN; i++) a[i] = rand();
	st = clock();
	MergeSortNonRecursive(a, LEN);
	ft = clock();
	printf("归并排序（非递归）用时%lf秒\n", (ft - st) / CLOCKS_PER_SEC);

	for (i = 0; i < LEN; i++) a[i] = rand();
	st = clock();
	HeapSort(a, LEN);
	ft = clock();
	printf("堆排序用时%lf秒\n", (ft - st) / CLOCKS_PER_SEC);
	system("pause");
}