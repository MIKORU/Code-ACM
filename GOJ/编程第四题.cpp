//第四题：阶梯式打印九九乘法表
#include<stdio.h>
int main()
{int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{	printf("%dx%d=%d\t",i,j,i*j);
		if(j==i)
			printf("\n");
		}
	}
return 0;
}