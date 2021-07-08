#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{

	int data;//数据域
	struct  Node * pNext;//指针域

}NODE,*pNODE;

//NODE相当于 struct Node ;pNODE相当于 struct Node *; 
pNODE creat_list();
void traverse_list(pNODE pHead);

bool is_empty(pNODE pHead);
int length_list(pNODE pHead);
bool insert_list(pNODE,int ,int);//哪个链表，哪个位置，插入的值
bool delete_list(pNODE,int,int *);//哪个链表，哪个位置，相当于删除的节点的数
void sort_list(pNODE);//排序，基于快排
void sort_list2(pNODE);//排序，基于冒泡

int  main()
{
	pNODE pHead = NULL;//等价于struct Node * pHead=NULL
	//创建链表
	pHead = creat_list(); /*creat_list()功能：创建一个非循环的单链表，
							并将该链表的头结点的地址给pHead
						  */
	traverse_list(pHead);//输出链表，表示遍历，一定需要参数确定遍历哪个链表	
	//判断链表是否为空	
	if (is_empty(pHead))
	{
		printf("链表为空！");
	}
	else
	{
		printf("链表表不为空\n");
	}
	//求出链表的长度	
	int len = length_list(pHead);
	printf("链表的长度是：%d\n",len);
	//给链表元素排序
	printf("排序：");
	sort_list2(pHead);
	traverse_list(pHead);
	
	//给链表插入元素
	if (insert_list(pHead, 4, 20))
	{
		printf("元素插入成功\n");
	}
	else
	{
		printf("元素插入失败\n");
	}
	traverse_list(pHead);
	//删除元素
	int val;
	if (delete_list(pHead, 5, &val))
	{
		printf("元素删除成功\n");
	}
	else
	{
		printf("元素删出失败\n");
	}
	traverse_list(pHead);
	return 0;
}

//返回值应该是个地址
pNODE creat_list()
{
	//1.
	int len;//用来存放有效结点的个数
	int i;
	int val=0;//用来临时存放用户输入的结点的值
	
	/*不能为每个临时结点都分配一个名字，
	因此用p来表示每一个新增节点的,然后将其挂在头结点的后面
	*/

	//2.分配了一个不存放有效数据的头结点
	pNODE pHead = (pNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("内存分配失败，程序终止！！");
		exit(-1);
	}
	//4.
	pNODE pTail = pHead;
	pTail->pNext = NULL;/*这一步是必须的，当只有一个节点的时候，
						pTail和pHead都指向头结点，然后把头结点的指针域清空
						让头结点永远指向尾结点
						*/
	//3.
	printf("请输入您需要生成的链表结点的个数len=");
	scanf("%d", &len);
	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个结点的值:",i+1);
		scanf("%d",&val);
	
		/*不能为每个临时结点都分配一个名字，
		因此用p来表示每一个新增节点的,然后将其挂在头结点的后面
		*/

		
		pNODE pNew = (pNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("内存分配失败，程序终止！！");
			exit(-1);
		}
		/*


		//要把pNew挂到pHead后面去
		pNew->data = val;
		pHead->pNext = pNew;
		pNew->pNext = NULL;
		//这样写会出问题，每次都挂向pHead的后面，上一个就会丢失
		//不是让每一个新生的结点挂到pHead后面，这样顺序就反了
		//应该让新生成的结点挂到尾结点的后面
		
		*/

		//4.正确写法
		pNew->data = val;
		pTail->pNext = pNew;//用pTail来一直放尾结点
		pNew->pNext = NULL;
		pTail = pNew;
		
	}
	return pHead;
}

//遍历
void traverse_list(pNODE pHead)
{
	pNODE p=pHead->pNext;//p只想第一个有效结点
	/*
		链表此时也有可能为空，链表为空时，也有一个头结点
		然后用pHead->pNext=NULL;
		链表为空：里面只有一个头结点，没有其他有效结点

	*/
	printf("输出链表：");
	while (NULL!=p)
	{
		
		printf("%d\t",p->data);
		p = p->pNext;//相当于++i;因为链表的存放是不连续的，数组存放是连续的

	}
	printf("\n");
}

//判断链表后是否为空
bool is_empty(pNODE pHead)
{
	if (NULL == pHead->pNext)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//求链表的长度
int length_list(pNODE pHead)
{
	int len=0;
	pNODE p = pHead->pNext;
	while (NULL != p)
	{
		len++;
		p = p->pNext;		
	}

	return len;
}

//排序
void sort_list(pNODE pHead)
{
	/*基于选择排序实现
	int i, j, t;
	int	a[8] = { 6,8,2,1,3,0,7,99 };

	for (i = 0; i < 7; ++i)
	{
		for (j = i + 1; j < 8; ++j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	for (i = 0; i < 8; i++)
	{
		printf("%d \t", a[i]);
	}

	*/
	int i,j ,t;
	pNODE p, q;
	int len = length_list(pHead);
	for (i = 0, p = pHead->pNext; i < len - 1; ++i, p = p->pNext)
	{
		for (j = i + 1, q = p->pNext; j < len; ++j, q = q->pNext)
		{
			if (p->data > q->data)//类似与数组中 ：a[i]>a[j]
			{
				t = p->data; //类似与数组中 ：t=a[i];
				p->data = q->data;//类似与数组中 ：a[i]=a[j]
				q->data = t;////类似与数组中 ：a[j]=t
			}
		}

	}

	
	
	
}

void sort_list2(pNODE pHead)
{
    /*基于冒泡实现
	int i, j, t;
	int	a[8] = { 6,8,2,1,3,0,7,99 };
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 8 - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (i = 0; i < 8; i++)
	{
		printf("%d \t", a[i]);
	}
	*/
	int i, j, t;
	pNODE p, q;
	int len = length_list(pHead);
	for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
	{
		for (j = 0, q = pHead->pNext; j < len - i - 1; j++, q = q->pNext)
		{
			if (q->data > q->pNext->data)//相当于数组中：a[j] > a[j + 1]
			{
				t = q->data;//相当于数组中：t = a[j]
				q->data = q->pNext->data;//相当于数组中：a[j] = a[j + 1];
				q->pNext->data = t;//相当于数组中： a[j + 1] = t;
			}
		}
	}

}

//在pHead所指向链表的第pos个节点的前面插入一个新的节点，该节点的值是val,并且pos是从1开始
bool insert_list(pNODE pHead, int pos, int val)
{
	//链表不存在满的问题
	//判断pos的节点是否合法，因此要先求链表的长度

	//不需要判断，金典+高效，没看懂
	int i = 0;
	pNODE p = pHead;
	while (NULL != p && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p)
		return false;
	pNODE pNew = (pNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("动态内存分配失败");
		exit(-1);
	}
	pNew->data = val;
	pNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return true;
}

bool delete_list(pNODE pHead, int pos, int * pVal)
{

	int i = 0;
	pNODE p = pHead;
	while (NULL != p->pNext &&i < pos - 1)
	{
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p->pNext)
		return false;
	pNODE q = p->pNext;
	*pVal = q->data;
	printf("删出的元素是：%d \n",*pVal);
	//删除p结点后面的结点
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
}