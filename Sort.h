#pragma once

#include<stdio.h>

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


int Partition_1(int array[], int left, int right)//左右下标
{
	int begin = left;
	int end = right;
	int pivot = array[right];

	while (begin < end)
	{
		while (begin < end&&array[begin] <= pivot)
		{
			begin++;
		}
		while (begin < end&&array[end] >= pivot)
		{
			end--;
		}
		Swap(array + begin, array + end);
	}
	Swap(array + begin, array + right);
	return begin;
}


int Partition_2(int array[], int left, int right)//挖坑
{
	int begin = left;
	int end = right;
	int pivot = array[right];

	while (begin < end)
	{
		while (begin < end&&array[begin] <= pivot)
		{
			begin++;
		}
		array[end] = array[begin];
		while (begin < end&&array[end] >= pivot)
		{
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = pivot;
	return begin;
}

int Partition_3(int array[], int left, int right)//前后指针
{
	int div = left;
	int pivot = array[right];
	for (int cur = left; cur <= right; cur++)
	{
		if (array[cur] < pivot)
		{
			Swap(array + cur, array + div);
			div++;
		}
	}
	Swap(array + div, array + right);
	return div;
}

void _QuickSort(int array[], int left, int right)
{
	if (left == right)
	{
		return;
	}
	if (left > right)
	{
		return;
	}
	int div = Partition_3(array, left, right);
	_QuickSort(array, left, div - 1);
	_QuickSort(array, div + 1, right);
}


void QuickSort(int array[], int size)
{
	_QuickSort(array, 0, size - 1);
}

void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		int flag = 0;
		for (int j = 0; j < size-1-i; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array + j, array + j + 1);	
			}
			flag++;
		}
		if (flag == 1)
		{
			return;
		}
	}
}


void 
