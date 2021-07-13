#include<stdio.h>
#include<malloc.h>

//递归求阶乘：欲求n！，只需求n*(n-1)!
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
//循环求阶乘
long for_factorial( int val)
{
	int result = 1;
	int i;
	for (i = 1; i <=val; ++i)
		result *= i;
	return result;
}
//用递归求1+2+3+4+····100的和
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

//汉诺塔问题
/*
	
		如果是一个盘子：
			直接将A柱子上的盘子从A移动到C
		否则：
			先把柱子A上的n-1个盘子从A借助C移动到B
			将柱子上的第n个盘子直接移到C
			再将B柱子上的n-1个盘子借助A移动到C

	
	
*/


void HanuoTower(int n, char A, char B, char C)
{

	if (1 == n)
	{
		printf("将编号为%d的盘子直接从%c柱子移动到%c\n",n,A,C);
	}
	else
	{
		//在某一次是：再将B柱子上的n-1个盘子借助A移动到C，此时形参中的charA ，应该是B
		HanuoTower(n-1,A,C,B);//把n-1个盘子从A借助C移动到B
		printf("将编号为%d的盘子直接从%c柱子移动到%c\n", n, A, C);
		HanuoTower(n-1,B,A,C);//B柱子上的n-1个盘子借助A移动到C
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