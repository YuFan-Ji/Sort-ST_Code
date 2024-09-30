#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//�ѵĽṹ����
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}HP;


//�ѵĳ�ʼ��
void HPInit(HP* php);

//�ѵ�����
void HPDestroy(HP* php);

//�����в���Ԫ��
void HPPush(HP* php, HPDataType x);

//ɾ����������
void HPPop(HP* php);

//��ȡ�Ѷ�Ԫ��
HPDataType HPTop(HP* php);

bool HPEmpty(HP* php);