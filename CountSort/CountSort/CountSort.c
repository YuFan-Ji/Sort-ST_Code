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


// ��������
void CountSort(int* arr, int n)
{
	int max = arr[0], min = arr[0];

	//�������Сֵ
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	//����������ռ��С
	int range = max - min + 1;

	int* count = (int*)malloc(range * sizeof(int));
	if (count == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}

	//��ʼ��range���������е�����Ϊ0
	memset(count, 0, sizeof(int) * range);

	//ԭ�����±��ΪԪ�أ�ԭ����(Ԫ�� - min) ��Ϊ�±꣬���ּ����µ�Ԫ�ؾͼӼ���
	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++;
	}

	//���ź����Ԫ�طŻ�ԭ����
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			arr[index++] = i + min;
		}
	}
}