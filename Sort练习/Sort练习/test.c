#include"Sort.h"

int main()
{
	int a[] = { 5, 3, 9, 6, 2, 4, 7, 1, 8 };
	int n = sizeof(a) / sizeof(int);
	printf("����ǰ��");
	PrintArr(a, n);

	QuickSortNonR(a,0,n-1);

	printf("�����");
	PrintArr(a, n);

	return 0;
}