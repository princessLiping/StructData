#include<stdio.h>

#define MAXSIZE 8

/*
ð�������ԭ��
��һ�����������������Ƚϣ��������У��Ƚ��ĴΣ�ȷ�����һ�������һ�������
for (j = 0; j < MAXSIZE - 1; ++j)
{
	if (arr[j] > arr[j + 1])
	{
		tem = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = tem;
	}
}

�ڶ��������Σ�MAXSIZE-1-1,ȷ�������ڶ���
	for (j = 0; j < MAXSIZE - 1-1; ++j)
{
	if (arr[j] > arr[j + 1])
	{
		tem = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = tem;
	}
}
����������
*/

void BubbleSort(int  arr[MAXSIZE])
{

	int i, j, tem;
	bool flag = false;//�Ż�ð������һ�ζ�û�н���˵���������������
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
		if (flag == false)//û�н���һ�ν���
		{
			printf("����������������");
			break;

		}
		else//���򽻻���flag=true���false
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