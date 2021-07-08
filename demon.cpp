#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;//指针域

}NODE,*PNODE;

typedef  struct Stack
{
	PNODE pTop;//永远指向栈顶元素
	PNODE pBottom;//永远指向栈底元素

}STACK,*PSTACK;

void initStack(PSTACK pStack);
void pushStack(PSTACK pStack, int val);
int traverseStack(PSTACK);
bool popStack(PSTACK pstack,int * val);
bool is_emptyStack(PSTACK pStack);
void clear(PSTACK pStack);

int main()
{
	STACK s;//等价于 struct Stack
	int val;

	initStack(&s);//目的是造出一个空战
	pushStack(&s,1);//压栈
	pushStack(&s, 2);
	pushStack(&s, 3);
	pushStack(&s, 4);
	pushStack(&s, 5);
	pushStack(&s, 6);

	//popStack();
	traverseStack(&s);//遍历输出
	if (popStack(&s, &val))
	{
		printf("出栈成功，该出栈元素是%d\n",val);
	}
	else
	{
		printf("出栈失败\n");
	}
	traverseStack(&s);	
	
	clear(&s);
	printf("清空完毕");
	traverseStack(&s);

	return 0;
}

//初始化
void initStack(PSTACK pStack)
{
	pStack->pTop = (PNODE)malloc(sizeof(NODE));//造出一个节点，把地址给pTop
	if (NULL == pStack->pTop)
	{
		printf("内存分配失败");
		exit(-1);
	}
	else
	{
		pStack->pBottom = pStack->pTop;
		pStack->pTop->pNext = NULL;
	}
}

void pushStack(PSTACK pStack, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));//造出一个新节点
	pNew->data = val;//把新节点的数据域放给val
	pNew->pNext = pStack->pTop;//新的结点的指针域要指向下一个节点
	pStack->pTop= pNew; 
}

//遍历
int traverseStack(PSTACK pStack)
{
	PNODE p = pStack->pTop;
	while(p!=pStack->pBottom)
	{
		printf("%d \t",p->data);
		p = p->pNext;
	}
	printf("\n");
	return 0;
}

bool is_emptyStack(PSTACK pStack)
{
	/*
	PNODE p = (PNODE)malloc(sizeof(NODE));
	if (NULL == p->pNext)
		return  true;
	else
		return false;
	*/
	
	if (pStack->pTop == pStack->pBottom)
		return true;
	else
		return false;
}

// 把pStack所指的元素出栈一次，并把出栈元素存入pVal形参所指的变量中，如果出栈失败，返回false,否则返回true
bool popStack(PSTACK pstack, int * pVal)
{
	PNODE p = (PNODE)malloc(sizeof(Node));

	if (is_emptyStack(pstack))//所有的平Stack都存放的是主函数中s的地址
	{
		printf("该栈为空栈");
		return false;
	}
	else
	{
		PNODE r = pstack->pTop;
		*pVal = r->data;

		//pstack->pTop = pstack->pTop->pNext;
		pstack->pTop = r->pNext;		
		free(r);
		r = NULL;
		return true; 		
	}
}

//清空
void clear(PSTACK pStack)
{

	if (is_emptyStack(pStack))
	{
		return ;
	}
	else
	{
		PNODE p = pStack->pTop;
		//PNODE q = p->pNext;
		PNODE q = NULL;
		while (p != pStack->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pStack->pTop = pStack->pBottom;

	}

}