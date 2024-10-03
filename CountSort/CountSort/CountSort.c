#include"CountSort.h"

void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


// 计数排序
void CountSort(int* arr, int n)
{
	int max = arr[0], min = arr[0];

	//找最大最小值
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	//定义新数组空间大小
	int range = max - min + 1;

	int* count = (int*)malloc(range * sizeof(int));
	if (count == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}

	//初始化range数组中所有的数据为0
	memset(count, 0, sizeof(int) * range);

	//原来的下标成为元素，原来的(元素 - min) 成为下标，出现几次新的元素就加几次
	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++;
	}

	//把排好序的元素放回原数组
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			arr[index++] = i + min;
		}
	}
}