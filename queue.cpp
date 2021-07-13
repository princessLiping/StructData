
#include<stdio.h>
#include<malloc.h>

typedef struct Queue
{
	int * pBase;
	int rear;
	int front;

}QUEUE,*pQUEUE;


void init(QUEUE * pQu);
bool en_queue(QUEUE * pQu, int val);
void traverse_queue(QUEUE * pQu);
bool full_queue(QUEUE * pQu);
bool out_queue(QUEUE * pQu,int * pVal);
bool empty_queue(QUEUE * pQu);

int main()
{
	
	QUEUE Q;
	int  val;
	
	init(&Q);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	en_queue(&Q, 7);
	
	traverse_queue(&Q);
	if (out_queue(&Q, &val))
	{
		printf("出队列的元素是%d\n",val);
	}
	else
	{
		printf("出队失败\n");
	}
	traverse_queue(&Q);
	return 0;




}

void init(QUEUE *pQu)
{
	pQu->pBase = (int *)malloc(sizeof(int) * 6);
	pQu->front = 0;
	pQu->rear = 0;

}

bool full_queue(QUEUE *pQu)
{
	if ((pQu->rear + 1) % 6 == pQu->front)
		return true;
	else
		return false;
}

bool en_queue(QUEUE *pQu, int val)
{
	if (full_queue(pQu))
	{
		printf("队列已满");
		return false;
	}
		
	else
	{
		pQu->pBase[pQu->rear] = val;
		pQu->rear = (pQu->rear + 1) % 6;
		return true;
	}
}
void traverse_queue(QUEUE *pQu)
{
	int i = pQu->front;
	while (i != pQu->rear)
	{
		printf("%d \t", pQu->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
	return;
}

bool empty_queue(QUEUE * pQu)
{
	if (pQu->front == pQu->rear)
		return true;
	else
	{
		return false;
	}
}

bool out_queue(QUEUE * pQu, int *pVal)
{
	if (empty_queue(pQu))
	{
		printf("当前为空");
		return false;
		
	
	}
	else
	{
		*pVal =pQu->pBase[ pQu->front];
		pQu->front = (pQu->front + 1) % 6;
		return true;
	}
}

