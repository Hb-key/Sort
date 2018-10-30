#include<stdio.h>
void Swap(int *a, int *b)
{
	int *tmp = a;
	a = b;
	b = tmp;
}

int Partition_1(int array[], int left, int right)//×óÓÒÏÂ±ê
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


int Partition_2(int array[], int left, int right)//ÍÚ¿Ó
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

void Quick(int array[], int left, int right)
{
	if (left > right || left == right)
	{
		return;
	}
	int div = Partition_1(array, left, right);
	Quick(array, left, div - 1);
	Quick(array, div + 1, right);
}


void test()
{
	
	int array[] = { 1,3,4,8,9,2,4,6,7,0,3 };
	int size = sizeof(array) / sizeof(array[0]);
	int left = 0, right = size - 1;
	Quick(array, left, right);
	for (int i = 0; i < 11; i++)
	{
		printf("%d ", array[i]);
	}
}


int main()
{
	test();
	return 0;
}