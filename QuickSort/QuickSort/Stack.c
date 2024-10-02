#include"Stack.h"

//栈的初始化
void STInit(ST* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//栈的销毁
void STDestroy(ST* ps)
{
	assert(ps);
	if(ps->arr)
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//数据入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)           //空间满了需要扩容
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;  //三目运算符如果原本栈为空，就赋初始为4个空间，若不为空，则双倍扩容
		STDataType* tem = (STDataType*)realloc(ps->arr, newcapacity * sizeof(STDataType));
		//判断所开空间是否成功
		if (tem == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}

		ps->arr = tem;
		ps->capacity = newcapacity;
	}

	//入栈开始
	ps->arr[ps->top++] = x;
}

//栈判空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//数据出栈
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

//取栈顶元素
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->arr[ps->top - 1];
}

//获取栈中有效元素个数
int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}