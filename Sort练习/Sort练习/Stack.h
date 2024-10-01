#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;        //ջ����
	int capacity;           //ջ�Ŀռ��С
	int top;                //ջ��λ��
}ST;


//ջ�ĳ�ʼ��
void STInit(ST* ps);

//ջ������
void StackDestroy(ST* ps);

//������ջ
void StackPush(ST* ps, STDataType x); //STDataType x ��������Ҫ���������

//���ݳ�ջ
void StackPop(ST* ps);

//ȡջ��Ԫ��
STDataType StackTop(ST* ps);

//��ȡջ����ЧԪ�ظ���
int STSize(ST* ps);

