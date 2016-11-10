#include <stdio.h>
#include <string.h>
int main()
{
	int N,a,b,i,j,m;
	char c[25];
	scanf("%d",&N);
	while (N--)
	{
		scanf("%d%d%s",&a,&b,&c);
		m=strlen(c);
		printf("%d ",a);
		for(i=0;i<m;i++)
		{
			for(j=0;j<b;j++)
				printf("%c",c[i]);
		}
		putchar('\n');
	}
return 0;
}
