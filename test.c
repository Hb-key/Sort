#include"Sort.h"

int main()
{

	int array[] = { 1,3,4,8,9,2,5,6,7,0 };
	int size = sizeof(array) / sizeof(array[0]);
	MergeSort(array, size);
	PrintArray(array, size);
	return 0;
}