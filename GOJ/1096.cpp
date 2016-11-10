#include <stdio.h>
#include <string.h>
#define N 200005
int main()
{
	char b[N];
	int i,p,a,c,m;
	long long sum;
	while (scanf("%s",&b)!=EOF)
	{
		sum=0;
		a=c=m=0;
		p = strlen(b);
		for(i=0;i<p;i++)
		{
			if(b[i]=='m')
				m++;
		}
		for(i=0;i<p;i++)
		{
			if(b[i]=='a')
				a++;
			else if(b[i]=='m')
				m--;
			else if(b[i]=='c')
				sum+=a*m;
		}
		printf("%lld\n",sum);
	}
return 0;
}
