#include<stdio.h>
int run(int y)
{
	if(y%400==0||y%4==0&&y%100!=0)
		return 1;
	return 0;
}
int main()
{
	int n,i,y,m,d,sum;
	scanf("%d",&n);
	while(n--)
	{
		sum=0;
		scanf("%d-%d-%d",&y,&m,&d);
		if(m<2||m==2&&d<29)
		{
			for(i=y;i<y+18;i++)
				if(run(i))
					sum+=366;
				else
					sum+=365;
			printf("%d\n",sum);
		}
		else if(m==2&&d==29)
		{
			if(run(y+18)==0)
			{
				printf("-1\n");
				continue;
			}
			for(i=y;i<y+18;i++)
				if(run(i))
					sum+=366;
				else
					sum+=365;
			printf("%d\n",sum);
		}
		else
		{
			for(i=y+1;i<y+19;i++)
				if(run(i))
					sum+=366;
				else
					sum+=365;
			printf("%d\n",sum);
		}
	}
 return 0;
}