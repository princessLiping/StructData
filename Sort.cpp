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
//-------------------------------冒泡排序-------------------------------
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
//---------------------------------------------选择排序----------------------------------------
void selectSort(int arr[MAXSIZE])
{

	int i, j;
	int minValueIndex;//定义一个索引值下标，假设当前就是最小
	int minValue;//定义一个最小值，假设当前就是最小值
	
	for (i = 0; i < MAXSIZE; i++)
	{
		minValue = arr[i];//相当于minValue=arr[0];,把一个当做最小的元素，和后面一次进行比较
		minValueIndex = i;//索引下标为当前设置为0；
		for (j = i + 1; j < MAXSIZE; ++j)
		{
			if (minValue > arr[j])//如果有比当前最小值小的则交换
			{
				minValue = arr[j];//把找到的最小值赋值给minValue,此时的最小值发生变化
				minValueIndex = j;//把找到最小值的下标存给minValueIndex,此时的最小值下标发生变换
			}
		}
		if (minValueIndex != i)//如多索引下标没有发生改变则交换，否则不执行
		{
			arr[minValueIndex] = arr[i];//把最大值（从它开始比较的那个纸）给 找到的最小值的位置
			arr[i] = minValue;//把最小值给此时从它开始比较的下标
		}
	}

}
//----------------------------------------插入排序------------------------------------------------
/*
//第一躺
int i;
int insertIndex = 1 - 1;//要插入的下表位置
int insertValue = arr[1];//要插入的值
//防止越界
while (insertIndex >= 0 && arr[insertIndex] > insertValue)
{
	arr[insertIndex + 1] = arr[insertIndex];
	insertIndex--;//第一躺是完了insertIndex的值是：-1；-1不满足while条件，结束当前循环，转到2
}

arr[insertIndex + 1] = insertValue;//2：此时相当于arr[0]=插入的值
//第二趟
insertIndex = 2 - 1;//要插入的下表位置
 insertValue = arr[2];//要插入的值
//防止越界
while (insertIndex >= 0 && arr[insertIndex] > insertValue)//1>=0,arr[1]>a[2]??       2--  >0 &&arr[0]>arr[2]????是的话
{
	arr[insertIndex + 1] = arr[insertIndex];//a[2]=a[1]  ，a[1]=a[0],
	insertIndex--;//2--,继续向后移,0--  <0循环退出
}

arr[insertIndex + 1] = insertValue;//2：此时相当于arr[0]=插入的值
*/
void inserSort(int arr[MAXSIZE])
{
	int i;
	int insertValue;//定义一个要插入的值
	int insertIndex;//定义一个要插入值的位置
	for ( i = 1; i < MAXSIZE; i++)
	{
		insertValue= arr[i];
		insertIndex = i - 1;
		while (insertIndex >= 0 && arr[insertIndex] > insertValue)//防止数组越界
		{
			arr[insertIndex + 1] = arr[insertIndex];
			insertIndex--;
		}
		arr[insertIndex + 1] = insertValue;
	}
}
//插入法的希尔排序（效率较低）
void ShellSort(int arr[MAXSIZE])
{
	int temp;
	int i, j, gap;
	for (gap = MAXSIZE / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < MAXSIZE; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				
				if (arr[j] > arr[j + gap])
				{
					temp = arr[j];
					arr[j] = arr[j + gap];
					arr[j + gap] = temp;
				}
			}
		}
	}

}
//希尔排序的高效算法

void  shellSort(int arr[])
{
	int i, j, temp, gap;
	for (gap = MAXSIZE / 2; gap > 0; gap /= 2) {
		for (i = gap; i < MAXSIZE; i++) {
			int j = i;
			int temp = arr[j];
			if (arr[j] < arr[j -=gap])
			{
				
				while (j - gap >= 0 && temp < arr[j - gap])
				{
					arr[j] = arr[j - gap];
					j -= gap;
				}
				arr[j] = temp;
			}
		}
	}
}

int main()
{

	int	a[MAXSIZE] = { 1,2,3,4,5,6,7,8 };
	shellSort(a);
	output(a);
	return 0;
}