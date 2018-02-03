#include <stdio.h>
#include <stdlib.h>
#include "print_swap.h"
#include "sort.h"

// ѡ������
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

// ��������
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

// ð������
void BubbleSort(int *a, int n){
	int i, j;
	for (i = 0; i < n; i++){
		for (j = n - 2; j >= i; j--){
			if (a[j + 1] < a[j]) swap(a, j, j + 1);
		}
	}
}

// ϣ������
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

// ������ a[low...high] ���п��Ż��֣����ػ�׼Ԫ�ص�λ��
int Partition(int *a, int low, int high){
	int pivot = a[low]; // �����еĵ�һ��Ԫ��Ϊ��׼
	while (low < high){
		while ((low < high) && (a[high] >= pivot)) high--;
		swap(a, low, high);
		while ((low < high) && (a[low] <= pivot)) low++;
		swap(a, low, high);
	}
	return low;
}
// ������ a[low...high] ���п�������
void QSort(int *a, int low, int high){
	if (low < high){
		int pivot = Partition(a, low, high);
		QSort(a, low, pivot - 1);
		QSort(a, pivot + 1, high);
	}
}
// ��������
void QuickSort(int *a, int n){
	QSort(a, 0, n - 1);
}

// ���������� src[low...mid] �� src[mid+1...high] ���ж�·�鲢������des[]��
void Merge(int *src, int *des, int low, int mid, int high){
	int i = low, j = mid + 1, k = low;
	while ((i <= mid) && (j <= high)){
		if (src[i] <= src[j]) des[k++] = src[i++];
		else des[k++] = src[j++];
	}
	while (i <= mid) des[k++] = src[i++];
	while (j <= high) des[k++] = src[j++];
}
// ������ src[low...high] ���й鲢���򣬲����ź����Ԫ�ش��� des[] ��
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
// �鲢����
void MergeSort(int *a, int n){
	/*int i = 0;
	int *b = (int *)malloc(sizeof(int)*n);
	MSort(a, b, 0, n - 1, n);
	for (i = 0; i < n; i++) a[i] = b[i];
	free(b);*/
	MSort(a, a, 0, n - 1, n);
}
// �鲢����ǵݹ��㷨
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

// ������ a[low...high] ����Ϊ�󶥶ѣ�������ֻ��һ��Ԫ���ƻ��˶ѹ�ϵ���� a[low] �ⶼ����ѹ�ϵ
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
// ������
void HeapSort(int *a, int n){
	int i;
	// ����
	for (i = n / 2 - 1; i >= 0; i--) HeapAdjust(a, i, n - 1);
	for (i = n - 1; i > 0; i--){
		swap(a, 0, i);
		HeapAdjust(a, 0, i - 1);
	}
}