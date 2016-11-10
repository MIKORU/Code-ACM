#include <stdio.h>
#include <string.h>
int n;
char a[100];
void cv(int x)
{
	int c = 0;
	while (x)
	{
		if(x%n<10)
			a[c++] = x%n+'0';
		else
			a[c++] = x%n-10+'A';
		x/=n;
		

	}
	a[c]='\0';
}
int main()
{
	int x,i,p,m,t,j,s;
	while (scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=300;i++)
		{  
			x=i*i;
			cv(x);
			m = strlen(a);
			for(t=0,j=m-1;;t++,j--)
			{
				if(a[t]!=a[j])
					break;
				if (t>=j)
				{	
					cv(i);
					p=strlen(a);
					for(s=p-1;s>=0;s--)
					printf("%c",a[s]);
					cv(x);
					printf(" %s\n",a);
					break;
					
				}
			}
		
		}
	
	}
return 0;
}

