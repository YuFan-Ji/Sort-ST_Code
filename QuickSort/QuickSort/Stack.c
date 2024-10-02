#include"Stack.h"

//ջ�ĳ�ʼ��
void STInit(ST* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//ջ������
void STDestroy(ST* ps)
{
	assert(ps);
	if(ps->arr)
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//������ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)           //�ռ�������Ҫ����
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;  //��Ŀ��������ԭ��ջΪ�գ��͸���ʼΪ4���ռ䣬����Ϊ�գ���˫������
		STDataType* tem = (STDataType*)realloc(ps->arr, newcapacity * sizeof(STDataType));
		//�ж������ռ��Ƿ�ɹ�
		if (tem == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}

		ps->arr = tem;
		ps->capacity = newcapacity;
	}

	//��ջ��ʼ
	ps->arr[ps->top++] = x;
}

//ջ�п�
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//���ݳ�ջ
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

//ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->arr[ps->top - 1];
}

//��ȡջ����ЧԪ�ظ���
int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}