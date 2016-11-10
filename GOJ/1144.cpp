#include <stdio.h>
int gcd(int a,int b)
{
	int r;
	while((r=a%b)!=0)
	{
		a=b;
		b=r;
	}
	return b;
}
int lcm(int a,int b)
{
	int d;
	d = gcd(a,b);
	return a*b/d;
}
int main()
{
	int n,a,b;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",lcm(a,b)+gcd(a,b));
	}
	return 0;
}
