#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define ERROR

#define ListSize 100//�궨��

typedef int ElemType;//��int������������޸�

typedef struct SeqList
{
	ElemType data[ListSize];//���鳤�ȣ��������ܱ������Ԫ�أ����Բ����������������Ա�ĳ���
	int length;  //���Ա�ĳ��ȣ���ʾ�Ѿ������Ա��д��Ԫ�صĸ���
}SEQLIST;//�൱��struct SeqList


void init_List(SEQLIST * pList);//��ʼ�����Ա�
bool empty_List(SEQLIST * pList);//�ж��Ƿ�Ϊ��
bool full_List(SEQLIST * pList);//�ж��Ƿ�Ϊ��
void clear_List(SEQLIST * pList);//������Ա�
int length_List(SEQLIST * pList);//����ĳ���
ElemType  *  getElem_List(SEQLIST * pList, int i);//��ȡָ��ĳ���±��Ԫ��
int locateed_List(SEQLIST * pList, ElemType e);//ĳ��Ԫ������λ��
void  insert_List(SEQLIST * pList, int i, ElemType e);//����
void output_List(SEQLIST * pList);//���
void del_List(SEQLIST * pList,int i);//ɾ��ĳ��Ԫ��
void sort(SEQLIST * pList);//����
void sort2(SEQLIST * pList);
void reverse_List(SEQLIST * pList);//��������

int main()
{
	SEQLIST List;
	int len;
	int location;
	int i;

	init_List(&List);
	printf("���������Ա�Ϊ��\n");
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

	printf("ɾ����СԪ�غ��ֵ�ǣ�\n");
	sort2(&List);
	output_List(&List);

	printf("�����Ԫ�ص�ֵ�ǣ�\n");
	reverse_List(&List);
	output_List(&List);
	
	
	
	/*
	sort(&List);
	printf("�����������ɾ����Сֵ������Ա�Ϊ��");
	for (i = 0; i < List.length; i++)
	{
		printf("%d\t",List.data[i]);
	}



	printf("���Ա�ĳ����ǣ�");
	len=length_List(&List);
	printf("%d\n",len);
	

	location=locateed_List(&List,3);
	printf("��Ԫ������λ���ǣ�%d\n ",location);
	
	ElemType  *  data = getElem_List(&List, 3);//�����Ǵ�0�±�ʼ��Ҳ���ǵ��ĸ�Ԫ��
	printf("%d\n",* data);

	
	del_List(&List,4);
	printf("ɾ��������Ա�Ϊ��");
	output_List(&List);
	*/

	
	return 0;
}

//˳���ĳ�ʼ��
void init_List(SEQLIST * pList)
{
	pList->length = 0;
}

//�ж�Ϊ��
bool empty_List(SEQLIST * pList)
{
	return pList->length;
	
}
//�ж�Ϊ��
bool full_List(SEQLIST * pList)
{
	if (ListSize == pList->length)
		return true;
}
//ɾ�����Ա�������Ԫ��

void clear_List(SEQLIST * pList)
{
	pList->length = 0;
}
//��ȡ���Ա���Ԫ�صĸ���

int length_List(SEQLIST * pList)
{
	return pList->length;
}

//��λ�ò���
ElemType  *  getElem_List(SEQLIST * pList,int i)
{
	if (i<0 || i>ListSize - 1)//�������������ʱ����Ҫ���ض����������ElemType *
		return NULL;
	return &pList->data[i];//�ڿռ��ھ�ֱ�ӿ��Է���
}


//��ֵ����

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

//��ĳ��λ�ò���

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

//��ĳ��λ��ɾ��
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


//���

void output_List(SEQLIST * pList)
{
	int i;
	for (i = 0; i < pList->length; ++i)
	{
		printf("%d \t",pList->data[i]);
	}
	printf("\n");
}

//˳�������

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
//����
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