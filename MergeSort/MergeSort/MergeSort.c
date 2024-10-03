#include"MergeSort.h"

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
	//index Ϊtmp�±꣬��һ����0��������߽�
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
}


/*
�ǵݹ�������ݹ������෴����һ��Ԫ��������Ԫ�ع����������飬
�����Ա����鹹���������飬ֱ��������������
Ҫ��midָ�봫�룬��Ϊ����һ������ʱ�����¼���mid���ֻ�������
��Ҫָ��mid��λ��
*/
void merge(int* a, int left, int mid, int right, int* tmp)
{
	// [left, mid]
	// [mid+1, right]
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

/*
k������ʾÿ��k��Ԫ�ع鲢
*/
void mergePass(int* arr, int k, int n, int* temp)
{
	int i = 0;
	//��ǰ����,��2������Ϊk�������кϲ�Ϊ1��
	while (i < n - 2 * k + 1)
	{
		merge(arr, i, i + k - 1, i + 2 * k - 1, temp);
		i += 2 * k;
	}
	//�ϲ�����[i, n - 1]�������벿��[i, i + k - 1]�Լ�����һ���������Ұ벿��[i + k, n - 1]
	if (i < n - k)
	{
		merge(arr, i, i + k - 1, n - 1, temp);
	}

}