#include<stdio.h>
int divisor(int a,int b)
{int r;
while ((r=a%b)!=0)
{
	a=b;
	b=r;
}
	return b;
}
int main()
{int T,a,b,c,d,e,f,g;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
       e=a*d+c*b;
	   f=b*d;
   g=divisor(e,f);
   printf("%d %d\n",e/g,f/g);
	}
	return 0;
}