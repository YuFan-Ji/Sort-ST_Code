#include"Sort.h"
#include"Stack.h"

void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

//直接插入排序
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tem = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tem)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tem;
	}
}


//希尔排序
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tem = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tem)
				{
					arr[end + gap] = arr[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tem;
		}
	}
}

void Swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}

// 选择排序
void SelectSort(int* a, int n) 
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini, maxi;
		mini = maxi = begin;
		for (int i = begin + 1; i < end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

		}
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[begin], &a[mini]);
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}


// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[root])
		{
			Swap(&a[child], &a[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}


//冒泡排序
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int exchange = 0;

		for (int j = 0; j < n - 1 - i; j++)
		{
			//排升序
			if (arr[j] > arr[j + 1])
			{
				exchange = 1;
				Swap(&arr[j], &arr[j + 1]);
			}
		}

		if (exchange == 0)
		{
			break;
		}
	}
}


int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	left++;
	while (left <= right)
	{
		while (left <= right && a[right] > a[keyi])
		{
			right--;
		}
		while (left <= right && a[left] < a[keyi])
		{
			left++;
		}
		if (left <= right)
		{
			Swap(&a[left++], &a[right--]);
		}

	}
	Swap(&a[keyi], &a[right]);
	return right;
}

// 快速排序hoare版本
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return ;
	}
	int keyi = PartSort3(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
	return ;
}


// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int hole = left;
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] > key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] < key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
	

}


// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int prev = left;
	int pcur = left + 1;
	while (pcur <= right)
	{
		if (a[pcur] < a[keyi] && ++prev != pcur)
		{
			Swap(&a[prev], &a[pcur]);
		}
		pcur++;
	}
	Swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}


// 快速排序 非递归实现

void QuickSortNonR(int* arr, int left, int right)
{
	ST st;
	STInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int keyi = begin;
		int prev = begin;
		int cur = begin + 1;

		while (cur <= end)
		{
			if (arr[cur] < arr[keyi] && ++prev != cur)
			{
				Swap(&arr[prev], &arr[cur]);
			}
			cur++;
		}
		Swap(&arr[keyi], &arr[prev]);

		keyi = prev;
		if (keyi + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}

		if (keyi - 1 > begin)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}
	}


	STDestroy(&st);
}