#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;        //栈数组
	int capacity;           //栈的空间大小
	int top;                //栈顶位置
}ST;


//栈的初始化
void STInit(ST* ps);

//栈的销毁
void StackDestroy(ST* ps);

//数据入栈
void StackPush(ST* ps, STDataType x); //STDataType x 是我们需要插入的数据

//数据出栈
void StackPop(ST* ps);

//取栈顶元素
STDataType StackTop(ST* ps);

//获取栈中有效元素个数
int STSize(ST* ps);

