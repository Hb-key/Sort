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


int Partition_2(int array[], int left, int right)//挖坑法
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
//快速排序
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
//冒泡排序
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


void InsertSort(int array[], int size)
{ 
	for (int i = 1; i < size; i++)
	{
		if (array[i] < array[i - 1]) 
		{
			int j = i - 1;
			int tmp = array[i];
			while (tmp < array[j]) 
			{
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = tmp;
		}
	}
}

void __InsertSort(int array[], int size, int gap)
{
	for (int g = 0; g < gap; g++)
	{
		int i, j;
		int tmp;
		for (i = gap + g; i < size; i += gap)
		{
			tmp = array[i];
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (tmp >= array[j])
				{
					break;
				}
				else
				{
					array[j + gap] = array[j];
				}
			}
			array[j + gap] = tmp;
		}
	}
}

void ShellSort(int array[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;
		__InsertSort(array, size, gap);

		if (gap == 1)
		{
			break;
		}
	}
}

void SelectSort(int array[], int size)//找最大的数
{
	for (int i = 1; i < size; i++)
	{
		int max = 0;
		for (int j = 1; j < i; j++)
		{
			if (array[j] > array[max])
				max = j;
		}
		Swap(array + max, array + i - 1);
	}
}

void SelectSortOP(int array[], int size)//最大最小一起找 
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int min = left;
		int max = left;
		for (int j = left + 1; j <= right; j++)
		{
			if (array[j] > array[max])
			{
				max = j;
			}
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		Swap(array + left, array + min);
		if (max = left)
		{
			max = min;
		}
		Swap(array + right, array + max);
	}
}

void AdjustDown(int array[],int size,int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	//左孩子越界
	if (left >= size)
	{
		return;
	}
	//假设左孩子最大
	int max = left;
	//存在右孩子，右>左
	if (right < size && array[right] > array[left])
	{
		max = right;	
	}
	if (array[root] >= array[max])
	{
		return;
	}
	Swap(array + root, array + max);
	AdjustDown(array, size, max);
}

void CreateHeap(int array[], int size)
{
	//最后一个非叶子节点(最后一个结点的双亲节点)->0
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
}

void HeapSort(int array[], int size)//升序建大堆
{
	CreateHeap(array, size);
	for (int i = 0; i < size; i++)
	{
		Swap(&array[0], &array[size - i - 1]);
		AdjustDown(array, size - 1 - i, 0);
	}
}
#include<malloc.h>
//void Merge(int array[], int Temp[], int L, int R, int RightEnd)//合并两个有序序列
//{
//	int LeftEnd = R - 1;
//	int p = L, i;
//	int num = RightEnd - L + 1;
//	while (L <= LeftEnd && R <= RightEnd)
//		if (array[L] <= array[R])
//			Temp[p++] = array[L++];
//		else
//			Temp[p++] = array[R++];
//	while (L <= LeftEnd)
//		Temp[p++] = array[L++];
//	while (R <= RightEnd)
//		Temp[p++] = array[R++];
//	for (i = 0; i<num; i++, RightEnd--)
//		array[RightEnd] = Temp[RightEnd];
//}

//void MSort(int array[], int Temp[], int L, int RightEnd)
//{
//	int center;
//	if (L<RightEnd)
//	{
//		center = (L + RightEnd) / 2;
//		MSort(array, Temp, L, center);
//		MSort(array, Temp, center + 1, RightEnd);
//		Merge(array, Temp, L, center + 1, RightEnd);
//	}
//}

//void MergeSort(int array[], int size)
//{
//	int *Temp = (int *)malloc(size * sizeof(int));
//	if (Temp)
//	{
//		MSort(array, Temp, 0, size - 1);
//		free(Temp);
//	}
//}
void Merge(int array[], int left, int mid, int right, int extra[])
{
	int left_i = left;//[left,mid)
	int right_i = mid;//[mid,right)
	int extra_i = left;
	while (left_i < mid && right_i < right)
	{
		if (array[left_i] <= array[right_i])
		{
			extra[extra_i++] = array[left_i++];
		}
		else
		{
			extra[extra_i++] = array[right_i++];
		}
	}
	while (left_i < mid)
	{
		extra[extra_i++] = array[left_i++];
	}
	while (right_i < right)
	{
		extra[extra_i++] = array[right_i++];
	}
	for (int i = left; i < right; i++)
	{
		array[i] = extra[i];
	}
}

void __MergeSort(int array[], int left, int right,int extra[])
{
	if (left == right - 1)
	{
		return;
	}
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);
	Merge(array, left, mid, right, extra);
}
//归并
void MergeSort(int array[], int size)
{
	int *extra = (int *)malloc(sizeof(int)*size);
	__MergeSort(array, 0, size, extra);
	free(extra);
}
