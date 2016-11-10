#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000]; 
	int b[1000], s, i, j,c[1000], n, f1, f2, sum, t, m;
	while (scanf("%s",&a)!=EOF)
	{
		m = strlen(a);
		for(i = 0; i < m; i++)
		{
			b[i] =a[i] - '0';
		}
		for(i = 0, n = 0,s = 0; i < m; i++)
		{   
			if(b[i] != 5 && s == 0)
			{ 
				f1 = i; 
				s = 1;  
			}
			if(b[i] == 5 && s == 1)
			{ 
				f2 = i-1;
				s = 0; 
				for(j = f1, sum = 0; j <= f2; j++)
				{
					sum+= b[j];
					if(j != f2)
						sum *= 10;
				}
				c[n] = sum;
				++n;
			}
		}
		if(b[m-1] != 5)
		{
			for(j = f1, sum = 0; j <= m-1; j++)
			{
				sum+= b[j];
				if(j != m-1)
					sum *= 10;
			}
			c[n] = sum;
			++n;
		}
		for(i = 1; i < n; i++)
		{
			t = c[i];
			for(j = i-1; j >= 0 && t < c[j]; j--)
			{
				c[j+1] = c[j];
			}
			c[j+1] = t;
		}
		for(i = 0; i < n; i++)
		{
			if(i != 0)
				printf(" ");
			printf("%d", c[i]);
		}
		putchar('\n');
	}
 return 0;
}
