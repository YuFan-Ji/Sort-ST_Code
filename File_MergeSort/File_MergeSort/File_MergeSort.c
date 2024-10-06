#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




// 创建有 N 个数据的文件，并同时创建 file1 和 file2
void CreatNData()
{
	// 随机数造数据
	int n = 1000000;
	srand(time(0));
	const char* file = "data.txt";
	const char* file1 = "file1";
	const char* file2 = "file2";

	// 打开文件(写数据)
	FILE* fin = fopen(file, "w");
	// 判断文件是否打开成功
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	// 循环开始写数据
	for (int i = 0; i < n; i++)
	{
		int x = rand() + i;
		fprintf(fin, "%d\n", x);
	}

	// 关闭大文件
	fclose(fin);

	// 清空 file1 和 file2，以便后续使用
	FILE* f1 = fopen(file1, "w");
	FILE* f2 = fopen(file2, "w");
	if (f1 == NULL || f2 == NULL)
	{
		perror("fopen file1 or file2 fail!");
		return;
	}

	// 关闭 file1 和 file2
	fclose(f1);
	fclose(f2);
}

//先把堆排拿过来备用
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出左右孩⼦中⼤的那⼀个
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	// 建堆 -- 向下调整建堆 -- O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	// O(N*logN)
	
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);
		--end;
	}
}

// file1⽂件的数据和file2⽂件的数据归并到mfile⽂件中
void MergeFile(const char* file1, const char* file2, const char* mfile)
{
	//创立三个文件，以读的方式打开file1和file2，以写的方式打开mfile
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		perror("fopen file1 fail!");
		exit(-1);
	}

	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		perror("fopen file2 fail!");
		exit(-1);
	}

	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		perror("fopen mfile fail!");
		exit(-1);
	}

	// 这⾥跟内存中数组归并的思想完全类似，只是数据在硬盘⽂件中⽽已
    // 依次读取file1和file2的数据，谁的数据⼩，谁就往mfile⽂件中去写
    // file1和file2其中⼀个⽂件结束后，再把另⼀个⽂件未结束⽂件数据，
    // 依次写到mfile的后⾯
	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);
	int ret2 = fscanf(fout2, "%d\n", &num2);

	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d\n", &num1);
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}

	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}
	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}

	///打开文件后记得关闭
	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}

// 返回读取到的数据个数,并排序,读 N 个数据返回给文件,并返回读到数据的个数
int ReadNNumSortToFile(FILE* fout, int* a, int n, const char* file)
{
	//数据读到 x 中
	int x = 0;

	// i 表示读到数据的个数
	int i = 0;

	while (i < n && fscanf(fout, "%d\n", &x) != EOF)
	{
		a[i++] = x;
	}

	//如果一个数据都没读到，不用排序了，返回0
	if (i == 0)
	{
		return i;
	}

	//读到的数据堆排序
	HeapSort(a, i);

	//把排序过的数组放回文件中去
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen file fail!");
		exit(-1);
	}

	for (int j = 0; j < i; j++)
	{
		fprintf(fin, "%d\n", a[j]);
	}

	//记得关闭文件
	fclose(fin);
	return i;
}

// MergeSortFile的第⼆个是每次取多少个数据到内存中排序，然后写到⼀个⼩⽂件进⾏归并
// 这个n给多少取决于我们有多少合理的内存可以利⽤，相对⽽⾔n越⼤，更多数据到内存中排序后，
// 再⾛⽂件归并排序，整体程序会越快⼀些。
void MergeSortFile(const char* file, int n)
{
	// 以写的方式打开文件 file
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen file fail!");
		exit(-1);
	}

	// 定义三个文件 file1, file2, mfile
	const char* file1 = "file1";
	const char* file2 = "file2";
	const char* mfile = "mfile";

	// 分割成⼀段⼀段数据，内存排序后写到，⼩⽂件
	int* a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}

	
	int readCount1 = ReadNNumSortToFile(fout, a, n, file1);
	int readCount2 = ReadNNumSortToFile(fout, a, n, file2);

	if (readCount1 == 0 && readCount2 == 0) {
		fclose(fout);
		free(a);
		return; // 如果两个文件都没有数据，直接返回
	}

	//循环归并获取元素
	while (1)
	{
		// file1和file2⽂件归并到mfile⽂件中
		MergeFile(file1, file2, mfile);

		//删除file1和file2
		if (remove(file1) != 0 || remove(file2) != 0)
		{
			perror("Error deleting file");
			exit(-1);
		}

		//重命名mfile为file1
		if (rename(mfile, file1) != 0)
		{
			perror("Error renaming file");
			exit(-1);
		}

		// 读取N个数据到file2，继续⾛归并
        // 如果⼀个数据都没读到，则归并结束了
		if (ReadNNumSortToFile(fout, a, n, file2) == 0)
		{
			break;
		}
	}

	printf("%s 文件成功排序到%s\n", file, file1);
	// 别忘了关闭文件，释放a空间
	fclose(fout);
	free(a);
}

int main()
{
	//CreatNData();
	
	// 一次排100000个数据
	MergeSortFile("data.txt", 100000);
	return 0;
}