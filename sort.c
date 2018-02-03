#include <stdio.h>
#include <stdlib.h>
#include "print_swap.h"
#include "sort.h"

// 选择排序
void SelectSort(int *a, int n){
	int i, j, k = -1;
	for (i = 0; i < n; i++){
		k = i;
		for (j = i + 1; j < n; j++){
			if (a[k]>a[j]) k = j;
		}
		swap(a, i, k);
	}
}

// 插入排序
void InsertSort(int *a, int n){
	int i, j;
	int k = -1, temp = -1;
	for (i = 1; i < n; i++){
		temp = a[i];
		k = i;
		for (j = i - 1; (j >= 0) && (a[j] > temp); j--){
			a[j + 1] = a[j];
			k = j;
		}
		a[k] = temp;
	}
}

// 冒泡排序
void BubbleSort(int *a, int n){
	int i, j;
	for (i = 0; i < n; i++){
		for (j = n - 2; j >= i; j--){
			if (a[j + 1] < a[j]) swap(a, j, j + 1);
		}
	}
}

// 希尔排序
void ShellSort(int *a, int n){
	int i, j;
	int k = -1, temp = -1;
	int gap = n;
	do{
		gap = gap / 3 + 1;
		for (i = gap; i<n; i++){
			temp = a[i];
			k = i;
			for (j = i - gap; (j >= 0) && (a[j]>temp); j -= gap){
				a[j + gap] = a[j];
				k = j;
			}
			a[k] = temp;
		}
	} while (gap > 1);
}

// 对区间 a[low...high] 进行快排划分，返回基准元素的位置
int Partition(int *a, int low, int high){
	int pivot = a[low]; // 以序列的第一个元素为基准
	while (low < high){
		while ((low < high) && (a[high] >= pivot)) high--;
		swap(a, low, high);
		while ((low < high) && (a[low] <= pivot)) low++;
		swap(a, low, high);
	}
	return low;
}
// 对区间 a[low...high] 进行快速排序
void QSort(int *a, int low, int high){
	if (low < high){
		int pivot = Partition(a, low, high);
		QSort(a, low, pivot - 1);
		QSort(a, pivot + 1, high);
	}
}
// 快速排序
void QuickSort(int *a, int n){
	QSort(a, 0, n - 1);
}

// 对有序序列 src[low...mid] 和 src[mid+1...high] 进行二路归并，存入des[]中
void Merge(int *src, int *des, int low, int mid, int high){
	int i = low, j = mid + 1, k = low;
	while ((i <= mid) && (j <= high)){
		if (src[i] <= src[j]) des[k++] = src[i++];
		else des[k++] = src[j++];
	}
	while (i <= mid) des[k++] = src[i++];
	while (j <= high) des[k++] = src[j++];
}
// 对序列 src[low...high] 进行归并排序，并将排好序的元素存入 des[] 中
void MSort(int *src, int *des, int low, int high, int n){
	if (low == high) des[low] = src[low];
	else{
		int *space = (int *)malloc(sizeof(int)*n);
		int mid = (high + low) / 2;
		MSort(src, space, low, mid, n);
		MSort(src, space, mid + 1, high, n);
		Merge(space, des, low, mid, high);
		free(space);
	}
}
// 归并排序
void MergeSort(int *a, int n){
	/*int i = 0;
	int *b = (int *)malloc(sizeof(int)*n);
	MSort(a, b, 0, n - 1, n);
	for (i = 0; i < n; i++) a[i] = b[i];
	free(b);*/
	MSort(a, a, 0, n - 1, n);
}
// 归并排序非递归算法
void MergeSortNonRecursive(int *a, int n){
	int i = 0, step = 1;
	int *b = (int *)malloc(sizeof(int)*n);
	while (step < n){
		for (i = 0; i < n; i += 2 * step){
			int mid = i + step - 1;
			int high = i + 2 * step - 1;
			if (mid>n - 1) mid = high = n - 1;
			else high = high <= n - 1 ? high : n - 1;
			Merge(a, b, i, mid, high);
		}
		for (i = 0; i < n; i++) a[i] = b[i];
		step *= 2;
	}
	free(b);
}

// 将序列 a[low...high] 调整为大顶堆，即堆中只有一个元素破坏了堆关系，除 a[low] 外都满足堆关系
void HeapAdjust(int *a, int low, int high){
	int key;
	key = 2 * low + 1;
	while (key < high){
		if ((key < high) && (a[key] < a[key + 1])) key++;
		if (a[low] < a[key]){
			swap(a, low, key);
			low = key;
			key = 2 * low + 1;
		}
		else break;
	}
}
// 堆排序
void HeapSort(int *a, int n){
	int i;
	// 建堆
	for (i = n / 2 - 1; i >= 0; i--) HeapAdjust(a, i, n - 1);
	for (i = n - 1; i > 0; i--){
		swap(a, 0, i);
		HeapAdjust(a, 0, i - 1);
	}
}