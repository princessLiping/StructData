#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10


void InputArr(int arr[MaxSize]);//������ɳ���ΪMaxSize������
void OutPut(int arr[MaxSize]);//���������
void QuickSort(int arr[MaxSize], int left, int right);//������������
int  FindPos(int arr[MaxSize], int left, int right);//ȷ����׼���бȽ�

int main()
{
	int arr[MaxSize];//����һ������
	
	InputArr(arr);
	printf("����ǰ������");
	OutPut(arr);
	printf("\n");
	printf("����������");
	QuickSort(arr, 0, MaxSize-1);
	OutPut(arr);
	
	return 0;
	
}
//������ɳ���ΪMaxSize������
void InputArr(int arr[MaxSize])
{
	int i;
	for (i = 0; i < MaxSize; i++)
	{
		arr[i] = rand();
	}
}
//���
void OutPut(int arr[MaxSize])
{
	int i;
	for (i = 0; i < MaxSize; i++)
	{
		printf("%d\t",arr[i]);
	}
}
//������õݹ�
void QuickSort(int arr[MaxSize],int left,int right)
{
	int pos;
	if (left < right)
	{
		pos = FindPos(arr, left, right);
		QuickSort(arr,left,pos-1);//������
		QuickSort(arr, pos + 1, right);//������
	}

}
//ȷ����׼���Ƚ�
int  FindPos(int arr[MaxSize], int low, int high)
{
	int val = arr[low];
	while(low < high)//������ʱ�±�
	{
		while (low < high && arr[high] >= val)//���ұߵ�ֵ���ڻ�׼��ʱ��
		{
			--high;//��׼��ǰ��һ
		}
		//����Ļ������ұߵ�ֵС�ڻ�׼��ֵ��С�ھ͸�ֵ�����
		arr[low] = arr[high];
		while (low < high && arr[low] <= val)//����׼�����ұߵ�
		{
			++low;//��׼ֵ��ǰ��
		}
		//����Ļ������ǵ���׼С��ĳ��ֵ��ʱ��ĳ��ֵ�Ȼ�׼���ʱ�򣩣��Ѹ�ֵ��ֵ���ұ�
		arr[high] = arr[low];
	}
	//��ֹwhileѭ��֮��low��high��ֵһ������ȵ�
	arr[low] = val;//�ѵ�һ��ֵ�Ž�low��high����Ǹ�λ��
	return low;//�˴���������Ҷ���һ����
}