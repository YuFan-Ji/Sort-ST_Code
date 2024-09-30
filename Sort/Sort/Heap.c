#include"Heap.h"

//堆的初始化
void HPInit(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->capacity = php->size = 0;
}

//堆的销毁
void HPDestroy(HP* php)
{
	if (php->arr)
	{
		free(php->arr);
	}
	php->arr = NULL;
	php->capacity = php->size = 0;
}


//交换堆中数据
void Swap(int* x, int* y)
{
	int tem = *x;
	*x = *y;
	*y = tem;
}



//堆中数据向上调整
void AdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)//不需要等于，child只要走到根节点的位置，根节点没有父节点不需要交换
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

//往堆中插入元素
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


//判断堆中数据是否为空
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}


//向下调整
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

//删除堆中数据，删的是堆顶的数据
void HPPop(HP* php)
{
	assert(php);
	assert(!HPEmpty(php));
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	Adjustdown(php->arr, 0, php->size);
}

//获取堆顶数据
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(!HPEmpty(php));

	return php->arr[0];

}
