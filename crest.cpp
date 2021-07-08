#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{

	int data;//������
	struct  Node * pNext;//ָ����

}NODE,*pNODE;

//NODE�൱�� struct Node ;pNODE�൱�� struct Node *; 
pNODE creat_list();
void traverse_list(pNODE pHead);

bool is_empty(pNODE pHead);
int length_list(pNODE pHead);
bool insert_list(pNODE,int ,int);//�ĸ������ĸ�λ�ã������ֵ
bool delete_list(pNODE,int,int *);//�ĸ������ĸ�λ�ã��൱��ɾ���Ľڵ����
void sort_list(pNODE);//���򣬻��ڿ���
void sort_list2(pNODE);//���򣬻���ð��

int  main()
{
	pNODE pHead = NULL;//�ȼ���struct Node * pHead=NULL
	//��������
	pHead = creat_list(); /*creat_list()���ܣ�����һ����ѭ���ĵ�����
							�����������ͷ���ĵ�ַ��pHead
						  */
	traverse_list(pHead);//���������ʾ������һ����Ҫ����ȷ�������ĸ�����	
	//�ж������Ƿ�Ϊ��	
	if (is_empty(pHead))
	{
		printf("����Ϊ�գ�");
	}
	else
	{
		printf("�����Ϊ��\n");
	}
	//�������ĳ���	
	int len = length_list(pHead);
	printf("����ĳ����ǣ�%d\n",len);
	//������Ԫ������
	printf("����");
	sort_list2(pHead);
	traverse_list(pHead);
	
	//���������Ԫ��
	if (insert_list(pHead, 4, 20))
	{
		printf("Ԫ�ز���ɹ�\n");
	}
	else
	{
		printf("Ԫ�ز���ʧ��\n");
	}
	traverse_list(pHead);
	//ɾ��Ԫ��
	int val;
	if (delete_list(pHead, 5, &val))
	{
		printf("Ԫ��ɾ���ɹ�\n");
	}
	else
	{
		printf("Ԫ��ɾ��ʧ��\n");
	}
	traverse_list(pHead);
	return 0;
}

//����ֵӦ���Ǹ���ַ
pNODE creat_list()
{
	//1.
	int len;//���������Ч���ĸ���
	int i;
	int val=0;//������ʱ����û�����Ľ���ֵ
	
	/*����Ϊÿ����ʱ��㶼����һ�����֣�
	�����p����ʾÿһ�������ڵ��,Ȼ�������ͷ���ĺ���
	*/

	//2.������һ���������Ч���ݵ�ͷ���
	pNODE pHead = (pNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("�ڴ����ʧ�ܣ�������ֹ����");
		exit(-1);
	}
	//4.
	pNODE pTail = pHead;
	pTail->pNext = NULL;/*��һ���Ǳ���ģ���ֻ��һ���ڵ��ʱ��
						pTail��pHead��ָ��ͷ��㣬Ȼ���ͷ����ָ�������
						��ͷ�����Զָ��β���
						*/
	//3.
	printf("����������Ҫ���ɵ�������ĸ���len=");
	scanf("%d", &len);
	for (i = 0; i < len; ++i)
	{
		printf("�������%d������ֵ:",i+1);
		scanf("%d",&val);
	
		/*����Ϊÿ����ʱ��㶼����һ�����֣�
		�����p����ʾÿһ�������ڵ��,Ȼ�������ͷ���ĺ���
		*/

		
		pNODE pNew = (pNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("�ڴ����ʧ�ܣ�������ֹ����");
			exit(-1);
		}
		/*


		//Ҫ��pNew�ҵ�pHead����ȥ
		pNew->data = val;
		pHead->pNext = pNew;
		pNew->pNext = NULL;
		//����д������⣬ÿ�ζ�����pHead�ĺ��棬��һ���ͻᶪʧ
		//������ÿһ�������Ľ��ҵ�pHead���棬����˳��ͷ���
		//Ӧ���������ɵĽ��ҵ�β���ĺ���
		
		*/

		//4.��ȷд��
		pNew->data = val;
		pTail->pNext = pNew;//��pTail��һֱ��β���
		pNew->pNext = NULL;
		pTail = pNew;
		
	}
	return pHead;
}

//����
void traverse_list(pNODE pHead)
{
	pNODE p=pHead->pNext;//pֻ���һ����Ч���
	/*
		�����ʱҲ�п���Ϊ�գ�����Ϊ��ʱ��Ҳ��һ��ͷ���
		Ȼ����pHead->pNext=NULL;
		����Ϊ�գ�����ֻ��һ��ͷ��㣬û��������Ч���

	*/
	printf("�������");
	while (NULL!=p)
	{
		
		printf("%d\t",p->data);
		p = p->pNext;//�൱��++i;��Ϊ����Ĵ���ǲ������ģ���������������

	}
	printf("\n");
}

//�ж�������Ƿ�Ϊ��
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

//������ĳ���
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

//����
void sort_list(pNODE pHead)
{
	/*����ѡ������ʵ��
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
			if (p->data > q->data)//������������ ��a[i]>a[j]
			{
				t = p->data; //������������ ��t=a[i];
				p->data = q->data;//������������ ��a[i]=a[j]
				q->data = t;////������������ ��a[j]=t
			}
		}

	}

	
	
	
}

void sort_list2(pNODE pHead)
{
    /*����ð��ʵ��
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
			if (q->data > q->pNext->data)//�൱�������У�a[j] > a[j + 1]
			{
				t = q->data;//�൱�������У�t = a[j]
				q->data = q->pNext->data;//�൱�������У�a[j] = a[j + 1];
				q->pNext->data = t;//�൱�������У� a[j + 1] = t;
			}
		}
	}

}

//��pHead��ָ������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬�ýڵ��ֵ��val,����pos�Ǵ�1��ʼ
bool insert_list(pNODE pHead, int pos, int val)
{
	//����������������
	//�ж�pos�Ľڵ��Ƿ�Ϸ������Ҫ��������ĳ���

	//����Ҫ�жϣ����+��Ч��û����
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
		printf("��̬�ڴ����ʧ��");
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
	printf("ɾ����Ԫ���ǣ�%d \n",*pVal);
	//ɾ��p������Ľ��
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
}