#include <stdio.h>
#include <stdlib.h>
#include "print_swap.h"
// ��ӡ����
void PrintArray(int *a, int n){
	int i = 0;
	for (i = 0; i < n; i++){
		printf("%d  ", a[i]);
	}
	printf("\n");
}
// ��������Ԫ��
void swap(int *a, int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}