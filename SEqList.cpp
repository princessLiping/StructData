#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define ERROR

#define ListSize 100//宏定义

typedef int ElemType;//给int起别名，方便修改

typedef struct SeqList
{
	ElemType data[ListSize];//数组长度，决定了能保存多少元素，可以不放满，不代表线性表的长度
	int length;  //线性表的长度，表示已经在线性表中存放元素的个数
}SEQLIST;//相当于struct SeqList


void init_List(SEQLIST * pList);//初始化线性表
bool empty_List(SEQLIST * pList);//判断是否为空
bool full_List(SEQLIST * pList);//判断是否为满
void clear_List(SEQLIST * pList);//清空线性表
int length_List(SEQLIST * pList);//链表的长度
ElemType  *  getElem_List(SEQLIST * pList, int i);//获取指定某个下标的元素
int locateed_List(SEQLIST * pList, ElemType e);//某个元素所在位置
void  insert_List(SEQLIST * pList, int i, ElemType e);//插入
void output_List(SEQLIST * pList);//输出
void del_List(SEQLIST * pList,int i);//删除某个元素
void sort(SEQLIST * pList);//排序
void sort2(SEQLIST * pList);
void reverse_List(SEQLIST * pList);//逆序排列

int main()
{
	SEQLIST List;
	int len;
	int location;
	int i;

	init_List(&List);
	printf("创建的线性表为：\n");
	insert_List(&List,0,2);
	insert_List(&List, 1, 3);
	insert_List(&List, 2, 4);
	insert_List(&List, 2, 5);
	insert_List(&List, 2, 6);
	insert_List(&List, 2, 7);
	insert_List(&List, 2, 8);
	insert_List(&List, 2, 9);
	insert_List(&List, 2, 10);
	insert_List(&List, 2, 11);
	output_List(&List);

	printf("删除最小元素后的值是：\n");
	sort2(&List);
	output_List(&List);

	printf("逆序后元素的值是：\n");
	reverse_List(&List);
	output_List(&List);
	
	
	
	/*
	sort(&List);
	printf("按升序排序后并删除最小值后的线性表为：");
	for (i = 0; i < List.length; i++)
	{
		printf("%d\t",List.data[i]);
	}



	printf("线性表的长度是：");
	len=length_List(&List);
	printf("%d\n",len);
	

	location=locateed_List(&List,3);
	printf("该元素所在位置是：%d\n ",location);
	
	ElemType  *  data = getElem_List(&List, 3);//数组是从0下表开始，也就是第四个元素
	printf("%d\n",* data);

	
	del_List(&List,4);
	printf("删除后的线性表为：");
	output_List(&List);
	*/

	
	return 0;
}

//顺序表的初始化
void init_List(SEQLIST * pList)
{
	pList->length = 0;
}

//判断为空
bool empty_List(SEQLIST * pList)
{
	return pList->length;
	
}
//判断为满
bool full_List(SEQLIST * pList)
{
	if (ListSize == pList->length)
		return true;
}
//删除线性表中所有元素

void clear_List(SEQLIST * pList)
{
	pList->length = 0;
}
//获取线性表中元素的个数

int length_List(SEQLIST * pList)
{
	return pList->length;
}

//按位置查找
ElemType  *  getElem_List(SEQLIST * pList,int i)
{
	if (i<0 || i>ListSize - 1)//当条件不满足的时候，需要返回东西，因此用ElemType *
		return NULL;
	return &pList->data[i];//在空间内就直接可以返回
}


//按值查找

int locateed_List(SEQLIST * pList,ElemType e)
{
	int i;
	for (i = 0; i < pList->length; ++i)
	{
		if (e == pList->data[i])
		{
			return i ;
		}
	}
}

//按某个位置插入

void  insert_List(SEQLIST * pList,int i,ElemType e) 
{
	int j;
	if (i<0 || i>ListSize)
		exit(-1);
	if (pList->length >= ListSize)
		exit(-1);
	for (j = pList->length; j >= i; j--)
	{
		pList->data[j] = pList->data[j - 1];
	}
	pList->data[i] = e;
	pList->length++;
	
}

//按某个位置删除
void del_List(SEQLIST * pList, int i)
{
	int j;
	if (i<0 || i>ListSize)
		exit(-1);
	if (pList->length >= ListSize)
		exit(-1);
	
	for (j = i; j < pList->length; j++)
	{
		pList->data[j] = pList->data[j + 1];
	}
	pList->length--;
	
}


//输出

void output_List(SEQLIST * pList)
{
	int i;
	for (i = 0; i < pList->length; ++i)
	{
		printf("%d \t",pList->data[i]);
	}
	printf("\n");
}

//顺序表排序

void sort(SEQLIST * pList)
{
	int i, j,t;
	for (i = 0; i < pList->length-1; i++)
	{
		for (j = 0; j < pList->length - i - 1; j++)
		{
			if (pList->data[j] < pList->data[j + 1])
			{
				t = pList->data[j];
				pList->data[j] = pList->data[j + 1];
				pList->data[j + 1] = t;
			}
		}
	}
	del_List(pList, pList->length - 1);

}


void sort2(SEQLIST * pList)
{

	int i;
	int pos=0;
	int num = pList->data[0];;
	for (i = 0; i < pList->length; i++)
	{
		if (num > pList->data[i])
		{
			num = pList->data[i];
			pos = i;
		}

	}
	 
	for (i = pos; i < pList->length; i++)
	{
		pList->data[i] = pList->data[i + 1];
	}
	pList->length--;
}
//逆序
void reverse_List(SEQLIST * pList)
{
	int i,j,t;
	for (i = 0; i < pList->length / 2; i++)
	{
	
			t = pList->data[i];
			pList->data[i] = pList->data[pList->length-1-i];
			pList->data[pList->length - 1 - i] = t;
	
	}

}