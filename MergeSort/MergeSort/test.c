#include"MergeSort.h"

int main()
{
	int a[] = { 5, 3, 9, 6, 2, 4, 7, 1, 8 };
	//int a[] = {100,101,109,105,101,105 };
	//int a[] = { 5, 3, 9, 6, 2 };
	int n = sizeof(a) / sizeof(int);
	printf("����ǰ��");
	PrintArr(a, n);

	//QuickSort(a, 0, n - 1);
	//QuickSortNonR(a, 0, n - 1);
	MergeSort(a, n);
	//CountSort(a, n);

	printf("�����");
	PrintArr(a, n);


	return 0;
}