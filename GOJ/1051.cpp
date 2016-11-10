#include <stdio.h>
int main()
{
	char a[1000];
	int i,t,n;
	scanf("%d",&t);
		while (t--)
	{
		scanf("%s",&a);
		scanf("%d",&n);
		for (i=0;;i++)
		{
			if(a[i] == '.')
			{
				printf("%c\n",a[i+n]);
			break;
			}
		}
	}
	return 0;
}
