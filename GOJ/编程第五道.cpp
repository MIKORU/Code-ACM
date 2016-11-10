//第五道：本题的任务是判断两个正整数之间完数的个数。
#include <stdio.h>
int main()
{int i,
	 j, 
	 n,	
	 a, 
	 sum, 
	 b=0,
	 t;

	while (scanf("%d", &n) !=EOF)
	{
		b=0;
		while (n--)
		{	
			b=0;
			scanf("%d%d", &i, &j);
			if (1 < i && j < 10000 )
			{
				if (i>j)
				{
					t=i;
					i=j;
					j=t;
				}
				for (i; i<=j; i++)
				{
					sum = 0;
					for (a = 1;a < i;a++)
					{
						if (i % a == 0)
						sum += a;			
					}
					if (sum == i)
					b++;
				}
			printf("%d\n", b);
			}
		}
	}
	return 0;
}
