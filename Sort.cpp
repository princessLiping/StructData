#include<stdio.h>

#define MAXSIZE 8

/*
冒泡排序的原理
第一趟用两个索引两两比较，逆序排列，比较四次，确定最后一个，最后一个是最大
for (j = 0; j < MAXSIZE - 1; ++j)
{
	if (arr[j] > arr[j + 1])
	{
		tem = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = tem;
	}
}

第二趟走三次，MAXSIZE-1-1,确定倒数第二个
	for (j = 0; j < MAXSIZE - 1-1; ++j)
{
	if (arr[j] > arr[j + 1])
	{
		tem = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = tem;
	}
}
·····
*/

void BubbleSort(int  arr[MAXSIZE])
{

	int i, j, tem;
	bool flag = false;//优化冒泡排序：一次都没有交换说明本来就是有序的
	for (i = 0; i < MAXSIZE - 1; ++i)
	{
		for (j = 0; j < MAXSIZE - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = true;
				tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;
			}

		}
		if (flag == false)//没有进行一次交换
		{
			printf("本来就是有序数组");
			break;

		}
		else//否则交换后将flag=true变成false
			flag = false;
	}
}
	
void output(int arr[MAXSIZE])
{
	int i;
	for (i = 0; i < MAXSIZE; ++i)
	{
		printf("%d \t", arr[i]);
	}
}

int main()
{

	int	a[MAXSIZE] = { 1,2,3,4,5,6,7,8 };
	BubbleSort(a);
	output(a);



	return 0;
}