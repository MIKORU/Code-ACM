/*#include <stdio.h>
int main()
{
	int n,s,i,j,k;
	while (scanf("%d",&n)!=EOF)
	{
		s=0;
		for(i=0;i<=n-3;i++)
		{
			for(j=0;j<=n-3;j++)
			{
				for(k=0;k<=n-3;k++)
				{
					if(i+j+k==n-3)
					{
						s++;
					}
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}*/
#include <stdio.h>
int main()
{
	int x1,x2,x3,y1,y2,y3,n,s,i;
	scanf("%d",&n);
	while (n--)
	{
		s=1;
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		for(i=1;;i++)
		{
          if(i%x1==y1&&i%x2==y2&&i%x3==y3)
		  {
			  s=0;
			  break;
		  }
        }
		if(s==0)
			printf("%d\n",i);
	}
    return 0;
}


