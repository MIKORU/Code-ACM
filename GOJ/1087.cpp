#include <stdio.h>
int main()
{
	int a,b,c,d,e,f,sum;
	while (scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)!=EOF)
	{
		sum=0;
		sum=60*60*(11-a)+60*(59-b)+(60-c)+60*60*d+60*e+f;
		printf("%d\n",sum);
	}
	return 0;
}
