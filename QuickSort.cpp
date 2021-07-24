#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10


void InputArr(int arr[MaxSize]);//随机生成长度为MaxSize的数组
void OutPut(int arr[MaxSize]);//排序后的输出
void QuickSort(int arr[MaxSize], int left, int right);//右排序左排序、
int  FindPos(int arr[MaxSize], int left, int right);//确定基准进行比较

int main()
{
	int arr[MaxSize];//定义一个数组
	
	InputArr(arr);
	printf("排序前的如下");
	OutPut(arr);
	printf("\n");
	printf("排序后的如下");
	QuickSort(arr, 0, MaxSize-1);
	OutPut(arr);
	
	return 0;
	
}
//随机生成长度为MaxSize的数组
void InputArr(int arr[MaxSize])
{
	int i;
	for (i = 0; i < MaxSize; i++)
	{
		arr[i] = rand();
	}
}
//输出
void OutPut(int arr[MaxSize])
{
	int i;
	for (i = 0; i < MaxSize; i++)
	{
		printf("%d\t",arr[i]);
	}
}
//排序采用递归
void QuickSort(int arr[MaxSize],int left,int right)
{
	int pos;
	if (left < right)
	{
		pos = FindPos(arr, left, right);
		QuickSort(arr,left,pos-1);//左排序
		QuickSort(arr, pos + 1, right);//右排序
	}

}
//确定基准，比较
int  FindPos(int arr[MaxSize], int low, int high)
{
	int val = arr[low];
	while(low < high)//这代表的时下标
	{
		while (low < high && arr[high] >= val)//当右边的值大于基准的时候
		{
			--high;//基准往前加一
		}
		//否则的话就是右边的值小于基准的值，小于就赋值给左边
		arr[low] = arr[high];
		while (low < high && arr[low] <= val)//当基准大于右边的
		{
			++low;//基准值往前走
		}
		//否则的话，就是当基准小于某个值的时候（某个值比基准大的时候），把该值赋值给右边
		arr[high] = arr[low];
	}
	//中止while循环之后low和high的值一定是相等的
	arr[low] = val;//把第一个值放进low和high相等那个位置
	return low;//此处返回左和右都是一样的
}