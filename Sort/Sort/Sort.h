#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void PrintArr(int* arr, int n);


//ֱ�Ӳ�������
void InsertSort(int* arr, int n);

//������
void HeapSort(int* arr, int n);

//ð������
void BubbleSort(int* arr, int n);

//ϣ������
void ShellSort(int* arr, int n);

//ѡ������
void SelectSort(int* arr, int n);

//��������
void QuickSort(int* arr, int left, int right);