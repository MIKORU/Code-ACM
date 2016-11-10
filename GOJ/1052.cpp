#include <stdio.h>
int main()
{
	int N,r,y,i;
	char a[20];
	while (scanf("%d",&N)!=EOF)
	{
		if(N==0)
			break;
		r=y=0;
		scanf("%s",&a);
		for(i=0;i<N;i++)
		{
			if(a[i]=='R')
				r++;
			else if(a[i]=='Y')
				y++;
		}
		if(a[N-1]=='B')
		{
			if(r==7)
				printf("Red\n");
			else
				printf("Yellow\n");
		}
		if(a[N-1]=='L')
		{
			if(y==7)
				printf("Yellow\n");
			else
				printf("Red\n");
		}
	}
	return 0;
}

