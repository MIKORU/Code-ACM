#include <stdio.h>
int main()
{
	int n,a,b,c,m,q,i;
	while (scanf("%d",&n)!=EOF)
	{
		a=b=c=0;
		q=n;
		if (n==0)
			break;
		for(i=1;n>0;i++)
		{
			m=n%10;
			n=n/10;
			a+=m;
		}
		n=q;
		for(i=1;n>0;i++)
		{
			m=n%16;
			n=n/16;
			b+=m;
		}
		n=q;
		for(i=1;n>0;i++)
		{
			m=n%12;
			n=n/12;
			c+=m;
		}
		if(a==b&&b==c)
			printf("%d is a Sky Number.\n",q);
		else
			printf("%d is not a Sky Number.\n",q);
	}
	return 0;
}

