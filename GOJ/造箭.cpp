#include <stdio.h>
int main()
{
	int N,T,m[32],n[11],i,r,j,k,a;
 	scanf("%d",&T);
	while(T--)
    {
		scanf("%d",&N);
        for(i = 0;i < N;i++)
			scanf("%d%d",&m[i],&n[i]);
		for(i = 0;i <N-1; i++)
		 for(j = 0;j < N-i-1;j++)
            {
                if(m[j]>m[j+1])
			{
				r = m[j+1];
				m[j+1] = m[j];
				m[j] = r;
				a = n[j+1];
				n[j+1] = n[j];
				n[j] = a;

			}
			}
		for (i=0;i<N;i++)
		{
			for (j=0;j<n[i];j++)
			{
				printf(">+");
				for(k = 0; k < m[i]-2; k++)
				printf("-");
			printf("+>\n");
			}
		  printf("\n");
		}     

     }
    return 0;
}
			



		