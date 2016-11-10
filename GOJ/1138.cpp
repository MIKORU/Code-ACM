#include <stdio.h>
int main()
{
	long long s,sum;
	while (scanf("%lld",&s)!=EOF)
	{
		sum=s*(1+s)/2;
		printf("%lld\n",sum);
	}
	return 0;
}