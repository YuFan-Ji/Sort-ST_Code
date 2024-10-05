#include"introsort.h"

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出左右孩⼦中⼤的那⼀个
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	// 建堆 -- 向下调整建堆 -- O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	// ⾃⼰先实现 -- O(N*logN)

		int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);
		--end;
	}
}
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		// 将tmp插⼊到[0,end]区间中，保持有序
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// 三值取中函数
int MedianOfThree(int* arr, int left, int right)
{
	int mid = left + (right - left) / 2;

	// 比较并交换，确保 arr[left] <= arr[mid] <= arr[right]
	if (arr[left] > arr[mid])
		Swap(&arr[left], &arr[mid]);
	if (arr[left] > arr[right])
		Swap(&arr[left], &arr[right]);
	if (arr[mid] > arr[right])
		Swap(&arr[mid], &arr[right]);

	// 使用中间值作为基准值，并将其移到 left 位置
	Swap(&arr[left], &arr[mid]);

	return arr[left]; // 返回基准值
}

void IntroSort(int* a, int left, int right, int depth, int defaultDepth)
{
	if (left >= right)
		return;

	// 数组⻓度⼩于16的⼩数组，换为插⼊排序，简单递归次数
	if (right - left + 1 < 16)
	{
		InsertSort(a + left, right - left + 1);
		return;
	}
	// 当深度超过2*logN时改⽤堆排序
	
		if (depth > defaultDepth)
		{
			HeapSort(a + left, right - left + 1);
			return;
		}
	depth++;
	int begin = left;
	int end = right;
	// 随机选key
	int randi = left + (rand() % (right - left + 1));
	Swap(&a[left], &a[randi]);
	//也可以三值取中选key
	//int key = MedianOfThree(arr, left, right);
	int prev = left;
	int cur = prev + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	// [begin, keyi-1] keyi [keyi+1, end]
	IntroSort(a, begin, keyi - 1, depth, defaultDepth);
	IntroSort(a, keyi + 1, end, depth, defaultDepth);
}
void QuickSort(int* a, int left, int right)
{
	int depth = 0;
	int logn = 0;
	int N = right - left + 1;
	for (int i = 1; i < N; i *= 2)
	{
		logn++;
	}
	
		// introspective sort -- ⾃省排序
	 IntroSort(a, left, right, depth, logn * 2);

}
 int* sortArray(int* nums, int numsSize, int* returnSize)
 {
	 srand(time(0));
	 QuickSort(nums, 0, numsSize - 1);
	
	 * returnSize = numsSize;
	 return nums;
	
 }