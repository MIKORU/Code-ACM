#include<stdio.h>
int main()
{
    int a,b,n,i,f[1009];
    while(scanf("%d%d%d",&a,&b,&n)!=EOF)
    {
		if(a==0&&b==0&&n==0)
			break;
		f[1]=1;
		f[2]=1;
		for(i=3;i<=1008;i++)
		{
			f[i]=(a*f[i-1]+b*f[i-2])%7;
		}
		printf("%d\n",f[(n-1)%1008+1]);
	}
	return 0;
}

