#include<stdio.h>
#include<string.h>
#define N 10005
int main()
{
	int sum,t,i,n,m;
	char a[N];
	scanf("%d",&n);
	while(n--)
	{
		t = 1;
		scanf("%s",&a);
		m = strlen(a);
		for(i=0;i<m;i++)
		{
			if(a[i]==a[i+1])
				t++;
			else
			{
				if(t==1)
					printf("%c",a[i]);
				else
					printf("%d%c",t,a[i]);
				t = 1;
			}
		}
		putchar('\n');
	}
	return 0;
}