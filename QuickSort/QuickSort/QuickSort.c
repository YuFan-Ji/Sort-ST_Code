#include"QuickSort.h"
#include"Stack.h"

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

//hoare�汾
int _QuickSort1(int* arr, int left, int right)
{
	int keyi = left;
	left++;
	while (left <= right)
	{
		while (left <= right && arr[right] > arr[keyi])
		{
			right--;
		}

		while (left <= right && arr[left] < arr[keyi])
		{
			left++;
		}

		if (left <= right)
		{
			Swap(&arr[left++], &arr[right--]);
		}
	}
	Swap(&arr[keyi], &arr[right]);
	return right;
}


//�ڿӷ�
int _QuickSort2(int* arr, int left, int right)
{
	int key = arr[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && arr[right] > key)
		{
			right--;
		}
		if (left < right)
		{
			arr[hole] = arr[right];
			hole = right;
		}

		while (left < right && arr[left] < key)
		{
			left++;
		}
		if (left < right)
		{
			arr[hole] = arr[left];
			hole = left;
		}

	}
	arr[hole] = key;

	return hole;
}

//lomutoǰ��ָ�뷨
int _QuickSort3(int* arr, int left, int right)
{
	int keyi = left;
	int prev = left, cur = left + 1;

	while (cur <= right)
	{
		if (arr[cur] < arr[keyi] && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}

	Swap(&arr[keyi], &arr[prev]);
	return prev;
}



//ʹ�õݹ�ķ���
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int keyi = _QuickSort3(arr, left, right);
	QuickSort(arr, left, keyi - 1);
	QuickSort(arr, keyi + 1, right);
}

//ʹ�ñ����ķ���
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

		//���ݻ�׼ֵ������������
		//�����䣺[begin,keyi-1]
		//�����䣺[keyi+1,end]
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

//�鲢����

void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}
}

void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}