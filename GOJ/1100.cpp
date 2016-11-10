#include<stdio.h>
#include<string.h> 
int main()
{
  int n, x, i, j, c[105],a;
  while(scanf("%d", &n) !=EOF) 
  {
    memset(c, 0, sizeof(c));
    for(i = 0; i < n; i++)
	{
      scanf("%d", &x);
      c[x]++;
    }
	a = 1;
    for( i = 1; i <= 100; i++)
      for( j = 0; j < c[i]; j++) 
	  {
        if(a!=1) 
			printf(" ");	
        a = 0;
        printf("%d", i);
      }
    printf("\n");
  }
  return 0;
}