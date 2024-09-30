#include"Heap.h"

//�ѵĳ�ʼ��
void HPInit(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->capacity = php->size = 0;
}

//�ѵ�����
void HPDestroy(HP* php)
{
	if (php->arr)
	{
		free(php->arr);
	}
	php->arr = NULL;
	php->capacity = php->size = 0;
}


//������������
void Swap(int* x, int* y)
{
	int tem = *x;
	*x = *y;
	*y = tem;
}



//�����������ϵ���
void AdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)//����Ҫ���ڣ�childֻҪ�ߵ����ڵ��λ�ã����ڵ�û�и��ڵ㲻��Ҫ����
	{
		if (arr[child] < arr[parent])
		{
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}

//�����в���Ԫ��
void HPPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tem = (HPDataType*)realloc(php->arr, newcapacity * sizeof(HPDataType));
		if (tem == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}

		php->arr = tem;
		php->capacity = newcapacity;
	}

	php->arr[php->size] = x;
	AdjustUp(php->arr, php->size);
	php->size++;
}


//�ж϶��������Ƿ�Ϊ��
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}


//���µ���
void Adjustdown(HPDataType* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//ɾ���������ݣ�ɾ���ǶѶ�������
void HPPop(HP* php)
{
	assert(php);
	assert(!HPEmpty(php));
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	Adjustdown(php->arr, 0, php->size);
}

//��ȡ�Ѷ�����
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(!HPEmpty(php));

	return php->arr[0];

}
