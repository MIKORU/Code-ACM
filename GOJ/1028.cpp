#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j,m;
	char a[100];
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",&a);
		m = strlen(a);
		for (i=0,j=m-1;i<=j;i++,j--)
		{
			if (a[i]!=a[j])
			{
				printf("no\n");
				break;
			}
		}
		if (i>j)
			printf("yes\n");
	}
	return 0;
}
