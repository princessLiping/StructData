#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;//ָ����

}NODE,*PNODE;

typedef  struct Stack
{
	PNODE pTop;//��Զָ��ջ��Ԫ��
	PNODE pBottom;//��Զָ��ջ��Ԫ��

}STACK,*PSTACK;

void initStack(PSTACK pStack);
void pushStack(PSTACK pStack, int val);
int traverseStack(PSTACK);
bool popStack(PSTACK pstack,int * val);
bool is_emptyStack(PSTACK pStack);
void clear(PSTACK pStack);

int main()
{
	STACK s;//�ȼ��� struct Stack
	int val;

	initStack(&s);//Ŀ�������һ����ս
	pushStack(&s,1);//ѹջ
	pushStack(&s, 2);
	pushStack(&s, 3);
	pushStack(&s, 4);
	pushStack(&s, 5);
	pushStack(&s, 6);

	//popStack();
	traverseStack(&s);//�������
	if (popStack(&s, &val))
	{
		printf("��ջ�ɹ����ó�ջԪ����%d\n",val);
	}
	else
	{
		printf("��ջʧ��\n");
	}
	traverseStack(&s);	
	
	clear(&s);
	printf("������");
	traverseStack(&s);

	return 0;
}

//��ʼ��
void initStack(PSTACK pStack)
{
	pStack->pTop = (PNODE)malloc(sizeof(NODE));//���һ���ڵ㣬�ѵ�ַ��pTop
	if (NULL == pStack->pTop)
	{
		printf("�ڴ����ʧ��");
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
	PNODE pNew = (PNODE)malloc(sizeof(NODE));//���һ���½ڵ�
	pNew->data = val;//���½ڵ��������Ÿ�val
	pNew->pNext = pStack->pTop;//�µĽ���ָ����Ҫָ����һ���ڵ�
	pStack->pTop= pNew; 
}

//����
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

// ��pStack��ָ��Ԫ�س�ջһ�Σ����ѳ�ջԪ�ش���pVal�β���ָ�ı����У������ջʧ�ܣ�����false,���򷵻�true
bool popStack(PSTACK pstack, int * pVal)
{
	PNODE p = (PNODE)malloc(sizeof(Node));

	if (is_emptyStack(pstack))//���е�ƽStack����ŵ�����������s�ĵ�ַ
	{
		printf("��ջΪ��ջ");
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

//���
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