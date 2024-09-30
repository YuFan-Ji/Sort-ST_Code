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

//ֱ�Ӳ�������
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



//ϣ������
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








//ð������
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int exchange = 0;

		for (int j = 0; j < n - 1 - i; j++)
		{
			//������
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


//ѡ������
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


//�һ�׼ֵ
int _QuickSort(int* arr, int left, int right)
{
	int keyi = left;
	left++;
	//���ڴ�����left��right,left���������Ҵ�right����������С
	//����1����û�е���?  ���У�Ϊ��ƽ������������ɶ��ֵ�����Ϊ����right����ǰ��һ��
	while (left <= right)
	{
		//����2����û�е���?    ��û�У���������Ԫ��ȫ�����ǻ�׼ֵ����ôÿ�εݹ�֮�ֳ�ȥһ������
		//����3: ΪʲôҪ��left <= right����Ϊleft<=right�Ϳ��Խ����˲���ѭ����
		while (left <= right && arr[right] > arr[keyi])
		{
			right--;
		}
		while (left <= right && arr[left] < arr[keyi])
		{
			left++;
		}
		

		//����������ѭ��֮�󣬾ʹ��� left �� right ���ҵ��˸��Ե�ֵ�����û�ҵ�Ҳ��Խ����
		if (left <= right)
		{
			Swap(&arr[left++], &arr[right--]);
		}
	}
	//���˴��whileѭ���ʹ���left�Ѿ�����right��,��ô����Ҫ����rightλ�õ�ֵ�ͱ���Ļ�׼ֵ
	Swap(&arr[keyi], &arr[right]);

	//rightλ�þ������ǵĻ�׼ֵ�±�
	return right;
}

//��������
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int keyi = _QuickSort(arr, left, right);
	//��������������
	QuickSort(arr, left, keyi - 1);
	//��������������
	QuickSort(arr, keyi + 1, right);

}

//������
void HeapSort(int* arr, int n)
{
	//����
	//����---���
	//����----С��


	//for (int i = 0; i < n; i++)
	//{
	//	AdjustUp(arr, i);
	//}

	//���µ����㷨����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(arr, i, n);
	}

	//ѭ�����Ѷ����ݸ����λ�ã���仯��ÿ�μ���һ�����ݣ������ݽ��н���
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		Adjustdown(arr, 0, end);
		end--;
	}
}