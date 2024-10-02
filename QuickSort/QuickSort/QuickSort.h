#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void PrintArr(int* arr, int n);

//快排递归三种方法

void QuickSort(int* arr, int left, int right);

//快排不递归

void QuickSortNonR(int* arr, int left, int right);

//归并排序

void MergeSort(int* arr, int n);