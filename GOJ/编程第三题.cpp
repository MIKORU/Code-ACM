//第三题：再次规范输出星型图案
#include<stdio.h>
int main()
{int N,i,j,b;
	while(printf("请输入一个整数：")&&scanf("%d",&N)!=EOF)
	{
		if(N==0)
			break;
		for(i=1;i<=N;i++)
		{
			{
				for(j=1;j<=2*(N-i);j++)
					putchar('  ');
				for(b=1;b<=i;b++)
					printf("* ");
				putchar('\n');
			}			
		}
		putchar('\n');
		putchar('\n');
	}
return 0;
}