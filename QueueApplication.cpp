#include<stdio.h>
#include<malloc.h>

//�ݹ���׳ˣ�����n����ֻ����n*(n-1)!
/*
	f(3)=3*f(2)
			2*f(1)
				f(1)=1

*/
long  factorial(long n)
{
	if (n <= 1)
		return 1;
	else	
		return factorial(n - 1)*n;
}
//ѭ����׳�
long for_factorial( int val)
{
	int result = 1;
	int i;
	for (i = 1; i <=val; ++i)
		result *= i;
	return result;
}
//�õݹ���1+2+3+4+��������100�ĺ�
/*
	f(5)=5+f(4)
		   4+f(3)
			 3+f(2)
				2+f(1)
				   f(1)=1
*/
int sum_num(int n)
{
	if (1 == n)
		return 1;
	else
		return sum_num(n - 1) + n;
}

//��ŵ������
/*
	
		�����һ�����ӣ�
			ֱ�ӽ�A�����ϵ����Ӵ�A�ƶ���C
		����
			�Ȱ�����A�ϵ�n-1�����Ӵ�A����C�ƶ���B
			�������ϵĵ�n������ֱ���Ƶ�C
			�ٽ�B�����ϵ�n-1�����ӽ���A�ƶ���C

	
	
*/


void HanuoTower(int n, char A, char B, char C)
{

	if (1 == n)
	{
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c\n",n,A,C);
	}
	else
	{
		//��ĳһ���ǣ��ٽ�B�����ϵ�n-1�����ӽ���A�ƶ���C����ʱ�β��е�charA ��Ӧ����B
		HanuoTower(n-1,A,C,B);//��n-1�����Ӵ�A����C�ƶ���B
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c\n", n, A, C);
		HanuoTower(n-1,B,A,C);//B�����ϵ�n-1�����ӽ���A�ƶ���C
	}
}



int main()
{
	long num = factorial(3);
	printf("num=%d\n",num);
	int number = sum_num(100);
	printf("%d\n",number);

	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';


	int val;
	printf("please enter the val=");
	scanf_s("%d",&val);
	HanuoTower(val,'A','B','C');
	printf("\n");

	return 0;
}