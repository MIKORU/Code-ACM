//�����⣺�ٴι淶�������ͼ��
#include<stdio.h>
int main()
{int N,i,j,b;
	while(printf("������һ��������")&&scanf("%d",&N)!=EOF)
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