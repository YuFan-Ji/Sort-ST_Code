#include"Sort.h"
#include"Heap.h"


void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
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
					end -= gap;
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


//选择排序
void SelectSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}
		if (maxi == begin)
		{
			maxi = mini;
		}

		Swap(&arr[mini], &arr[begin]);
		Swap(&arr[maxi], &arr[end]);

		begin++;
		end--;
	}
}


//找基准值
int _QuickSort(int* arr, int left, int right)
{
	int keyi = left;
	left++;
	//对于传来的left与right,left从左往右找大，right从右往左找小
	//问题1：有没有等于?  答：有，为了平衡左右子树达成二分的作用为了让right在往前走一格
	while (left <= right)
	{
		//问题2：有没有等于?    答：没有，假设数组元素全部都是基准值，那么每次递归之分出去一个数据
		//问题3: 为什么要加left <= right，因为left<=right就可以结束了不用循环了
		while (left <= right && arr[right] > arr[keyi])
		{
			right--;
		}
		while (left <= right && arr[left] < arr[keyi])
		{
			left++;
		}
		

		//出了这两个循环之后，就代表 left 与 right 都找到了各自的值，如果没找到也就越界了
		if (left <= right)
		{
			Swap(&arr[left++], &arr[right--]);
		}
	}
	//出了大的while循环就代表left已经超过right了,那么就需要交换right位置的值和保存的基准值
	Swap(&arr[keyi], &arr[right]);

	//right位置就是我们的基准值下标
	return right;
}

//快速排序
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int keyi = _QuickSort(arr, left, right);
	//遍历它的左子树
	QuickSort(arr, left, keyi - 1);
	//遍历它的右子树
	QuickSort(arr, keyi + 1, right);

}

//堆排序
void HeapSort(int* arr, int n)
{
	//建堆
	//升序---大堆
	//降序----小堆


	//for (int i = 0; i < n; i++)
	//{
	//	AdjustUp(arr, i);
	//}

	//向下调整算法建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(arr, i, n);
	}

	//循环将堆顶数据跟最后位置（会变化，每次减少一个数据）的数据进行交换
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		Adjustdown(arr, 0, end);
		end--;
	}
}