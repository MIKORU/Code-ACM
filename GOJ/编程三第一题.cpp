#include <stdio.h>
int main()
{
	int n, i, j, u=0; 
	char a[100],t;
	while(scanf("%d",&n)!=EOF)
	{
		if (n==0)
			break;
		u+=1;
		for (i=0; i<2*n; i++)
			scanf("%c",&a[i]);
		printf("Case %d:\n",u);
		for (i=0; i < 2*(n-1); i++)
			for (j = i+1;j < 2*n;j++)
			{
				if (a[i] > a[j])
				{
					t = a[i];
					a[i] = a[j];
					a[j] = t;
									
				}
			}
			for (i = n; i < 2*n; i++)
			printf("%c ",a[i]);
			putchar('\n');
			putchar('\n');
	}			

return 0;
}