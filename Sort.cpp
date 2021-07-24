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
//-------------------------------ð������-------------------------------
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
//---------------------------------------------ѡ������----------------------------------------
void selectSort(int arr[MAXSIZE])
{

	int i, j;
	int minValueIndex;//����һ������ֵ�±꣬���赱ǰ������С
	int minValue;//����һ����Сֵ�����赱ǰ������Сֵ
	
	for (i = 0; i < MAXSIZE; i++)
	{
		minValue = arr[i];//�൱��minValue=arr[0];,��һ��������С��Ԫ�أ��ͺ���һ�ν��бȽ�
		minValueIndex = i;//�����±�Ϊ��ǰ����Ϊ0��
		for (j = i + 1; j < MAXSIZE; ++j)
		{
			if (minValue > arr[j])//����бȵ�ǰ��СֵС���򽻻�
			{
				minValue = arr[j];//���ҵ�����Сֵ��ֵ��minValue,��ʱ����Сֵ�����仯
				minValueIndex = j;//���ҵ���Сֵ���±���minValueIndex,��ʱ����Сֵ�±귢���任
			}
		}
		if (minValueIndex != i)//��������±�û�з����ı��򽻻�������ִ��
		{
			arr[minValueIndex] = arr[i];//�����ֵ��������ʼ�Ƚϵ��Ǹ�ֽ���� �ҵ�����Сֵ��λ��
			arr[i] = minValue;//����Сֵ����ʱ������ʼ�Ƚϵ��±�
		}
	}

}
//----------------------------------------��������------------------------------------------------
/*
//��һ��
int i;
int insertIndex = 1 - 1;//Ҫ������±�λ��
int insertValue = arr[1];//Ҫ�����ֵ
//��ֹԽ��
while (insertIndex >= 0 && arr[insertIndex] > insertValue)
{
	arr[insertIndex + 1] = arr[insertIndex];
	insertIndex--;//��һ��������insertIndex��ֵ�ǣ�-1��-1������while������������ǰѭ����ת��2
}

arr[insertIndex + 1] = insertValue;//2����ʱ�൱��arr[0]=�����ֵ
//�ڶ���
insertIndex = 2 - 1;//Ҫ������±�λ��
 insertValue = arr[2];//Ҫ�����ֵ
//��ֹԽ��
while (insertIndex >= 0 && arr[insertIndex] > insertValue)//1>=0,arr[1]>a[2]??       2--  >0 &&arr[0]>arr[2]????�ǵĻ�
{
	arr[insertIndex + 1] = arr[insertIndex];//a[2]=a[1]  ��a[1]=a[0],
	insertIndex--;//2--,���������,0--  <0ѭ���˳�
}

arr[insertIndex + 1] = insertValue;//2����ʱ�൱��arr[0]=�����ֵ
*/
void inserSort(int arr[MAXSIZE])
{
	int i;
	int insertValue;//����һ��Ҫ�����ֵ
	int insertIndex;//����һ��Ҫ����ֵ��λ��
	for ( i = 1; i < MAXSIZE; i++)
	{
		insertValue= arr[i];
		insertIndex = i - 1;
		while (insertIndex >= 0 && arr[insertIndex] > insertValue)//��ֹ����Խ��
		{
			arr[insertIndex + 1] = arr[insertIndex];
			insertIndex--;
		}
		arr[insertIndex + 1] = insertValue;
	}
}
//���뷨��ϣ������Ч�ʽϵͣ�
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
//ϣ������ĸ�Ч�㷨

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