#include"Sort.h"

int main()
{

	int array[] = { 1,3,4,8,9,2,4,6,7,0,3 };
	int size = sizeof(array) / sizeof(array[0]);
	QuickSort(array, size);
	PrintArray(array, size);
	return 0;
}