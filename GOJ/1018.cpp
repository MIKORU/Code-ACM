#include <stdio.h>
int main()
{
	int n,i,j,a,b,p,s;
	while (scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		p=b=1;
		s=0;
		for (i=0;i<n;i++)
		{
			b=b+s;
			printf("%d",b);
			a=b;
			for(j=0;j<n-i-1;j++)
			{
				p++;
				a=a+p;
				printf(" %d",a);	
			}
			p=i+2;
			s++;
			putchar('\n');
		}
	}
	return 0;
}

