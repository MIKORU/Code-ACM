/*#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int i,a[3];
	for(i=0;i<3;i++)
		scanf("%d",&a[i]);
		sort(a,a+3);
	for(i=0;i<3;i++)
	{
		if(i!=0)
			printf(" ");
		printf("%d",a[i]);
	}
	putchar('\n');
return 0;
}*/
#include<stdio.h>
int main()
{
	int a,b,n,s,A,B;
	while(scanf("%d%d%d",&a,&b,&n)!=EOF)
	{
		if(a==0&&b==0)
			break;
		A=a;
		B=b;
		s=0;
		while (n--)
		{ 
			if(a%10==b%10)
				s=1;
			else
			{
				s=0;
				break;
			}
			a/=10;
			b/=10;
		}
		if(s==1)
			printf("-1\n");
		else
			printf("%d\n",A+B);
	}
return 0;
}


