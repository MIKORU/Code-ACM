#include<stdio.h>
int main()
{
   int h,m,H,M;
	while(scanf("%d:%d%d:%d",&h,&m,&H,&M)!=EOF)
	{
		if(h<H)
			h=24-H+h;
		else
			h-=H;
		if(m<M)
			m=60-M+m;
		else
			m-=M;
		if(m+M>60)
		{
			if(h==0)
				h=24-1;
			else
				h=h-1;
		}
		if(h/10==0)
		{
			if(m/10==0)
				printf("0%d:0%d\n",h,m);
			else
				printf("0%d:%d\n",h,m);
		}
		else
		{
			if(m/10==0)
				printf("%d:0%d\n",h,m);
			else
				printf("%d:%d\n",h,m);
		}
	}
	return 0;
}
