/*#include <stdio.h>
int main()
{
	char a;
	int n,b,i,j,s;
	while (scanf("%c%d",&a,&n)!=EOF)
	{
		s=1;
		if(a=='@')
			break;
		for(i=0;i<n-1;i++)
		{
			for(j=1;j<=(2*n-1)/2-i;j++)
				putchar(' ');
			printf("%c\n",a);
			if(i>=1)
			{
				for(j=0;j<s;j++)
					putchar(' ');
				printf("%c\n",a);
				s+=2;
			}
		}
		for(i=1;i<=2*n-1;i++)
			printf("%c\n",a);
		getchar();
	}
	return 0;
}
*/
#include<stdio.h>
int main()
{
	char a;
	int i,j,n,f=0; 
	while (scanf("%c",&a)!=EOF)
	{
		if(a=='@')
			break;
		scanf("%d",&n);
		getchar();
		if(f)
			putchar('\n');
		f=1;
		for(i=1;i<n;i++)
		{
			for(j=1;j<=i-1+n;j++) 
			if(j==n-i+1||j==n+i-1) 
				printf("%c",a); 
			else
				printf(" "); 
			printf("\n");
		}
		if(n!=1)
		{
			for(i=1;i<=2*n-1;i++) 
			printf("%c",a);
			putchar('\n');
		}
	}
	return 0;
}