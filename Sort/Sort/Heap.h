#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//堆的结构定义
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}HP;


//堆的初始化
void HPInit(HP* php);

//堆的销毁
void HPDestroy(HP* php);

//往堆中插入元素
void HPPush(HP* php, HPDataType x);

//删除堆中数据
void HPPop(HP* php);

//获取堆顶元素
HPDataType HPTop(HP* php);

bool HPEmpty(HP* php);