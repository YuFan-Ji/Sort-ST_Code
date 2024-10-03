#include"QuickSort.h"

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// ��ֵȡ�к���
int MedianOfThree(int* arr, int left, int right)
{
	int mid = left + (right - left) / 2;

	// �Ƚϲ�������ȷ�� arr[left] <= arr[mid] <= arr[right]
	if (arr[left] > arr[mid])
		Swap(&arr[left], &arr[mid]);
	if (arr[left] > arr[right])
		Swap(&arr[left], &arr[right]);
	if (arr[mid] > arr[right])
		Swap(&arr[mid], &arr[right]);

	// ʹ���м�ֵ��Ϊ��׼ֵ���������Ƶ� left λ��
	Swap(&arr[left], &arr[mid]);

	return arr[left]; // ���ػ�׼ֵ
}

void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	
	int begin = left, end = right;
	// ���ѡkey
	//int randi = left + (rand() % (right - left + 1));
	//Swap(&arr[left], &arr[randi]);
	//int key = arr[left];


	//��ֵȡ��ѡkey
	int key = MedianOfThree(arr, left, right);
	int cur = left + 1;

	while (cur <= right)
	{
		if (arr[cur] < key)
		{
			Swap(&arr[left], &arr[cur]);
			left++;
			cur++;
		}
		else if (arr[cur] > key)
		{
			Swap(&arr[right], &arr[cur]);
			right--;
		}
		else if (arr[cur] == key)
		{
			cur++;
		}
	}


	// [begin, left-1] [left, right] right+1, end]
	QuickSort(arr, begin, left - 1);
	QuickSort(arr, right + 1, end);
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
	srand(time(0));
	QuickSort(nums, 0, numsSize - 1);
	*returnSize = numsSize;
	return nums;
}